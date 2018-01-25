//
// Created by Axel LE BOT on 20/12/17.
//

/*
 nom : ServeurUDP
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
#define MAX_BUFFER_SIZE 1024

// prend un tableau de caracteres en entree et sa taille
// inverse les caracteres (le premier devient le dernier, etc ...
void inverser_buffer(char *bufferAInverser, int taille) {
    // precision : utiliser la taille du message, pas celle du buffer
    int i;
    char temp;
    for (i = 0; i < taille / 2; i++) {
        temp = bufferAInverser[i];
        bufferAInverser[i] = bufferAInverser[taille - 1 - i];
        bufferAInverser[taille - i - 1] = temp;
    }
}

int main(int argc, const char *argv[]) {
    // Etape 0 : definition des variables
    int sock;   // socket en mode non connecte UDP

    struct sockaddr_in serverAddress; // pour le stockage de sa propre identite (serveur)
    struct sockaddr_in clientAddress; // pour le stockage de l'identité du client
    socklen_t clientAddressSize = sizeof(struct sockaddr_in); // Besoin de connaire la taille de la structure de type sockaddr_in
    int binded; // valeur retour pour bind()
    ssize_t recvBufferSize; // valeur retour pour recvFrom()
    ssize_t sentBufferSize; // valeur retour pour send()

    char buffer[MAX_BUFFER_SIZE];  // buffer pour lecture du message

    // Etape 1 : creation de la socket de communication
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("Erreur création socket");
        exit(EXIT_FAILURE);
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant sa propre identite
    // cette structure permettra de faire connaitre son identité
    // identité composée d'une association IP-port
    serverAddress.sin_family = AF_INET; // famille d’adresse IPv4
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // n'importe quelle IP
    serverAddress.sin_port = htons(SERVER_PORT); // Port a associer

    // Etape 3 : association de l'adresse avec la socket
    binded = bind(sock, (struct sockaddr *) &serverAddress, clientAddressSize);
    if (binded == -1) {
        perror("erreur 1 bind()");
        exit(EXIT_FAILURE);
    }

    // Etape 4 : mise en route d'une boucle continue.
    // Ecoute sur la socket.
    // Tout message extrait est affiché
    // l'affichage correct via printf : dernier caractère du buffer  ‘\0'
    // de ce fait, on ne recevra qu'au maximum 1023 caractères
    // boucle infinie
    while (1) {
        // réception (mode bloquant par défaut) d'un message
        // message stocké dans buffer (taille max: 1023 octetcs
        // identité de l'émetteur stockée dans cliAddr

        recvBufferSize = recvfrom(sock, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *) &clientAddress,
                                  &clientAddressSize);
        if (recvBufferSize == -1) {
            perror("erreur recvfrom()");
            exit(EXIT_FAILURE);
        }

        // on renvoie le buffer au client :
        sentBufferSize = sendto(sock, buffer, recvBufferSize, 0, (struct sockaddr *) &clientAddress, clientAddressSize);
        if (sentBufferSize == -1) {
            perror("erreur sendto()");
            exit(EXIT_FAILURE);
        }

        // on inverse le buffer :
        inverser_buffer(buffer, recvBufferSize);
        // ajout du caractère de fin de buffer :
        buffer[recvBufferSize] = '\0';

        // affichage du buffer 
        printf("message send from %s:%i : %s \n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port),
               buffer);
    }
}
