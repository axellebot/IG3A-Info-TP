#include <stdio.h>
#include <stdlib.h>

#include "arbresBasiques.h"

struct noeud *nouveauNoeud(int val) {
    // @params : val : valeur du nouveau noeud a creer
    // @result : retourne un pointeur sur le noeud nouvellement cree
    //            Les fils droits et gauche sont initialises a null

    struct noeud *noeudRetour;

    // reservation d'un espace memoire dans le tas

    noeudRetour = (struct noeud *) malloc(sizeof(struct noeud));

    // affectation des valeurs si l'allocation memoire reussit
    if (noeudRetour != NULL) {
        noeudRetour->valeur = val;
        noeudRetour->filsGauche = NULL;
        noeudRetour->filsDroit = NULL;
    } else {
        printf("erreur : plus de memoire (gros probleme!)\n");
        exit(1);
    }
    //renvoi du pointeur vers le noeud nouvellement cree
    return noeudRetour;
}


struct noeud *unArbrePredefini() {
    // action : definit en memoire l'arbre de l'enonce
    // result : un pointeur vers la racine de cet arbre
    // fonction a ne pas modifier, ne fonctionnera que si nouveauNoeud est faite
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
        printf("filsDroit : vide\n");
    else
        printf("filsDroit : %4i\n", noeudPointe->filsDroit->valeur);

    if (noeudPointe->filsGauche != NULL)
        nbNoeuds += afficheArbre(noeudPointe->filsGauche);
    if (noeudPointe->filsDroit != NULL)
        nbNoeuds += afficheArbre(noeudPointe->filsDroit);
    return nbNoeuds;
}


int estVide(struct noeud *noeudPointe) {
    struct noeud *courant;
    int vide;

    if (courant == NULL) {
        vide = 1;
    } else { vide = 0; }

    return vide;
}

int estFeuille(struct noeud *noeudPointe) {
    struct noeud *courant;
    int feuille;

    if ((courant != NULL) && (courant->filsGauche == NULL) && (courant->filsDroit == NULL)) {
        feuille = 1;
    } else { feuille = 0; }

    return feuille;
}


int rechercheValeur(struct noeud *noeudPointe, int val) {
    struct noeud *courant;
    int trouve;
    //renvoie 1 si la valeur val est contenue dans l'arbre, 0 sinon

    struct noeud *parcours = courant;
    if (parcours != NULL) {
        trouve = 0;
    } else {
        if (parcours->valeur == val) {
            trouve = 1;
        } else {
            if (parcours->valeur > courant->valeur) {
                parcours = parcours->filsDroit;
            } else if (parcours->valeur < courant->valeur) {
                parcours = parcours->filsGauche;
            }
        }
    }

    return trouve;
}



