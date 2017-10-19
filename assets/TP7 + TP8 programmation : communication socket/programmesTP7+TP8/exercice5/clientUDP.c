/*
 nom : ClientUDP
 description :	envoi un message UDP sur un port donne en IPV4
 auteur : Barties
 */

// Liste des includes necessaires
#include <stdio.h>
#include <unistd.h>
// <a completer >

#define PORT_DU_SERVEUR 9999999 // <a modifier >
#define IP_DU_SERVEUR "7.7.7.7" // <a modifier >
#define MESSAGE_A_ENVOYER ".eruelp tnafne nu ,siofrap te ,erbmos etef enu'd engapmahc ed ellub sel emmoc tnellitnics seliote sel uo egenam nu tse ednom el"
#define TAILLE_MESSAGE 127 // important d'etre exact, sinon probleme a l'inversion du buffer
int main (int argc, const char * argv[]) {
    
    // Etape 0 : definition des variables
    int sock;   // socket en mode non connecte UDP
    struct sockaddr_in AdresseServeur ; // carte de visite contenant l'identite du serveur
    socklen_t longueurStructAdresse; // contient la taille d'une carte de visite
    int nbSend; // stockage du nombre d'octets recus
    char *buffer = MESSAGE_A_ENVOYER;  // buffer pour envoyer le message (taille ajustee)
    
    //initialisation de longueurStructAdresse
    longueurStructAdresse=sizeof(struct sockaddr_in);
    
    // Etape 1 : creation de la socket de communication
    sock = socket(/* <a completer >*/ );
    if (sock ==-1) {
            // <a completer >
    }
    
    // Etape 2 : creation d'une structure type sockaddr_in contenant l'identite du serveur
    // identite composee d'une association IP-port
    AdresseServeur.sin_family= /* <a completer >*/ ; // famille d’adresse IPv4
    AdresseServeur.sin_addr.s_addr = /* <a completer >*/ ; // IP du serveur
    AdresseServeur.sin_port= /* <a completer >*/ ; // Port du serveur relie à l'application
    
    // Etape 3 : envoi du message
    // envoi vers serveur (identite contenue dans AdresseServeur
    nbSend = sendto(/* <a completer >*/);
    if (nbSend ==-1) {
        perror("erreur sendto()");
        exit(1);
    }
    printf("message envoye\n");
}
