
/*
 nom : ServeurUDPEcoute
 description : écoute en continu les messages UDP sur un port donné (ex 5000) en IPV4
 affiche le message recu ainsi que l'identité de l'émetteur
 auteur : darties
 */

// Liste des includes necessaires
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_DU_SERVEUR 9999999 // <a modifier >

// prend un tableau de caracteres en entree et sa taille
// inverse les caracteres (le premier devient le dernier, etc ...
void inverser_buffer(char * bufferainverser, int taille) {
    // precision : utiliser la taille du message, pas celle du buffer
    int i;
    char temp;
    for (i=0; i < taille/2 ; i++) {
        temp = bufferainverser[i];
        bufferainverser[i]= bufferainverser[taille-1-i];
        bufferainverser[taille-i-1] = temp;
    }
}


int main (int argc, const char * argv[]) {
    // Etape 0 : definition des variables
    int sock;   // socket en mode non connecte UDP
    struct sockaddr_in monAdresse; // pour le stockage de sa propre identite (serveur)
    struct sockaddr_in adresseClientEntrant; // pour le stockage de l'identité du client
    socklen_t longueurStructAdresse;
    
    int nbRecus; // stockage du nombre d’octets recus
    int retour; // valeur temporaire pour retour
    char buffer[1024];  // buffer pour lecture du message
    
    // Besoin de connaire la taille de la structure de type sockaddr_in
    longueurStructAdresse=sizeof(struct sockaddr_in);
    
   
    // Etape 1 : creation de la socket de communication
    sock = socket(/* <a completer >*/);
    if (sock ==-1) {
            /* <a completer >*/
    }
    
    // Etape 2 : creation d'une structure type sockaddr_in contenant sa propre identite
    // cette structure permettra de faire connaitre son identité
    // identité composée d'une association IP-port
    monAdresse.sin_family=/* <a completer >*/; // famille d’adresse IPv4
    monAdresse.sin_addr.s_addr = /* <a completer >*/; // n'importe quelle IP
    monAdresse.sin_port= /* <a completer >*/; // Port a associer
    // Etape 3 : association de l'adresse avec la socket
    retour = bind (/* <a completer >*/);
    if (retour ==-1) {
        perror("erreur bind()");
        exit(1);
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
        nbRecus = recvfrom(/* <a completer >*/);
        if (nbRecus ==-1) {
            perror("erreur bind()");
            exit(1);
        }
        // on inverse le buffer :
        inverser_buffer(/* <a completer >*/);
        // ajout du caractère de fin de buffer :
        buffer[nbRecus]='\0';
        
        // affichage du buffer 
        printf("message : %s\n", /* <a completer >*/);
        
    }
}
