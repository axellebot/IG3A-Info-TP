#include <stdio.h>
#include "modifTableauxTries.h"


int ajoutValeurTabTrie(int tab[], int taille, int tailleMax, int val) {
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    //           tailleMax : nb d'element maximum du tableau. val : valeur
    // @action : ajoute val au tableau s'il reste de la place, sinon ne fait rien
    // @retour : retourne 1 si la valeur val a ete correctement ajoutee
    //           retourne 0 sinon (tableau plein)
    int retour = 0;
    int end = 0;
    int i = taille;
    // [a completer] ajouter code de valeurContenueDansTabTrie()
    if (taille == tailleMax) {
        retour = 0;
    } else {

        while (end == 0) {

            if (tab[i] == val) {
                tab[i + 1] = tab[i];
                tab[i] = val;
                retour++;
                end = 1;
            } else if ((tab[i - 1] <= val) && (tab[i + 1] >= val)) {
                tab[i + 1] = tab[i];
                tab[i] = val;
                retour++;
                end = 1;
            } else {
                tab[i + 1] = tab[i];
            }

            if (i == 0) {
                end = 1;
            }
            i--;

        }
    }

    int k = 0;
    for (k = 0; k < taille + 1; k++) {
        printf("%i , ", tab[k]);
    }

    return retour;


}


int supprimeValeurTabTrie(int tab[], int taille, int val) {
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    //           val : valeur
    // @action : supprime la premiere occurence de val dans le tableau
    // @retour : retourne 1 si la valeur val a ete correctement supprimee
    //           retourne 0 sinon (valeur non trouvee)

    // [a completer] ajouter code de supprimeValeurTabTrie()
    int retour = 0;
    int find = 0;
    // [a completer] ajouter code de valeurContenueDansTabTrie()
    int min = 0;
    int max = taille;
    int indice = 0;

    while (find == 0) {

        if ((max - min) == 1) {
            find = 1;
        }
        if (tab[(min + max) / 2] == val) {
            find = 1;
            indice = (min + max) / 2;
        } else if (tab[(min + max) / 2] > val) {
            max = (min + max) / 2;
        } else if (tab[(min + max) / 2] < val) {
            min = (min + max) / 2;
        }
    }

    if (indice != 0) {
        retour = 1;
        int i;

        for (i = indice; i < taille; i++) {
            tab[i] = tab[i + 1];

        }

    }

    if (retour == 1) {
        taille--;
    }
    int k = 0;
    for (k = 0; k < taille; k++) {
        printf("%i , ", tab[k]);
    }

    return retour;

}


int supprimeToutesLesValeursTabTrie(int tab[], int taille, int val) {
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    //           val : valeur
    // @action : supprime toutes les occurences de val dans le tableau
    // @retour : retourne le nombre d'occurences supprimees

    // [a completer] ajouter code de supprimeToutesLesValeursTabTrie()
    int retour = 0;
    int find = 0;
    int min = 0;
    int max = taille;
    int indice = 0;

    while (find == 0) {

        if ((max - min) == 1) {
            find = 1;
        }
        if (tab[(min + max) / 2] == val) {
            find = 1;
            indice = (min + max) / 2;
        } else if (tab[(min + max) / 2] > val) {
            max = (min + max) / 2;
        } else if (tab[(min + max) / 2] < val) {
            min = (min + max) / 2;
        }
    }

    if (indice != 0) {
        retour = 1;
        int indicemin = indice;

        while (tab[indicemin] == val) {
            indicemin--;
            retour++;

        }

        int indicemax = indice;

        while (tab[indicemax] == val) {
            indicemax++;
            retour++;

        }
        int diffindice = indicemax - indicemin;
        int i;
        for (i = indicemin; i < taille; i++) {
            tab[i] = tab[i + diffindice];

        }

    }

    if (retour > 0) {
        taille--;
    }
    int k = 0;
    for (k = 0; k < taille; k++) {
        printf("%i , ", tab[k]);
    }

    return retour;
}
