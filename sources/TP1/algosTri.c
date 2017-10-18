#include <stdbool.h>
#include "algosTri.h"

void triABulle(int tab[], int taille){
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    // @action : tri le tableau selon l'algorithme de tri a bulle

    // [a completer] ajouter code de triABulle()

    int i=0;
    bool swapped=true;
    while(swapped){
        swapped=false;
        i=0;
        for(i=0;i<taille;i++){
            //compare
            if(tab[i]>tab[i+1]){
                //swap
                tab[i] = tab[i]+tab[i+1];
                tab[i+1]=tab[i]-tab[i+1];
                tab[i]=tab[i]-tab[i+1];
                swapped=true;
            }
        }
    }
}

void triSelection(int tab[], int taille){
    // @params : tab : tableau d'entiers, taille : taille effective du tableau
    // @action : tri le tableau selon l'algorithme de tri par selection

    // [a completer] ajouter code de triSelection()
    int iMin;
    int i,j;
    for(i =0;i<taille-1;i++){
        int iMin = j;
        for(j=i+1;j<taille;j++){
            if(tab[j]<tab[iMin]){
                iMin = j;
            }
        }
        if(iMin!=i){
            //swap
            tab[i] = tab[i]+tab[iMin];
            tab[iMin]=tab[i]-tab[iMin];
            tab[i]=tab[i]-tab[iMin];
        }
    }
}

