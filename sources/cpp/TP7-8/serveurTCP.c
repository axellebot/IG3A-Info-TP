//
// Created by Axel LE BOT on 20/12/17.
//

/*
 nom : ServeurTCP
 description : écoute en continu les messages TCP sur un port donné (ex 5000) en IPV4
 affiche le message recu ainsi que l'identité de l'émetteur
 auteur : Axel LE BOT
 */

// Liste des includes necessaires
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_PORT 4444
#define MAXBUFFERSIZE 1024

// prend un tableau de caracteres en entree et sa taille
// inverse les caracteres (le premier devient le dernier, etc ...
void inverser_buffer(char *bufferainverser, int taille) {
    // precision : utiliser la taille du message, pas celle du buffer
    int i;
    char temp;
    for (i = 0; i < taille / 2; i++) {
        temp = bufferainverser[i];
        bufferainverser[i] = bufferainverser[taille - 1 - i];
        bufferainverser[taille - i - 1] = temp;
    }
}

int main(int argc, char **argv) {

    int sp;  // descripteur de la socket principale
    int st;  // descripteur de la socket de travail
    struct sockaddr_in serverAddr; // pour le stockage de sa propre identite (serveur)
    struct sockaddr_in cliAddr; // pour le stockage de l'identité du client
    socklen_t cliSize; // pour le stockage de l'adresse du client

    ssize_t nbRecus; // stockage du nombre d’octets recus
    char buffer[MAXBUFFERSIZE]; // buffer pour lecture du message

    // Etape 1 : creation de la socket de communication
    sp = socket(PF_INET, SOCK_STREAM, 0);
    if (sp == -1) {
        perror("Erreur création socket\n");
        exit(1);
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant sa propre identite
    serverAddr.sin_family = AF_INET;   // famille d’adresse IPv4
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // n'importe quelle IP
    serverAddr.sin_port = htons(SERVER_PORT); // Port a associer

    // Etape 3 : association de l'adresse avec la socket
    if (bind(sp, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        perror("erreur 1 bind()");
        exit(1);
    }

    // Etape 4 : mise en route d'une boucle continue.
    // Ecoute sur la socket.
    listen(sp, 1);
    //boucle infinie : nous écoutons les connexions entrantes sur la socket principale
    while (1) {
        // mode écoute : on attend l'arrivee d'une connexion entrante
        if ((st = accept(sp, (struct sockaddr *) &cliAddr, &cliSize)) == -1) {
            perror("erreur 2 accept()");
            exit(1);
        }

        // réception d'un message
        // message stocké dans buffer
        // on lit alors sur cette socket un message
        nbRecus = recv(st, buffer, MAXBUFFERSIZE, 0);
        if (nbRecus == -1) {
            perror("erreur recv()");
            exit(1);
        }

        // on inverse le buffer :
        inverser_buffer(buffer, strlen(buffer));
        // ajout du caractère de fin de buffer :
        buffer[nbRecus] = '\0';

        //On renvoie le buffer inversé au client :
        if (sendto(st, buffer, strlen(buffer), 0, (struct sockaddr *) &cliAddr, cliSize) == -1) {
            perror("erreur sendto()");
            exit(1);
        }

        // on ferme enfin la socket de travail
        close(st);
    }
}
