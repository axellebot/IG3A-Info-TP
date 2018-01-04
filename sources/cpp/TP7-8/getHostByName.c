//
// Created by Axel LE BOT on 20/12/17.
//

#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>

void affichage_IP_host(char *host){
    struct hostent *he;
    struct in_addr **addr_list;
    // réupération des infos de l'host
    if((he = gethostbyname(host)) == NULL){
        perror("Impossible de récupérer les infos host (vérifiez votre connexion internet)");
    }else{
        // affichage de l'adresse IP :
        printf("Adresse IP de %s : ", host);
        addr_list = (struct in_addr **) he->h_addr_list;
        for(int i = 0; addr_list[i] != NULL; i++){
            printf("%s ", inet_ntoa(*addr_list[i]));
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    char *yahoo = "www.yahoo.fr";
    char *gmail = "www.gmail.com";
    char *ubourgogne = "www.u-bourgogne.fr";
    affichage_IP_host(yahoo);
    affichage_IP_host(gmail);
    affichage_IP_host(ubourgogne);
}  
