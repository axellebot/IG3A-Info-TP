//
// Created by Axel LE BOT on 20/01/18.
//

#include <stdio.h>
#include "parcoursArbres.h"

void parcoursProfondeur(struct noeud *racine) {
    // sinon, on affiche son sous-arbre gauche, puis la valeur du noeud
    // puis son sous-arbre droit
    // si le noeud racine est NULL, on ne fait rien
    if (!estVide(racine)) {
        if (racine->filsGauche != NULL) {
            parcoursProfondeur(racine->filsGauche);
        }
        printf("%i", racine->valeur);
        if (racine->filsDroit != NULL) {
            parcoursProfondeur(racine->filsDroit);
        }
    }
}
