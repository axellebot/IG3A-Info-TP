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

#define SERVER_TCP_PORT 4444
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

int main(int argc, char **argv) {
    // Etape 0 : definition des variables
    int socketMain;  // socket en mode non connecte UDP principale
    int socketWorker;  // socket en mode non connecte UDP travail

    struct sockaddr_in serverAddress; // pour le stockage de sa propre identite (serveur)
    struct sockaddr_in clientAddress; // pour le stockage de l'identité du client
    socklen_t addressSize = sizeof(struct sockaddr_in); // Besoin de connaire la taille de la structure de type sockaddr_in
    int binded; // valeur retour pour bind()
    ssize_t recvBufferSize; // valeur retour pour recvFrom()
    ssize_t sentBufferSize; // valeur retour pour send()

    char buffer[MAX_BUFFER_SIZE]; // buffer pour lecture du message

    // Etape 1 : creation de la socket de communication
    socketMain = socket(PF_INET, SOCK_STREAM, 0);
    if (socketMain == -1) {
        perror("error création socket\n");
        exit(EXIT_FAILURE);
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant sa propre identite
    serverAddress.sin_family = AF_INET;   // famille d’adresse IPv4
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // n'importe quelle IP
    serverAddress.sin_port = htons(SERVER_TCP_PORT); // Port a associer

    // Etape 3 : association de l'adresse avec la socket
    binded = bind(socketMain, (struct sockaddr *) &serverAddress, addressSize);
    if (binded == -1) {
        perror("error bind()");
        exit(EXIT_FAILURE);
    }

    // Etape 4 : mise en route d'une boucle continue.
    // Ecoute sur la socket.
    listen(socketMain, 1);
    // boucle infinie : nous écoutons les connexions entrantes sur la socket principale
    while (1) {
        // mode écoute : on attend l'arrivee d'une connexion entrante
        printf("Waiting connection from a TCP client on : %s:%i\n",
               inet_ntoa(serverAddress.sin_addr),
               ntohs(serverAddress.sin_port));
        socketWorker = accept(socketMain, (struct sockaddr *) &clientAddress, &addressSize);
        if (socketWorker == -1) {
            perror("error accept()");
            exit(EXIT_FAILURE);
        }
        printf("Connection from TCP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));

        // on recoit le buffer du client :
        printf("Waiting reception from TCP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));
        recvBufferSize = recv(socketWorker, buffer, MAX_BUFFER_SIZE, 0);
        if (recvBufferSize == -1) {
            perror("error recv()");
            exit(EXIT_FAILURE);
        }
        printf("Connected to TCP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));

        // on inverse le buffer :
        inverser_buffer(buffer, recvBufferSize);
        // ajout du caractère de fin de buffer :
        buffer[recvBufferSize] = '\0';

        // on renvoie le buffer inversé au client :
        printf("Sending to TCP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));
        sentBufferSize = sendto(socketWorker, buffer, recvBufferSize, 0, (struct sockaddr *) &clientAddress,
                                addressSize);
        if (sentBufferSize == -1) {
            perror("error sendto()");
            exit(EXIT_FAILURE);
        }

        // affichage du buffer
        printf("message received from %s:%i : %s \n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port),
               buffer);

        // on ferme la socket de travail
        printf("Disonnecting TCP client at : %s:%i\n",
               inet_ntoa(clientAddress.sin_addr),
               ntohs(clientAddress.sin_port));
        close(socketWorker);
    }
}
