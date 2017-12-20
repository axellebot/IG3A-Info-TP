//
// Created by Axel LE BOT on 20/12/17.
//

#include "Guerrier.h"

extern "C" {
void displayHeaderTP(int number);
void displayHeaderExercice(int number);
bool endOfProgram();
}

#include "Mage.h"

void combat(){
    Mage *mage = new Mage("Mage 1", 10, 5, 3, 3);
    Guerrier *guerrier = new Guerrier("Guerrier", 10, 5, 10);
}

int main(){
    displayHeaderTP(9);
    bool finished = false;
    int ex = 0;
    while(!finished){

        finished = endOfProgram();
        printf("Bye !!!");
        exit(0);
    }
}