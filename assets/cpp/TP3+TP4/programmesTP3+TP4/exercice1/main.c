#include <stdio.h>
#include <stdlib.h>
#include "arbresbasiques.h"


// fonction main() a ne pas modifier
int main() {
    int i;
    struct noeud * racine;
    // recuperation de l'arbre predefini
    racine = unArbrePredefini();
    i = afficheArbre(racine);
    if (i ==0)
        printf(" arbre vide\n");
}