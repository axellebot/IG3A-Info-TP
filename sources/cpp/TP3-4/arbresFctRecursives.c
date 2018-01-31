//
// Created by Axel LE BOT on 19/10/17.
//

#include <stdlib.h>
#include "arbresFctRecursives.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int nbNoeuds(struct noeud *noeudCourant) {
    return estVide(noeudCourant) ? 0 : 1 +
                                       nbNoeuds(noeudCourant->filsGauche) +
                                       nbNoeuds(noeudCourant->filsDroit);
}

int sommeValArbres(struct noeud *noeudCourant) {
    return estVide(noeudCourant) ? 0 : noeudCourant->valeur +
                                       sommeValArbres(noeudCourant->filsGauche) +
                                       sommeValArbres(noeudCourant->filsDroit);
}

int hauteur(struct noeud *noeudCourant) {
    return estVide(noeudCourant) ? 0 : 1 +
                                       max(hauteur(noeudCourant->filsGauche),
                                           hauteur(noeudCourant->filsDroit));
}

void detruireArbre(struct noeud *noeudRacine) {
    if (!estVide(noeudRacine)) {
        detruireArbre(noeudRacine->filsGauche);
        detruireArbre(noeudRacine->filsDroit);
        free(noeudRacine);
    }
}

int rechercheValeurRec(struct noeud *noeudCourant, int val) {
    return !estVide(noeudCourant) && (noeudCourant->valeur == val ||
                                      rechercheValeur(noeudCourant->filsGauche, val) ||
                                      rechercheValeur(noeudCourant->filsDroit, val));
}

struct noeud *rechercheNoeudRec(struct noeud *noeudCourant, int val) {
    if (rechercheValeurRec(noeudCourant, val)) {
        if (noeudCourant->valeur == val) {
            return noeudCourant;
        } else {
            struct noeud *noeudTrouve = rechercheNoeudRec(noeudCourant->filsGauche, val);
            if (noeudTrouve == NULL) {
                noeudTrouve = rechercheNoeudRec(noeudCourant->filsDroit, val);
            }
            return noeudTrouve;
        }
    }
    return NULL;
}