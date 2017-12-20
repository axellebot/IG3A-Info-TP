
#include "manipTableauxNonTries.h"

int sommeElementsTab(int tab[], int taille) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    // @retour : la somme des elements du tableau

    // [a completer] ajouter code de la fonction sommeElementsTab()
    int somme = 0;
    int i = 0;
    for (i = 0; i < taille; i++) {
        somme += tab[i];
    }
    return somme;
}


int moyenneValeursTab(int tab[], int taille) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           val : uen valeur a chercher dans le tableau
    // @retour : la moyenne des valeurs contenues dans tab

    // [a completer] ajouter code de moyenneValeursTab()

    int somme = sommeElementsTab(tab, taille);
    return somme / taille;
}

int valeurContenueDansTabNonTrie(int tab[], int taille, int val) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           val : une valeur a chercher dans le tableau
    // @retour : 1 si la valeur val est contenue dans tab. 0 sinon

    // [a completer] ajouter code de valeurContenueDansTabNonTrie()

    int i = 0;
    while (i < taille) {
        if (tab[i] == val) return 1;
        i++;
    }
    return 0;
}

int nbOccurencesValeurDansTabNonTrie(int tab[], int taille, int val) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           val : une valeur a chercher dans le tableau
    // @retour : nombre de fois que la valeur val est contenue dans tab.

    // [a completer] ajouter code de nbOccurencesValeurDansTabNonTrie()
    int occurence = 0;
    int i = 0;
    for (i = 0; i < taille; i++) {
        if (tab[i] == val) occurence++;
    }
    return occurence;
}

