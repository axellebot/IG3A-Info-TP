#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbresBasiques.h"
#include "arbresFctRecursives.h.h"

#include "modifArbres.h"


// fonction main() a ne pas modifier
int main() {
    int i, j;
    struct noeud *racine;
    racine = NULL;
    srand(time(NULL));
    // recuperation de l'arbre predefini
    //  racine = unArbrePredefini();
    i = afficheArbre(racine);
    if (i == 0)
        printf(" arbre vide\n");

    for (i = 0; i < 10000000; i++) {
        j = rand();
        //  printf("ajout de la valeur %i\n", j);
        racine = ajouterValeurABR(racine, j);
    }
    // afficheArbre(racine);
    printf("arbre genere\n");
    for (i = 0; i < 500000; i++) {
        j = rand();
        rechercheValeur(racine, j);
//        printf("% dans larbre? %i\n", j, rechercheValeur(racine, j)) ;
    }

}
