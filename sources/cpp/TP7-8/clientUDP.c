//
// Created by Axel LE BOT on 20/12/17.
//

/*
 nom : ClientUDP
 description :	envoi un message UDP sur un port donne en IPV4
 auteur : Axel LE BOT
 */

// Liste des includes necessaires
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
        perror("erreur argument");
        printf("usage : %s server_ip server_port msg\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ipAdress = argv[1];
    const char *serverPort = argv[2];
    const char *message = argv[3];

    // Etape 0 : definition des variables
    int sock;   // socket en mode non connecte UDP
    struct sockaddr_in serverAddr, rcptAdrr; // carte de visite contenant l'identite du serveur
    socklen_t clientAddressSize = sizeof(struct sockaddr_in); // Besoin de connaire la taille de la structure de type sockaddr_in
    ssize_t nbSend; // stockage du nombre d'octets recus
    ssize_t recvBufferSize;

    char buffer[strlen(message)]; // buffer pour envoyer le message (taille ajustee)
    strcpy(buffer, message);

    // Etape 1 : creation de la socket de communication
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("erreur socket()");
        exit(EXIT_FAILURE);
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant l'identite du serveur
    serverAddr.sin_family = AF_INET; // famille d’adresse IPv4
    serverAddr.sin_addr.s_addr = inet_addr(ipAdress); // IP du serveur
    serverAddr.sin_port = htons(atoi(serverPort));// Port du serveur relie à l'application

    // Etape 3 : envoi du message au serveur
    nbSend = sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *) &serverAddr, clientAddressSize);
    if (nbSend == -1) {
        perror("erreur sendto()");
        exit(EXIT_FAILURE);
    }
    printf("message sent : %s\n",buffer);

    //Etape 4 : attente du retour du serveur
    recvBufferSize = recvfrom(sock, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *) &rcptAdrr, &clientAddressSize);

    if (recvBufferSize == -1) {
        perror("erreur recvfrom()");
        exit(EXIT_FAILURE);
    }

    // ajout du caractère de fin de buffer :
    buffer[recvBufferSize] = '\0';

    printf("message received : %s \n", buffer);
    close(sock);

    exit(EXIT_SUCCESS);
}
