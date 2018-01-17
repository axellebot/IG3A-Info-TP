#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbresbasiques.h"
#include "arbresfctrecursives.h"

#include "modifarbres.h"


// fonction main() a ne pas modifier
int main() {
    int i,j;
    struct noeud * racine;
    racine =NULL;
    srand(time(NULL));
    // recuperation de l'arbre predefini
    racine = unArbrePredefini();
    i = afficheArbre(racine);
    if (i ==0)
        printf(" arbre vide\n");

    for (i =0; i < 5; i++) {
        j = rand() % 100;
        printf("ajout de la valeur %i\n", j);
        racine = ajouterValeurABR(racine, j) ;
    }
    afficheArbre(racine);
    
    for (i =0; i < 5; i++) {
        j = rand() % 100;

        rechercheValeur(racine, j);
        printf("% dans larbre? %i\n", j, rechercheValeur(racine, j)) ;
    }

    printf("entrez une valeur a supprimer ");
    scanf("%d", &i);
    supprimerValeurABR(racine, i);
    printf("arbre apres suppression ");
    afficheArbre(racine);

}