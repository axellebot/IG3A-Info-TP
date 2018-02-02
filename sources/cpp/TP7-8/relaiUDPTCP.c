//
// Created by Axel LE BOT on 20/12/17.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define RELAY_PORT 5000
#define SERVER_TCP_PORT 4444
#define MAX_BUFFER_SIZE 1024

int main(int argc, const char *argv[]) {
    // Etape 0 : definition des variables
    int socketUDP;   // socket en mode non connecte UDP
    int socketTCP;   // socket en mode connecte TCP

    struct sockaddr_in
            relayAddress, // pour le stockage de sa propre identite (relai)
            serverAddress, // pour le stockage de l'identité du serveur
            clientAddress; // pour le stockage de l'identité du client

    socklen_t addressSize = sizeof(struct sockaddr_in); // Besoin de connaitre la taille de la structure de type sockaddr_in

    int binded; // valeur retour pour bind()
    int connected; // valeur retour pour connect()
    ssize_t recvBufferSize; // valeur retour pour recvFrom()
    ssize_t sentBufferSize; // valeur retour pour send()

    char buffer[MAX_BUFFER_SIZE];  // buffer pour lecture du message

    // Etape 1 : creation des sockets de communication
    socketUDP = socket(PF_INET, SOCK_DGRAM, 0); // UDP
    if (socketUDP == -1) {
        perror("error création socket");
        exit(EXIT_FAILURE);
    }

    socketTCP = socket(PF_INET, SOCK_STREAM, 0); // TCP
    if (socketTCP == -1) {
        perror("error création socket");
        exit(EXIT_FAILURE);
    }

    // Etape 2 : creation des structures sockaddr_in pour connaitre l'identité des appareils (IP-Port)
    relayAddress.sin_family = AF_INET; // famille d’adresse IPv4
    relayAddress.sin_addr.s_addr = htonl(INADDR_ANY); // n'importe quelle IP
    relayAddress.sin_port = htons(RELAY_PORT); // Port a associer

    serverAddress.sin_family = AF_INET; // famille d’adresse IPv4
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // IP du serveur
    serverAddress.sin_port = htons(SERVER_TCP_PORT);// Port du serveur relie à l'application

    // Etape 3 : association et connections des sockets
    binded = bind(socketUDP, (struct sockaddr *) &relayAddress, addressSize);
    if (binded == -1) {
        perror("error bind()");
        exit(EXIT_FAILURE);
    }
    // Connection au server TCP distant :
    printf("Connecting to TCP server at : %s:%i\n",
           inet_ntoa(serverAddress.sin_addr),
           ntohs(serverAddress.sin_port));
    connected = connect(socketTCP, (struct sockaddr *) &serverAddress, addressSize);
    if (connected == -1) {
        perror("error connect() TCP");
        exit(EXIT_FAILURE);
    }
    printf("Connected to TCP server at : %s:%i\n",
           inet_ntoa(serverAddress.sin_addr),
           ntohs(serverAddress.sin_port));

    // Etape 4 : mise en route d'une boucle infinie.
    while (1) {
        // on recoit le buffer du client UDP :
        printf("Waiting reception from an UDP client on : %s:%i\n",
               inet_ntoa(relayAddress.sin_addr),
               ntohs(relayAddress.sin_port));
        recvBufferSize = recvfrom(socketUDP, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *) &clientAddress,
                                  &addressSize);
        if (recvBufferSize == -1) {
            perror("error recvfrom() UDP");
            exit(EXIT_FAILURE);
        }
        printf("Received from UDP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));

        // On envoie le buffer au serveur TCP :
        printf("Sending to TCP server at : %s:%i\n",
               inet_ntoa(serverAddress.sin_addr),
               ntohs(serverAddress.sin_port));
        sentBufferSize = send(socketTCP, buffer, recvBufferSize, 0);
        if (sentBufferSize == -1) {
            perror("error send() TCP");
            exit(EXIT_FAILURE);
        }

        // On recoit le buffer du serveur TCP :
        printf("Receiving from TCP server at : %s:%i\n",
               inet_ntoa(serverAddress.sin_addr),
               ntohs(serverAddress.sin_port));
        recvBufferSize = recv(socketTCP, buffer, MAX_BUFFER_SIZE, 0);
        if (recvBufferSize == -1) {
            perror("error recv() TCP");
            exit(EXIT_FAILURE);
        }

        buffer[recvBufferSize] = '\0';

        // On renvoie le buffer au client UDP :
        printf("Sending to UDP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));
        sentBufferSize = sendto(socketUDP, buffer, recvBufferSize, 0, (struct sockaddr *) &clientAddress, addressSize);
        if (sentBufferSize == -1) {
            perror("error sendto() UDP");
            exit(EXIT_FAILURE);
        }
    }
}
