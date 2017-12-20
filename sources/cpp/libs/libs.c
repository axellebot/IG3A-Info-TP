//
// Created by Axel LE BOT on 17/11/17.
//

#include "libs.h"
#include <stdio.h>

void displayHeaderTP(int number) {
    printf("\n////////////////////////////////////\n/////////////// TP %d ///////////////\n////////////////////////////////////\n",
           number);
}

void displayHeaderExercice(int number) {
    printf("\n-----------Exercice %d-----------\n", number);
}

bool endOfProgram() {
    char s;
    printf("\nStop ? [Y/n] : ");
    scanf("%s", &s);

    if (s == 'N' || s == 'n') {
        return false;
    } else {
        return true;
    }
}
