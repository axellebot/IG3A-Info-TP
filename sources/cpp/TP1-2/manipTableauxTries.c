//
// Created by Axel LE BOT on 11/12/17.
//

#include "manipTableauxTries.h"

int valeurContenueDansTabTrie(int tab[], int taille, int val) {
    int iMin = 0;
    int iMax = taille - 1;
    int iMid;
    int trouve = -1;
    while ((iMin <= iMax) && (trouve == -1)) {
        iMid = (iMax + iMin) / 2;
        if (val < tab[iMid])
            iMax = iMid - 1;
        else if (val > tab[iMid])
            iMin = iMid + 1;
        else
            trouve = 1;
    }
    return (trouve);
}

int nbOccurencesValeurDansTabTrie(int tab[], int taille, int val) {
    int iMax = taille - 1, iMin = 0;
    int iMid = (iMin + iMax) / 2;
    int compteur = 0;
    int i;
    while ((iMin <= iMax) && (tab[iMid] != val)) {
        if (tab[iMid] > val) {
            iMax = iMid - 1;
        } else {
            iMin = iMid + 1;
        }
        iMid = (iMin + iMax) / 2;
    }
    i = iMid;
    while ((i >= iMin) && (tab[i] == val)) {
        ++compteur;
        --i;
    }
    i = iMid + 1;
    while ((i <= iMax) && (tab[i] == val)) {
        ++compteur;
        ++i;
    }
    return compteur;
}
