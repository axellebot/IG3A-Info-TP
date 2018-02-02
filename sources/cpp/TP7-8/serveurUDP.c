//
// Created by Axel LE BOT on 20/12/17.
//

/*
 nom : ServeurUDP
 description : écoute en continu les messages UDP sur un port donné (ex 5000) en IPV4
 affiche le message recu ainsi que l'identité de l'émetteur
 auteur : Axel LE BOT
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define SERVER_UDP_PORT 5000
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
    int socketUDP;   // socket en mode non connecte UDP

    struct sockaddr_in
            serverAddress, // pour le stockage de sa propre identite (serveur)
            clientAddress; // pour le stockage de l'identité du client
    socklen_t addressSize = sizeof(struct sockaddr_in); // Besoin de connaire la taille de la structure de type sockaddr_in
    int binded; // valeur retour pour bind()
    ssize_t recvBufferSize; // valeur retour pour recvFrom()
    ssize_t sentBufferSize; // valeur retour pour send()

    char buffer[MAX_BUFFER_SIZE];  // buffer pour lecture du message

    // Etape 1 : creation de la socket de communication
    socketUDP = socket(PF_INET, SOCK_DGRAM, 0);
    if (socketUDP == -1) {
        perror("error création socket");
        exit(EXIT_FAILURE);
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant sa propre identite
    // cette structure permettra de faire connaitre son identité
    // identité composée d'une association IP-port
    serverAddress.sin_family = AF_INET; // famille d’adresse IPv4
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // n'importe quelle IP
    serverAddress.sin_port = htons(SERVER_UDP_PORT); // Port a associer

    // Etape 3 : association de l'adresse avec la socket
    binded = bind(socketUDP, (struct sockaddr *) &serverAddress, addressSize);
    if (binded == -1) {
        perror("error bind()");
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

        // on recoit le buffer du client :
        printf("Waiting reception from a UDP client on : %s:%i\n",
               inet_ntoa(serverAddress.sin_addr),
               ntohs(serverAddress.sin_port));
        recvBufferSize = recvfrom(socketUDP, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *) &clientAddress,
                                  &addressSize);
        if (recvBufferSize == -1) {
            perror("error recvfrom()");
            exit(EXIT_FAILURE);
        }
        printf("Received from UDP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));

        // on renvoie le buffer au client :
        printf("Sending to UDP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));
        sentBufferSize = sendto(socketUDP, buffer, recvBufferSize, 0, (struct sockaddr *) &clientAddress, addressSize);
        if (sentBufferSize == -1) {
            perror("error sendto()");
            exit(EXIT_FAILURE);
        }

        // on inverse le buffer :
        inverser_buffer(buffer, recvBufferSize);
        // ajout du caractère de fin de buffer :
        buffer[recvBufferSize] = '\0';

        // affichage du buffer 
        printf("message received from %s:%i : %s \n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port),
               buffer);
    }
}
