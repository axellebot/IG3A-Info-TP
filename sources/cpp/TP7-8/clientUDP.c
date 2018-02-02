//
// Created by Axel LE BOT on 20/12/17.
//

/*
 nom : ClientUDP
 description :	envoi un message UDP sur un port donne en IPV4
 auteur : Axel LE BOT
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <memory.h>

#define MAX_BUFFER_SIZE 1024

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
    if (argc < 4) {
        perror("error argument");
        printf("usage : %s server_ip server_port msg\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ipAdress = argv[1];
    const char *serverPort = argv[2];
    const char *message = argv[3];

    // Etape 0 : definition des variables
    int socketUDP;   // socket en mode non connecte UDP
    struct sockaddr_in serverAddr, rcptAdrr; // carte de visite contenant l'identite du serveur
    socklen_t addressSize = sizeof(struct sockaddr_in); // Besoin de connaire la taille de la structure de type sockaddr_in
    ssize_t nbSend; // stockage du nombre d'octets recus
    ssize_t recvBufferSize;

    char buffer[strlen(message)]; // buffer pour envoyer le message (taille ajustee)
    strcpy(buffer, message);

    // Etape 1 : creation de la socket de communication
    socketUDP = socket(PF_INET, SOCK_DGRAM, 0);
    if (socketUDP == -1) {
        perror("error socket()");
        exit(EXIT_FAILURE);
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant l'identite du serveur
    serverAddr.sin_family = AF_INET; // famille d’adresse IPv4
    serverAddr.sin_addr.s_addr = inet_addr(ipAdress); // IP du serveur
    serverAddr.sin_port = htons(atoi(serverPort));// Port du serveur relie à l'application

    // Etape 3 : envoi du message au serveur
    printf("Sending to UDP server at : %s:%i\n",
           inet_ntoa(serverAddr.sin_addr),
           ntohs(serverAddr.sin_port));
    nbSend = sendto(socketUDP, buffer, strlen(buffer), 0, (struct sockaddr *) &serverAddr, addressSize);
    if (nbSend == -1) {
        perror("error sendto()");
        exit(EXIT_FAILURE);
    }

    //Etape 4 : attente du retour du serveur
    puts("Waiting reception from an UDP server");
    recvBufferSize = recvfrom(socketUDP, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *) &rcptAdrr, &addressSize);
    if (recvBufferSize == -1) {
        perror("error recvfrom()");
        exit(EXIT_FAILURE);
    }
    printf("Received from UDP server at : %s:%i\n",
           inet_ntoa(rcptAdrr.sin_addr),
           ntohs(rcptAdrr.sin_port));

    // ajout du caractère de fin de buffer :
    buffer[recvBufferSize] = '\0';

    printf("message received : %s \n", buffer);
    close(socketUDP);

    exit(EXIT_SUCCESS);
}
