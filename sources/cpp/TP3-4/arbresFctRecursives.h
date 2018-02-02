//
// Created by Axel LE BOT on 19/10/17.
//

#ifndef TP_CPP_ARBRES_FCT_RECURSIVES_H
#define TP_CPP_ARBRES_FCT_RECURSIVES_H

#include "arbresBasiques.h"

// prototype des fonctions a mettre en place (ne pas modifier)

int max(int a, int b);

int nbNoeuds(struct noeud *noeudCourant);

int sommeValArbres(struct noeud *noeudCourant);

int hauteur(struct noeud *noeudCourant);

void detruireArbre(struct noeud *noeudRacine);

int rechercheValeurRec(struct noeud *noeudCourant, int val);

struct noeud *rechercheNoeudRec(struct noeud *noeudCourant, int val);

#endif
