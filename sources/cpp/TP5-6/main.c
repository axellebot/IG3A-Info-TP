//
// Created by Axel LE BOT on 08/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include "../libs/libs.h"

void signalsHandler(int interruption){
    printf("Signal received\n");
    switch(interruption){
        case SIGINT:
            printf("SIGNAL SIGINT\n");
            break;
        case SIGUSR1 :
            printf("SIGNAL SIGUSR1\n");
            break;
        default:
            printf("SIGNAL NOT FOUND\n");
    }
}

// Exercice 1
void exercice1(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 1");
    printf("Lancement du processus %i\n", getpid());
    while(true){
        sleep(1);
        printf(".\n");
    }
}

// Exercice 2
void exercice2(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 2");

    signal(SIGINT, signalsHandler);
    signal(SIGUSR1, signalsHandler);

    while(true){
        sleep(1);
        printf(".\n");
    }
}

void exercice4(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 4");
    printf("Lancement du processus %i\n", getpid());
    signal(SIGINT, signalsHandler);
    while(true){
        printf(".\n");
        sleep(1);
    }
}

int main(){
    displayHeader(HEADER_LEVEL_TP, "TP 5-6");

    printf("Lancement du processus %d\n", getpid());

    bool finished = false;
    int ex = 0;
    while(!finished){
        printf("Select an exercice [1-4] : ");
        scanf("%d", &ex);
        switch(ex){
            case 1:
                exercice1();
                break;
            case 2:
                exercice2();
                break;
            case 3:
                printf("See shell script");
                break;
            case 4:
                exercice4();
                printf("See shell script too");
                break;
            default:
                printf("404 Not found");
        }
        finished = endOfProgram();
    }

    printf("Bye !!!");
    exit(0);
}