#include <stdio.h>
#include <stdlib.h>
#include "arbresbasiques.h"
#include "arbresFctRecursives.h"


// fonction main() a ne pas modifier
int main() {
    int i;
    struct noeud * racine;
    // recuperation de l'arbre predefini
    racine = unArbrePredefini();
    printf("affichage d'un arbre : \n");
    i = afficheArbre(racine);
    if (i ==0)
        printf("arbre vide\n");
    
    // test de la fonction nbNoeuds
    i = nbNoeuds(racine);
    printf("le nombre de ses noeuds est %i\n",i);
    
    // test de la fonction sommeValArbres
    i = sommeValArbres(racine);
    printf("la somme de ses valeurs est %i\n",i);

    // test de la fonction hauteur
    i = hauteur(racine);
    printf("sa hauteur est %i\n",i);

    
}