//
// Created by Axel LE BOT on 11/12/17.
//

#include "manipTableauxNonTries.h"

int sommeElementsTab(int tab[], int taille) {
    int somme = 0;
    int i = 0;
    for (i = 0; i < taille; i++) {
        somme += tab[i];
    }
    return somme;
}

int moyenneValeursTab(int tab[], int taille) {
    return sommeElementsTab(tab, taille) / taille;
}

int valeurContenueDansTabNonTrie(int tab[], int taille, int val) {
    int contenue = 0;
    int i = 0;
    while (i < taille && contenue == 0) {
        if (tab[i] == val) contenue = 1;
        i++;
    }
    return contenue;
}

int nbOccurencesValeurDansTabNonTrie(int tab[], int taille, int val) {
    int occurence = 0;
    int i = 0;
    for (i = 0; i < taille; i++) {
        if (tab[i] == val) occurence++;
    }
    return occurence;
}
