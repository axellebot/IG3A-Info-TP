//
// Created by Axel LE BOT on 11/12/17.
//

#include "modifTableauxNonTries.h"

int ajoutValeurTabNonTrie(int tab[], int taille, int tailleMax, int val) {
    if (tailleMax == taille) return 0;
    else {
        tab[taille] = val;
        return 1;
    }
}

int supprimeValeurTabNonTrie(int tab[], int taille, int val) {
    int i = 0, suppression = 0, temp;
    while (i < taille && suppression == 0) {
        if (tab[i] == val) {
            temp = tab[i];
            tab[i] = tab[taille - 1];
            tab[taille - 1] = temp;
            suppression = 1;
        }
        i++;
    }
    return suppression;
}

int supprimeToutesLesValeursTabNonTrie(int tab[], int taille, int val) {
    int compteur = 0;
    while (supprimeValeurTabNonTrie(tab, taille - compteur, val)) {
        compteur++;
    }
    return compteur;
}