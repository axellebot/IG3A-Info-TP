#ifndef _arbresBasiques_h
#define _arbresBasiques_h

// definition de la structure contenant un noeud
struct noeud {
    int valeur;
    struct noeud *filsGauche;
    struct noeud *filsDroit;
};

// prototype des fonctions a mettre en place (ne pas modifier)

struct noeud *unArbrePredefini();

struct noeud *nouveauNoeud(int val);

int afficheArbre(struct noeud *noeudPointe);

int estVide(struct noeud *noeudPointe);

int estFeuille(struct noeud *noeudPointe);

int rechercheValeur(struct noeud *noeudPointe, int val);

#endif
