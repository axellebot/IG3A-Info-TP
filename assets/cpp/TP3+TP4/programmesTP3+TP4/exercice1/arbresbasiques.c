#include <stdio.h>
#include <stdlib.h>

#include "arbresbasiques.h"


struct noeud* nouveauNoeud(int val) {
    // @params : val : valeur du nouveau noeud a creer
    // @result : retourne un pointeur sur le noeud nouvellement cree
    //            Les fils droits et gauche sont initialises a null
    
    struct noeud* noeudRetour;
    
    // reservation d'un espace memoire dans le tas

    // [a completer]
    
    // affectation des valeurs si l'allocation memoire reussit
    if (noeudRetour != NULL) {
        // [a completer]
    } else {
        printf("erreur : plus de memoire (gros probleme!)\n");
        exit(1);
    }
    //renvoi du pointeur vers le noeud nouvellement cree
    return noeudRetour;
}


struct noeud * unArbrePredefini() {
    // action : definit en memoire l'arbre de l'enonce
    // result : un pointeur vers la racine de cet arbre
    // fonction a ne pas modifier, ne fonctionnera que si nouveauNoeud est faite
    struct noeud* Racine = NULL;
    Racine = nouveauNoeud(17);
    struct noeud* NewNoeud;
    NewNoeud = nouveauNoeud(5);
    Racine->filsGauche=NewNoeud;
    NewNoeud = nouveauNoeud(23);
    Racine->filsDroit=NewNoeud;
    NewNoeud->filsGauche=nouveauNoeud(19);
    NewNoeud->filsDroit=nouveauNoeud(29);
    NewNoeud = NewNoeud->filsDroit;
    NewNoeud->filsDroit=nouveauNoeud(33);
    NewNoeud->filsDroit->filsDroit=nouveauNoeud(37);
    NewNoeud->filsDroit->filsGauche=nouveauNoeud(31);
    NewNoeud =Racine->filsGauche;
    NewNoeud->filsDroit = nouveauNoeud(11);
    NewNoeud = NewNoeud->filsDroit;
    NewNoeud->filsDroit = nouveauNoeud(13);
    return Racine;
}

int afficheArbre(struct noeud * noeudPointe) {
    // @action : affiche l'arbre pointe par noeudPointe
    // a ne pas modifier sauf si vous savez ce que vous faites
    int nbNoeuds =1;
    if (noeudPointe==NULL) return 0;
    printf("Noeud %4i : ", noeudPointe->valeur);
    if (noeudPointe->filsGauche == NULL)
        printf("filsGauche : vide  - ");
    else
        printf("filsGauche : %4i  - ", noeudPointe->filsGauche->valeur);

    if (noeudPointe->filsDroit == NULL)
        printf("filsDroit : vide\n");
    else
        printf("filsDroit : %4i\n", noeudPointe->filsDroit->valeur);

    if (noeudPointe->filsGauche != NULL)
        nbNoeuds += afficheArbre(noeudPointe->filsGauche);
    if (noeudPointe->filsDroit != NULL)
        nbNoeuds += afficheArbre(noeudPointe->filsDroit);
    return nbNoeuds;
}


int estVide(struct noeud * noeudPointe) {
    struct noeud * courant;
    
    // [a completer]
}

int estFeuille(struct noeud * noeudPointe) {
    struct noeud * courant;
    
    // [a completer]
}



int rechercheValeur(struct noeud * noeudPointe, int val) {
    struct noeud * courant;
    
    // [a completer]
}



