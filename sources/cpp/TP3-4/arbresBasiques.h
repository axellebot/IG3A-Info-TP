#ifndef TP_CPP_ARBRES_BASIQUES_H
#define TP_CPP_ARBRES_BASIQUES_H

// definition de la structure contenant un noeud
struct noeud{
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
