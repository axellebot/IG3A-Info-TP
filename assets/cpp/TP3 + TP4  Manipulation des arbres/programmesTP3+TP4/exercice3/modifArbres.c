#include <stdio.h>
#include <stdlib.h>
#include "arbresbasiques.h"
#include "modifarbres.h"

struct noeud * ajouterValeurABR(struct noeud * racine, int val){
    // @action : ajoute la valeur val a l'arbre.
    // @return : un pointeur sur la racine (peut avoir change!)
    struct noeud * parcours; // pointe sur le noeud a l'etude
    struct noeud * suivant; // pointe vers le prochain noeud a etudier
    struct noeud * ptrRetour; // pour retourner l'adresse de la racine de l'arbre
    struct noeud * nouveau; // pour retourner l'adresse du nouveau noeud
    
    // initialisation de parcours
    parcours = racine;
    //  *** cas particulier ou l'arbre est vide (racine= null) ***
    // que faire alors ?
    if (racine == NULL) {

        // [a completer]
    }
    
    //  *** recherche de l'emplacement ou mettre la valeur a ajouter ***

    // parcours est le noeud qui sera parent du nouveau noeud a inserer
    // mise a jour de suivant

    
    // [a completer]
    
    
    // *** insertion de la valeur ***
    // creation du nouveau noeud qui va contenir la valeur

    
    // [a completer]
    
}


struct noeud * supprimerValeurABR(struct noeud * racine, int val){
    // @action : supprime la valeur val a l'arbre.
    // @return : un pointeur sur la racine (peut avoir change!)
    struct noeud * courant; // pointe sur le noeud a l'etude
    struct noeud * ainverser; // pointe sur le noeud a dont la valeur sera a inverser
    struct noeud * precedent; // pointe vers noeud precedent celui a supprimer
    struct noeud * ptrRetour; // pour retourner l'adresse de la racine de l'arbre
    int temp;
    char direction ;  // a chaque fois que l'on avance, permet de savoir si on venait de la droite ou de la gauche
    
    // initialisation de parcours
    precedent = NULL;
    courant = racine;
    
    // d'abord on repere si la valeur a supprimer existe
    // on avance courant jusqu'a ce qu'il pointe sur le neoud contenant la valeur a supprimer
    while (courant != NULL && courant->valeur != val) {
        /* [a completer] */

    }
    // si elle n'existe pas :
    if (courant == NULL) {
        printf("valeur inexistante\n");
        return racine;
    }
    
    // cas particulier : la racine doit etre supprimee et n'a pas de fils
    // l'arbre deviendra vide apres suppression
    
    if (/* [a completer] */) {
        free(racine);
        racine = NULL;
        return racine;
    }
    
    // *** algorithme general *** //
    // si le noeud n contenant la valeur a supprimer est trouvee :
    // on regarde s'il a un fils gauche :
    // si oui : on va à gauche 1 fois, puis tout a droite
    //    et on inverse la valeur de ce noeud m avec la valeur du noeud n.
    //     et on recommence l'algorithme à partir de m
    //Sinon :
    // on regarde s"il a un fils droit :
    //  si oui : on va à droite 1 fois, puis tout a gauche
    //    et on inverse la valeur de ce noeud m avec la valeur du noeud n.
    //     et on recommence l'algorithme à partir de m
    //   s'il n'a ni fils droit ni fils gauche, c'est une feuille. A supprimer et mettre à jour l'endroit d'ou on venait à NULL
    // (on peut donc boucler tant que le noeud pointant la valeur a supprimer n'est pas une feuille
    // l'arbre binaire reste "de recherche", a une valeur pres (celle a supprimer)
    // *** fin algorithme general *** //
    
    // ** mise en oeuvre **//
    //tant que le noeud a supprimer a des fils, on avance selon l'algorithme
    
    while ( /* [a completer] */ ) {
        
        // si on peut aller a gauche : on avance une fois gauche puis tout a droite avec un autre pointeur, et on inverse les valeurs
        // (on oublie pas qu'il nous faudra connaitre le parent du nouveau noeud)
        if (courant->filsGauche != NULL) {
            // on avance une fois a gauche
            direction = /* [a completer] */;
            ainverser = /* [a completer] */;
            precedent = /* [a completer] */;
            // on avance tout a droite
            while (ainverser->filsDroit != NULL) {
                direction = /* [a completer] */;
                precedent = /* [a completer] */;
                ainverser = /* [a completer] */;
            }
            // on inverse les valeurs
           
            /* [a completer] */
            
            // on recommencera la boucle a partir du noeud contenant la valeur a supprimer
            courant = /* [a completer] */;
            //
        }
        else
            // on ne pouvait pas aller a gauche. On doit pouvoir aller a droite
        {           // on avance une fois a droite
            direction = /* [a completer] */;
            ainverser = /* [a completer] */;
            precedent = /* [a completer] */;
            // on avance tout a gauche
            while (ainverser->filsGauche != NULL) {
                direction = /* [a completer] */;
                precedent = /* [a completer] */;
                ainverser = /* [a completer] */;
            }
            // on inverse les valeurs
            
            /* [a completer] */
            
            // on recommencera la boucle a partir du noeud contenant la valeur a supprimer
            courant = /* [a completer] */;
            //

        }
    }
    
    
    // on est au bout. Le noeud a supprimer est une feuille, et precedent doit pointer vers le noeud parent du noeud a supprimer
    if (direction == /* [a completer] */ ) {
            /* [a completer] */
    }
    else {
            /* [a completer] */
    }
    
    // on retourne la racine
    return racine;
}


