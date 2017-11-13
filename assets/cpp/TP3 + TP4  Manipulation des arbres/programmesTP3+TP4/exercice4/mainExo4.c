#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbresbasiques.h"
#include "arbresfctrecursives.h"
#include "modifarbres.h"
#include "parcoursArbres.h"


// fonction main() a ne pas modifier
int main() {
    int i,j;
    struct noeud * racine;
    racine = NULL;

    // recuperation de l'arbre predefini
    racine = unArbrePredefini();

    // affichage de l'arbre en format classique
    printf("affichage de l'arbre :\n");
    afficheArbre(racine);
    
    // affichage du parcours en profondeur
    printf("le parcours en profondeur de l'arbre est :\n");
    parcoursProfondeur(racine);
    printf("\n");
    exit(0);
}