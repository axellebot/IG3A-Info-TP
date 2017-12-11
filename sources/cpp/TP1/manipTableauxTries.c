#include "manipTableauxTries.h"

int valeurContenueDansTabTrie(int tab[], int taille, int val){
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           val : une valeur a chercher dans le tableau
    // @retour : 1 si la valeur val est contenue dans tab. 0 sinon

    int retour = 0;
    int find = 0;
    // [a completer] ajouter code de valeurContenueDansTabTrie()
    int min = 0;
    int max = taille;

    while(find == 0){
        if((max - min) == 1){
            find = 1;
        }
        if(tab[(min + max) / 2] == val){
            retour = 1;
            find = 1;
        }else if(tab[(min + max) / 2] > val){
            max = (min + max) / 2;
        }else if(tab[(min + max) / 2] < val){
            min = (min + max) / 2;
        }
    }

    return retour;
}

int nbOccurencesValeurDansTabTrie(int tab[], int taille, int val){
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           val : uen valeur a chercher dans le tableau
    // @retour : 1 si la valeur val est contenue dans tab. 0 sinon
    int retour = 0;
    int min = 0;
    int max = taille;
    int find = 0;
    // [a completer] ajouter code de nbOccurencesValeurDansTabTrie()
    while(find == 0){
        if((max - min) == 1){
            find = 1;
        }
        if(tab[(min + max) / 2] == val){
            retour++;
            int tval1 = 0;
            int tval2 = 0;
            while(tab[((min + max) / 2) + 1 + tval1] == val){
                retour++;
                tval1++;
            }
            while(tab[((min + max) / 2) - 1 - tval2] == val){
                retour++;
                tval2++;
            }
            find = 1;
        }else if(tab[(min + max) / 2] > val){
            max = (min + max) / 2;
        }else if(tab[(min + max) / 2] < val){
            min = (min + max) / 2;
        }
    }

    return retour;
}
