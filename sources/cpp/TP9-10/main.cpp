//
// Created by Axel LE BOT on 20/12/17.
//

#include "Guerrier.h"
#include "Mage.h"

extern "C" {
void displayHeader(int level, char *string);
bool endOfProgram();
}

#include "../libs/libs.h"

void combat() {
    Mage *mage = new Mage("Mage 1", 10, 5, 3, 3);
    Guerrier *guerrier = new Guerrier("Guerrier", 10, 5, 10);
}

int main() {
    displayHeader(1, (char *) "TP 9-10");
    bool finished = false;
    int ex = 0;
    while (!finished) {

        finished = endOfProgram();
        printf("Bye !!!");
        exit(0);
    }
}