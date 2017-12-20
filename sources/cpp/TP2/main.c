//
// Created by Axel LE BOT on 11/12/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/libs.h"
#include "factorielle.h"
#include "harmonique.h"
#include "piLeibniz.h"
#include "bubbleBreaker.h"

//Exercice 6
void exercice6(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 6");

    int value = 0;
    printf("Entrer un nombre pour les algos :");
    scanf("%d", &value);
    printf("\n");

    //Factorielle
    printf("calcul de factorielle(%d) en iteratif : \n", value);
    printf("factorielle(%d) = %d\n", value, factorielle(value));
    printf("calcul de factorielle(%d) en recursif : \n", value);
    printf("factorielle(%d) = %d\n", value, factorielleRecursif(value));

    //Harmonique
    printf("calcul de harmonique(%d) en iteratif : \n", value);
    printf("harmonique(%d) = %lf\n", value, harmonique(value));
    printf("calcul de harmonique(%d) en recursif : \n", value);
    printf("harmonique(%d) = %lf\n", value, harmoniqueRecursif(value));

    //PiLeibniz
    printf("calcul de PiLeibniz(%d) en iteratif : \n", value);
    printf("PiLeibniz(%d) = %f\n", value, PiLeibniz(value));
    printf("calcul de PiLeibniz(%d) en recursif : \n", value);
    printf("PiLeibniz(%d) = %f\n", value, PiLeibnizRecursif(value));
}

void exercice7(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 7");
    int taille1 = 9, taille2 = 15;
    int M[9][15] = {
            {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1},
            {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
            {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0},
            {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    };

    printf("etat de la matrice avant selection de cellule:");
    afficheMatrice(taille1, taille2, M);

    // selection de la case (8,0)
    remplir(taille1, taille2, M, 8, 0);
    printf("etat de la matrice apres selection d'une cellule:");
    afficheMatrice(taille1, taille2, M);
}

int main(){
    displayHeader(HEADER_LEVEL_TP, "TP 2");

    bool finished = false;
    int ex = 0;
    while(!finished){
        printf("Select an exercice : ");
        scanf("%d", &ex);
        switch(ex){
            case 6:
                exercice6();
                break;
            case 7:
                exercice7();
                break;
            default:
                printf("404 Not found");
        }
        finished = endOfProgram();
    }

    printf("Bye !!!");
    exit(0);
}
