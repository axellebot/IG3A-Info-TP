#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int M[9][15] = {{1,1,1,0,1,0,0,1,0,1,1,0,0,0,1},
                {1,0,0,1,1,1,0,0,0,1,1,1,1,1,0},
                {1,0,0,0,1,0,1,1,0,0,1,1,0,1,1},
                {1,1,1,0,1,0,0,1,0,1,1,0,0,0,1},
                {1,1,0,0,0,0,1,0,1,0,0,0,1,0,0},
                {1,0,0,0,0,0,0,0,0,1,1,0,1,0,0},
                {1,0,0,1,0,1,0,0,1,0,0,1,0,1,1},
                {0,1,1,1,0,0,0,1,1,1,0,1,0,1,0},
                {1,1,0,1,1,0,0,0,1,0,0,1,1,1,0}};


void remplir (int M[9][15], int taille1, int taille2, int x, int y) {
    // [a completer] code de la fonction remplir()
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

int main() {
    printf("etat de la matrice avant selection de cellule:");
    afficheMatrice(M, 9, 15);
    
    // selection d'une cellule (ici 5,7) et modification des valeurs
    remplir (M, 9, 15,5,7);
    
    printf("etat de la matrice apres selection d'une cellule:");
    afficheMatrice(M, 9, 15);
     /* resultat attendu si cellule (5,7) selectionnee :
      ------------------------------------------------------------
      | 1 | 1 | 1 | 0 | 1 | 0 | 0 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 |
      | 1 | 2 | 2 | 1 | 1 | 1 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 0 |
      | 1 | 2 | 2 | 2 | 1 | 2 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 1 | 1 |
      | 1 | 1 | 1 | 2 | 1 | 2 | 2 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 |
      | 1 | 1 | 2 | 2 | 2 | 2 | 1 | 2 | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
      | 1 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 1 | 1 | 0 | 1 | 0 | 0 |
      | 1 | 2 | 2 | 1 | 2 | 1 | 2 | 2 | 1 | 0 | 0 | 1 | 0 | 1 | 1 |
      | 0 | 1 | 1 | 1 | 2 | 2 | 2 | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 0 |
      | 1 | 1 | 0 | 1 | 1 | 2 | 2 | 2 | 1 | 0 | 0 | 1 | 1 | 1 | 0 |
      ------------------------------------------------------------
      */
    
    return 0;
}