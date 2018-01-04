//
// Created by Axel LE BOT on 20/12/17.
//

/*
 nom : ServeurUDPEcoute
 description : écoute en continu les messages UDP sur un port donné (ex 5000) en IPV4
 affiche le message recu ainsi que l'identité de l'émetteur
 auteur : Axel LE BOT
 */

// Liste des includes necessaires
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>

#define SERVER_PORT 4444
#define MAXBUFFERSIZE 1024

// prend un tableau de caracteres en entree et sa taille
// inverse les caracteres (le premier devient le dernier, etc ...
void inverser_buffer(char *bufferainverser, int taille) {
    // precision : utiliser la taille du message, pas celle du buffer
    int i;
    char temp;
    for (i=0; i < taille/2 ; i++) {
        temp = bufferainverser[i];
        bufferainverser[i]= bufferainverser[taille-1-i];
        bufferainverser[taille-i-1] = temp;
    }
}

int main (int argc, char **argv) {

   int sp;  /* descripteur de la socket principale */
   int st;  /* descripteur de la socket de travail */
   int nbRecus; /* entier utilisé lors de la lecture d'un message */

   struct sockaddr_in servAddr; /* structure pour renseigner l'adresse du serveur et l'associer à la socket */
   struct sockaddr_in cliAddr; /* structure pour stocker l'identité du client qui a envoyé un message recu*/   
   socklen_t cliSize; /* type utilisé pour récupérer la taille de l'adresse du client qui a envoyé un message recu */
   char buffer[MAXBUFFERSIZE]; /* buffer pour lire puis afficher les messages recus*/   

   /**********************************************/
   /* Création du support de communication       */
   /**********************************************/

   /* Création d'une socket. Reseau internet (PF_INET) , Transport : TCP (SOCK_STREAM) */
   if ((sp = socket(PF_INET, SOCK_STREAM, 0 )) == -1) {
      perror("création de la socket");
      exit(1);
   }

   /* Nous renseignons la structure servAddr avec les éléments du serveur : type de socket, adresse ip, port */
   servAddr.sin_family = AF_INET;   /* Adresse internet de type IPv4 */   
   servAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Permet d'associer toutes les ips de la machine serveur */
   servAddr.sin_port = htons(SERVER_PORT); /* sur quel port écouter */
    

   /* Nous associons la socket locale à l'identité du serveur (contenue dans la structure servAddr) */
   if (bind(sp, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1) {
      perror("association socket / adresse");
      fprintf(stderr, "Ceci arrive généralement si :\n");
      fprintf(stderr, "- le port est déjà utilisé par une autre application\n");
      fprintf(stderr, "- vous n'avez pas l'autorisation d'utiliser ce port (réservé systeme)\n");
      fprintf(stderr, "- la derniere instance du programme a mal fermé la socket\n");
      exit(1);
   } 
  

   /********************************************************/
   /* etablisement et gestion du dialogue client / serveur */
   /********************************************************/

/* on met la socket principale  en position d'écoute (necessaire uniquement pour TCP)*/
listen(sp, 1);	
/*boucle infinie : nous écoutons les connexions entrantes sur la socket principale */
while (1) {
    /* mode écoute : on attend l'arrivee d'une connexion entrante */
    if ((st = accept(sp, (struct sockaddr *) &cliAddr, &cliSize))==-1) {
        perror("problem accept");
        exit(1); 
    }       
    /* une connexion entrante s'est produite.
    /* cliAddr a été rempli avec les informations d'identification du client*/
    /* on lit alors sur cette socket un message  */
    if ((nbRecus = recv(st, buffer, MAXBUFFERSIZE, 0)) == -1) {
        perror("problem recv");
        exit(1);
    }
    /* nbRecus contient le nombre d'octets qui ont été lus  (au max : MAXBUFFERSIZE)*/ 
    /* buffer contient le message recu */
    // on inverse le buffer :
    inverser_buffer(buffer, strlen(buffer));
    // ajout du caractère de fin de buffer :
    buffer[nbRecus]='\0';
    //On renvoie le buffer inversé au client :
    if (sendto(st, buffer, strlen(buffer), 0, (struct sockaddr*) &cliAddr, cliSize) ==-1) {
        perror("erreur sendto()");
        exit(1);
    }
    /* on ferme enfin la socket de travail */
    close(st);
}
}
