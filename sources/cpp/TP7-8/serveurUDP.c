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

#define SERVER_PORT 5000

// prend un tableau de caracteres en entree et sa taille
// inverse les caracteres (le premier devient le dernier, etc ...
void inverser_buffer(char *bufferAInverser, int taille){
    // precision : utiliser la taille du message, pas celle du buffer
    int i;
    char temp;
    for(i = 0; i < taille / 2; i++){
        temp = bufferAInverser[i];
        bufferAInverser[i] = bufferAInverser[taille - 1 - i];
        bufferAInverser[taille - i - 1] = temp;
    }
}

int main(int argc, const char *argv[]){
    // Etape 0 : definition des variables
    int sock;   // socket en mode non connecte UDP
    struct sockaddr_in monAdresse; // pour le stockage de sa propre identite (serveur)
    struct sockaddr_in adresseClientEntrant; // pour le stockage de l'identité du client
    socklen_t longueurStructAdresse;

    ssize_t nbRecus; // stockage du nombre d’octets recus
    int retour; // valeur temporaire pour retour
    ssize_t send;
    char buffer[1024];  // buffer pour lecture du message

    // Besoin de connaire la taille de la structure de type sockaddr_in
    longueurStructAdresse = sizeof(struct sockaddr_in);

    // Etape 1 : creation de la socket de communication
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1){
        perror("Erreur création socket\n");
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant sa propre identite
    // cette structure permettra de faire connaitre son identité
    // identité composée d'une association IP-port
    monAdresse.sin_family = AF_INET; // famille d’adresse IPv4
    monAdresse.sin_addr.s_addr = htonl(INADDR_ANY); // n'importe quelle IP
    monAdresse.sin_port = htons(SERVER_PORT); // Port a associer

    // Etape 3 : association de l'adresse avec la socket
    retour = bind(sock, (struct sockaddr *) &monAdresse, longueurStructAdresse);
    if(retour == -1){
        perror("erreur 1 bind()");
        exit(1);
    }

    // Etape 4 : mise en route d'une boucle continue.
    // Ecoute sur la socket.
    // Tout message extrait est affiché
    // l'affichage correct via printf : dernier caractère du buffer  ‘\0'
    // de ce fait, on ne recevra qu'au maximum 1023 caractères
    // boucle infinie
    while(1){
        // réception (mode bloquant par défaut) d'un message
        // message stocké dans buffer (taille max: 1023 octetcs
        // identité de l'émetteur stockée dans cliAddr
        nbRecus = recvfrom(sock, buffer, 1024, 0, (struct sockaddr *) &adresseClientEntrant, &longueurStructAdresse);
        if(nbRecus == -1){
            perror("erreur 2 bind()");
            exit(1);
        }

        //On renvoie le buffer au client :
        send = sendto(sock, buffer, 128, 0, (struct sockaddr *) &adresseClientEntrant, longueurStructAdresse);
        if(send == -1){
            perror("erreur sendto()");
            exit(1);
        }

        // on inverse le buffer :
        inverser_buffer(buffer, 128);
        // ajout du caractère de fin de buffer :
        buffer[nbRecus] = '\0';

        // affichage du buffer 
        printf("message recu depuis l'IP %s avec le port %i : %s\n",
               inet_ntoa(adresseClientEntrant.sin_addr),
               ntohs(adresseClientEntrant.sin_port), buffer);

    }
}
