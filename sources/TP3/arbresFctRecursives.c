#include <stdio.h>
#include <stdlib.h>

#include "arbresBasiques.h"
#include "arbresFctRecursives.h"

int max(int a, int b) {
    // params : a , b deux entiers
    // return : la valeur maximale entre a et b
    // fonction a ne pas modifier, a utiliser pour hauteur()
    if (a > b ) return  a;
    return b;
}

int nbNoeuds(struct noeud *noeudCourant) {
    int nb;

    if(noeudCourant == NULL){
        nb = 0;
    }else{
        nb = 1 + nbNoeuds(noeudCourant->filsGauche) + nbNoeuds(noeudCourant->filsDroit);
    }

    return nb;
}

int sommeValArbres(struct noeud *noeudCourant) {
    int somme;

    if(noeudCourant == NULL){
        somme = 0;
    }else{
        somme = noeudCourant->valeur + sommeValArbres(noeudCourant->filsGauche) + sommeValArbres(noeudCourant->filsDroit);
    }
    
    return somme;
}

int hauteur(struct noeud *noeudCourant) {
    int h;

    if(noeudCourant == NULL){
        h = 0;
    }else{
        h = 1 + max(hauteur(noeudCourant->filsGauche), hauteur(noeudCourant->filsDroit));
    }

    return h;
}

int detruireArbre(struct noeud *noeudRacine){

    detruireArbre(noeudRacine->filsGauche);
    detruireArbre(noeudRacine->filsDroit);
    free(noeudRacine->filsGauche);
    free(noeudRacine->filsDroit);
    free(noeudRacine);

    return 0;

}
