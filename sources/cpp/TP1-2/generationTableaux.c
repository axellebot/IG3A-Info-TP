//
// Created by Axel LE BOT on 11/12/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "generationTableaux.h"

int nbAleatoire(int min, int max) {
    int nb = min + rand() % (max - min);
    return nb;
}

void afficherTab(int tab[], int taille) {
    int i = 0;
    for (i = 0; i < taille; i++) {
        printf("%i , ", tab[i]);
    }
    printf(" \n");
}

void remplirTabValeursAleatoires(int tab[], int taille, int min, int max) {
    int i = 0;
    for (i = 0; i < taille; i++) {
        tab[i] = nbAleatoire(min, max);
    }
}

void remplirTabValeurs1aN(int tab[], int taille) {
    int i = 0;
    for (i = 0; i < taille; i++) {
        tab[i] = i + 1;
    }
}

void melangerTab(int tab[], int taille, int nb) {
    int u, v, temp;
    int i = 0;
    for (i = 0; i < 100; i++) {
        int u = nbAleatoire(0, 14);
        int v = nbAleatoire(0, 14);
        int temp = 0;
        temp = tab[u];
        tab[u] = tab[v];
        tab[v] = temp;
    }
}
