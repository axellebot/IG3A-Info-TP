#include "algosTri.h"

void triABulle(int tab[], int taille){
    int i, j, tmp;
    for(i = taille - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(tab[j + 1] < tab[j]){
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

void triSelection(int tab[], int taille){
    int i, j, tmp;
    for(i = 0; i < taille - 1; i++){
        for(j = i; j < taille; j++){
            if(tab[j] < tab[i]){
                tmp = tab[j];
                tab[j] = tab[i];
                tab[i] = tmp;
            }
        }
    }
}
