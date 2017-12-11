#include <stdbool.h>
#include "modifTableauxNonTries.h"

int ajoutValeurTabNonTrie(int tab[], int taille, int tailleMax, int val){
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    //           tailleMax : nb d'element maximum du tableau. val : valeur
    // @action : ajoute val au tableau s'il reste de la place, sinon ne fait rien
    // @retour : retourne 1 si la valeur val a ete correctement ajoutee
    //           retourne 0 sinon (tableau plein)

    // [a completer] ajouter code de valeurContenueDansTabNonTrie()

    if(taille >= tailleMax) return 0;
    tab[taille] = val;
    taille--;
    return 1;
}

int supprimeValeurTabNonTrie(int tab[], int taille, int val){
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    //           val : valeur
    // @action : supprime la premiere occurence de val dans le tableau
    // @retour : retourne 1 si la valeur val a ete correctement supprimee
    //           retourne 0 sinon (valeur non trouvee)

    // [a completer] ajouter code de supprimeValeurTabNonTrie()
    bool finish = false;
    int i = 0;
    while(!finish || i < taille){
        if(tab[i] == val){
            tab[i] = tab[taille - 1];
            taille--;
            finish = true;
        }
        i++;
    }
    return finish;
}

int supprimeToutesLesValeursTabNonTrie(int tab[], int taille, int val){
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    //           val : valeur
    // @action : supprime toutes les occurences de val dans le tableau
    // @retour : retourne le nombre d'occurences supprimees

    // [a completer] ajouter code de supprimeToutesLesValeursTabNonTrie()
    int i = 0, count = 0;
    for(i = 0; i < taille; i++){
        if(tab[i] == val){
            tab[i] = tab[taille - 1];
            count++;
            taille--;
            i--;
        }
    }
    return count;
}
