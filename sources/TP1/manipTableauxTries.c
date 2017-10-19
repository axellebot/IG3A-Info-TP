#include <stdbool.h>
#include "manipTableauxTries.h"

int valeurContenueDansTabTrie(int tab[], int taille, int val) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           val : une valeur a chercher dans le tableau
    // @retour : 1 si la valeur val est contenue dans tab. 0 sinon

    // [a completer] ajouter code de valeurContenueDansTabTrie()
    bool finished = false, found = false;
    int i = 0;
    while (i < taille || !finished) {
        if (tab[i] > val) {
            finished = true;
        } else if (tab[i] == val) {
            found = true;
            finished = true;
        }
        i++;
    }
    return found;
}

int nbOccurencesValeurDansTabTrie(int tab[], int taille, int val) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           val : uen valeur a chercher dans le tableau
    // @retour : 1 si la valeur val est contenue dans tab. 0 sinon

    // [a completer] ajouter code de nbOccurencesValeurDansTabTrie()
    bool finished = false;
    int count = 0;
    int i = 0;
    while (i < taille || !finished) {
        if (tab[i] > val) {
            finished = true;
        } else if (tab[i] == val) {
            count++;
        }
        i++;
    }
    return count;
}

