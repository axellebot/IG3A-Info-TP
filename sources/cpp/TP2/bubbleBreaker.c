//
// Created by axel on 11/12/17.
//

#include <stdio.h>
#include "bubbleBreaker.h"



void remplir (int M[9][15], int taille1, int taille2, int x, int y) {
    int temp;
    if(M[x][y] != 2){
        temp = M[x][y];
        M[x][y] = 2;
        if(x<8 && M[x+1][y] == temp){
            remplir(M, 9, 15, x+1, y);
        }
        if(x>0 && M[x-1][y] == temp){
            remplir(M, 9, 15, x-1, y);
        }
        if(y>0 && M[x][y-1] == temp){
            remplir(M, 9, 15, x, y-1);
        }
        if(y<14 && M[x][y+1] == temp){
            remplir(M, 9, 15, x, y+1);
        }
    }
}

void afficheMatrice (int M[9][15], int taille1, int taille2) {
    // affiche la matrice M dont les dimensions sont passees en param.
    int i,j;
    printf("\n");
    for (j=0; j < taille2; j++) {
        printf("----");
    }
    printf("\n");
    for (i=0; i < taille1; i++) {
        for (j=0; j < taille2; j++) {
            printf("| %i ", M[i][j]);
        }
        printf("|\n");
    }
    for (j=0; j < taille2; j++) {
        printf("----");
    }
    printf("\n");
}
