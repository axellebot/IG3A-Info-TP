//
// Created by axel on 08/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>

void displayHeaderTP(int number) {
    printf("\n////////////////////////////////////\n/////////////// TP %d ///////////////\n////////////////////////////////////\n",
           number);
}

void displayHeaderExercice(int number) {
    printf("\n-----------Exercice %d-----------\n", number);
}

bool endOfProgram() {
    char s;
    printf("Stop ? [Y/n] : ");
    scanf("%s", &s);

    if (s == 'N' || s == 'n') {
        return false;
    } else {
        return true;
    }
}

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
    displayHeaderExercice(1);

    while(true){
        sleep(1);
        printf(".\n");
    }
}

// Exercice 2
void exercice2(){
    displayHeaderExercice(2);

    signal(SIGINT, signalsHandler);
    signal(SIGUSR1, signalsHandler);

    while(true){
        sleep(1);
        printf(".\n");
    }
}

int main(){
    displayHeaderTP(5);

    printf("Lancement du processus %d\n",getpid());

    bool finished = false;
    int ex = 0;
    while (!finished) {
        printf("Select an exercice [1-2] : ");
        scanf("%d", &ex);
        switch (ex) {
            case 1:
                exercice1();
                break;
            case 2:
                exercice2();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
            default:
                printf("404 Not found");
        }
        finished = endOfProgram();
    }

    printf("Bye !!!");
    exit(0);
}