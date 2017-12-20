//
// Created by Axel LE BOT on 11/12/17.
//

#include <stdio.h>


void remplir(int taille1, int taille2, int M[taille1][taille2], int i, int j){
    if(M[i][j] != 2){
        int tmp = M[i][j];
        M[i][j] = 2;
        if(i > 0 && M[i - 1][j] == tmp){
            remplir(taille1, taille2, M, i - 1, j);
        }
        if(i < taille1 - 2 && M[i + 1][j] == tmp){
            remplir(taille1, taille2, M, i + 1, j);
        }
        if(j > 0 && M[i][j - 1] == tmp){
            remplir(taille1, taille2, M, i, j - 1);
        }
        if(j < taille2 - 2 && M[i][j + 1] == tmp){
            remplir(taille1, taille2, M, i, j + 1);
        }
    }
}

void afficheMatrice(int taille1, int taille2, int M[taille1][taille2]){
    // affiche la matrice M dont les dimensions sont passees en param.
    int i, j;
    printf("\n");
    for(i = 0; i < taille2; i++){
        printf("----");
    }
    printf("\n");
    for(i = 0; i < taille1; i++){
        for(j = 0; j < taille2; j++){
            printf("| %i ", M[i][j]);
        }
        printf("|\n");
    }
    for(j = 0; j < taille2; j++){
        printf("----");
    }
    printf("\n");
}
