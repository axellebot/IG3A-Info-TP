//#include <openssl/rand.h>
#include <stdio.h>
#include "generationTableaux.h"


// declaration des prototypes de fonctions qui seront
// utilisees dans la suite de ce programme
// (cette partie ne doit pas etre modifiee)
int nbAleatoire(int min, int max);
void afficherTab(int tab[], int taille);
void remplirTabValeursAleatoires(int tab[], int taille, int min, int max);
void remplirTabValeurs1aN(int tab[], int taille);
void melangerTab(int tab[], int taille, int nb);
// fin de declaration des prototypes de fonctions

// definition des fonctions

int nbAleatoire(int min, int max) {
    // @params : deux nombres
    // @retour : une valeur aleatoire comprise entre ces deux nombres
 
    // [a completer] ajouter code de la fonction nbAleatoire()
}

void afficherTab(int tab[], int taille) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    // @action : affiche le tableau a l'ecran
 
    // [a completer] ajouter boucle pour afficher le tableau
}

void remplirTabValeursAleatoires(int tab[], int taille, int min, int max) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           min et max : deux entiers donnes avec min < max
    // @action : remplit le tableau avec les valeurs aleatoires tirees entre
    //           les valeurs min et max
    
    
    // [a completer] ajouter boucle pour remplir le tableau
}

void remplirTabValeurs1aN(int tab[], int taille) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    // @action : remplit le tableau avec les valeurs 1, 2, 3 ... N
    
    // [a completer] ajouter boucle pour remplir le tableau

    
}

void melangerTab(int tab[], int taille, int nb) {
    // @params : tab : tableau d'entiers, taille :taille du tableau
    //           nb : nombre d'inversions a faire
    // @action : inverse nb fois deux valeurs aleatoires du tableau

    // [a completer] ajouter boucle pour remplir le tableau
}

