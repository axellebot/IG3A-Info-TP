//
// Created by Axel LE BOT on 19/10/17.
//
#include <stdio.h>
#include <stdlib.h>
#include "modifArbres.h"

struct noeud *ajouterValeurABR(struct noeud *noeud, int val) {
    if (noeud == NULL) {
        noeud = nouveauNoeud(val);
    } else {
        if (noeud->valeur < val) {
            noeud->filsDroit = ajouterValeurABR(noeud->filsDroit, val);
        } else if (noeud->valeur > val) {
            noeud->filsGauche = ajouterValeurABR(noeud->filsGauche, val);
        }
    }
    return noeud;
}

struct noeud *supprimerValeurABR(struct noeud *racine, int val) {
    struct noeud *courant; // pointe sur le noeud a l'etude
    struct noeud *ainverser; // pointe sur le noeud dont la valeur sera a inverser
    struct noeud *precedent; // pointe vers noeud précédent, celui a supprimer

    int _val; // permet de stocker temporaire la valeur d'un noeud
    char direction;  // permet de savoir si on venait de la droite ou de la gauche à chaque iteration de la boucle

    // initialisation de parcours
    precedent = NULL;
    courant = rechercheNoeudRec(racine, val);
    if (!courant) return courant;

    // tant que le noeud a supprimer n'est pas une feuille (pas de fils), on continue la boucle
    while (!estFeuille(courant)) {

        // si on peut aller a gauche : on avance une fois gauche puis tout a droite avec un autre pointeur, et on inverse les valeurs
        // (on oublie pas qu'il nous faudra connaitre le parent du nouveau noeud)
        if (courant->filsGauche != NULL) {
            // on avance une fois a gauche
            direction = 'd';
            ainverser = courant->filsGauche;
            precedent = courant;
            // on avance tout a droite
            while (ainverser->filsDroit != NULL) {
                direction = 'g';
                precedent = ainverser;
                ainverser = ainverser->filsDroit;
            }

            // on inverse les valeurs
            _val = ainverser->valeur;
            ainverser->valeur = courant->valeur;
            courant->valeur = _val;

            // on recommencera la boucle a partir du noeud contenant la valeur a supprimer
            courant = ainverser;
        } else {  // on ne peut pas aller a gauche on va a droite
            direction = 'g';
            ainverser = courant->filsDroit;
            precedent = courant;

            // on avance tout a gauche
            while (ainverser->filsGauche != NULL) {
                direction = 'd';
                precedent = ainverser;
                ainverser = ainverser->filsGauche;
            }

            // on inverse les valeurs
            _val = ainverser->valeur;
            ainverser->valeur = courant->valeur;
            courant->valeur = _val;

            courant = ainverser;
        }
        // on recommencera la boucle a partir du noeud contenant la valeur à supprimer
    }

    // Le noeud a supprimer est une feuille, et precedent doit pointer vers le noeud parent du noeud a supprimer
    courant = NULL;
    free(courant);
    printf("Precedent NULL ? : %i\n", precedent == NULL);
    if (precedent) {
        if (direction == 'g') {
            precedent->filsDroit = NULL;
        } else {
            precedent->filsGauche = NULL;
        }
    }

    // on retourne la racine
    return racine;
}
