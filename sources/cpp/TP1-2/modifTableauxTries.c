#include "modifTableauxTries.h"

int ajoutValeurTabTrie(int tab[], int taille, int tailleMax, int val){
    int i;
    if(taille != tailleMax){
        i = taille - 1;
        if(val > tab[i]){
            tab[taille] = val;

        }else{
            while((val < tab[i]) && (i >= 0)){
                tab[i + 1] = tab[i];
                i--;
            }
            tab[i + 1] = val;
        }
        return 1;
    }else{
        return 0;
    }
}

int supprimeValeurTabTrie(int tab[], int taille, int val){
    int iMax = taille - 1, iMin = 0;
    int iMid = (iMin + iMax) / 2;
    while((iMin != iMax) && (tab[iMid] != val)){
        if(tab[iMid] > val){
            iMax = iMid - 1;
        }else{
            iMin = iMid + 1;
        }
        iMid = (iMin + iMax) / 2;
    }
    if(tab[iMid] != val){
        return 0;
    }else{
        for(int i = iMid; i < taille - 1; ++i){
            tab[i] = tab[i + 1];
        }
        return 1;
    }
}

int supprimeToutesLesValeursTabTrie(int tab[], int taille, int val){
    int iMax = taille - 1, iMin = 0;
    int iMid = (iMin + iMax) / 2;
    int compteur = 0;
    int i;
    int iGauche;
    while((iMin != iMax) && (tab[iMid] != val)){
        if(tab[iMid] > val){
            iMax = iMid - 1;
        }else{
            iMin = iMid + 1;
        }
        iMid = (iMin + iMax) / 2;
    }
    if(tab[iMid] != val){
        return 0;
    }else{
        i = iMid;
        while((i >= iMin) && (tab[i] == val)){
            --i;
            ++compteur;
        }
        iGauche = i + 1;
        i = iMid + 1;
        while((i <= iMax) && (tab[i] == val)){
            ++compteur;
            ++i;
        }
        for(int i = iGauche; i < taille - 1; ++i){
            tab[i] = tab[i + compteur];
        }
        return compteur;
    }
}