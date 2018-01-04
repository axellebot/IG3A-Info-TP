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

#define MESSAGE_A_ENVOYER ".eruelp tnafne nu ,siofrap te ,erbmos etef enu'd engapmahc ed sellub sel emmoc tnellitnics seliote sel uo egenam nu tse ednom el"
#define TAILLE_MESSAGE 128 // important d'etre exact, sinon probleme a l'inversion du buffer

int main(int argc, const char *argv[]){
    /* le nombre d'arguments doit etre de 2 exactement */
    if(argc != 3){
        printf("usage : %s ip_server port\n", argv[0]);
        printf("l'ip du serveur UDP sous forme xxx.xxx.xxx.xxx\n");
        printf("le numéro du port à écouter, entre 1 et 65535\n");
        exit(1);
    }

    // Etape 0 : definition des variables
    int sock;   // socket en mode non connecte UDP
    struct sockaddr_in AdresseServeur, rcptAdrr; // carte de visite contenant l'identite du serveur
    socklen_t longueurStructAdresse; // contient la taille d'une carte de visite
    ssize_t nbSend; // stockage du nombre d'octets recus
    ssize_t recus;
    char *buffer = MESSAGE_A_ENVOYER;  // buffer pour envoyer le message (taille ajustee)
    char buffer2[1024];

    //initialisation de longueurStructAdresse
    longueurStructAdresse = sizeof(struct sockaddr_in);

    // Etape 1 : creation de la socket de communication
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1){
        perror("Erreur création socket\n");
    }

    // Etape 2 : creation d'une structure type sockaddr_in contenant l'identite du serveur
    // identite composee d'une association IP-port
    AdresseServeur.sin_family = AF_INET; // famille d’adresse IPv4
    inet_aton(argv[1], &AdresseServeur.sin_addr); // IP du serveur
    // Port du serveur relie à l'application :
    AdresseServeur.sin_port = htons(atoi(argv[2]));

    // Etape 3 : envoi du message
    // envoi vers serveur (identite contenue dans AdresseServeur
    nbSend = sendto(sock, buffer, TAILLE_MESSAGE, 0, (struct sockaddr *) &AdresseServeur, longueurStructAdresse);
    if(nbSend == -1){
        perror("erreur sendto()");
        exit(1);
    }
    printf("message envoye\n");

    //Etape 4 : attente du retour du serveur
    recus = recvfrom(sock, buffer2, 1024, 0, (struct sockaddr *) &rcptAdrr, &longueurStructAdresse);
    if(recus == -1){
        perror("erreur recvfrom()");
        exit(1);
    }
    printf("message reçu : %s \n", buffer2);
    close(sock);
}
