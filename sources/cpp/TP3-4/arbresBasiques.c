//
// Created by Axel LE BOT on 19/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "arbresBasiques.h"

struct noeud *unArbrePredefini() {
    struct noeud *Racine = NULL;
    Racine = nouveauNoeud(17);
    struct noeud *NewNoeud;
    NewNoeud = nouveauNoeud(5);
    Racine->filsGauche = NewNoeud;
    NewNoeud = nouveauNoeud(23);
    Racine->filsDroit = NewNoeud;
    NewNoeud->filsGauche = nouveauNoeud(19);
    NewNoeud->filsDroit = nouveauNoeud(29);
    NewNoeud = NewNoeud->filsDroit;
    NewNoeud->filsDroit = nouveauNoeud(33);
    NewNoeud->filsDroit->filsDroit = nouveauNoeud(37);
    NewNoeud->filsDroit->filsGauche = nouveauNoeud(31);
    NewNoeud = Racine->filsGauche;
    NewNoeud->filsDroit = nouveauNoeud(11);
    NewNoeud = NewNoeud->filsDroit;
    NewNoeud->filsDroit = nouveauNoeud(13);
    return Racine;
}

struct noeud *nouveauNoeud(int val) {
    struct noeud *noeudRetour;
    // reservation d'un espace memoire dans le tas
    noeudRetour = (struct noeud *) malloc(sizeof(struct noeud));

    // affectation des valeurs si l'allocation memoire reussit
    if (noeudRetour != NULL) {
        noeudRetour->valeur = val;
        noeudRetour->filsGauche = NULL;
        noeudRetour->filsDroit = NULL;
    } else {
        perror("error : not enough memory");
        exit(1);
    }
    //renvoi le pointeur vers le noeud crée
    return noeudRetour;
}

int afficheArbre(struct noeud *noeudPointe) {
    // @action : affiche l'arbre pointe par noeudPointe
    // a ne pas modifier sauf si vous savez ce que vous faites
    int nbNoeuds = 1;
    if (noeudPointe == NULL) return 0;
    printf("Noeud %4i : ", noeudPointe->valeur);
    if (noeudPointe->filsGauche == NULL)
        printf("filsGauche : vide  - ");
    else
        printf("filsGauche : %4i  - ", noeudPointe->filsGauche->valeur);

    if (noeudPointe->filsDroit == NULL)
        puts("filsDroit : vide");
    else
        printf("filsDroit : %4i\n", noeudPointe->filsDroit->valeur);

    if (noeudPointe->filsGauche != NULL)
        nbNoeuds += afficheArbre(noeudPointe->filsGauche);
    if (noeudPointe->filsDroit != NULL)
        nbNoeuds += afficheArbre(noeudPointe->filsDroit);
    return nbNoeuds;
}


int estVide(struct noeud *noeudPointe) {
    return (noeudPointe == NULL) ? 1 : 0;
}

int estFeuille(struct noeud *noeudPointe) {
    return (noeudPointe != NULL &&
            noeudPointe->filsGauche == NULL &&
            noeudPointe->filsDroit == NULL) ? 1 : 0;
}

int rechercheValeur(struct noeud *noeudPointe, int val) {
    struct noeud *courant = noeudPointe;
    int trouve = 0;
    if (courant == NULL) {
        trouve = 0;
    } else if (courant->valeur > val) {
        trouve = rechercheValeur(courant->filsGauche, val);
    } else if (courant->valeur < val) {
        trouve = rechercheValeur(courant->filsDroit, val);
    } else {
        trouve = 1;
    }
    return trouve;
}



