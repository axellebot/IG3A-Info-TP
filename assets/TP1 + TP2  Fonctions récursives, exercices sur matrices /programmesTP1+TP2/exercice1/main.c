#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generationTableaux.h"
// ligne suivante a decommenter plus tard
// #include "manipTableauxNonTries.h"

#define TAILLE1 20
#define TAILLE2 30


int main() {

    int tab1[TAILLE1];
    int tab2[TAILLE2];
    int compteur;
    int tabTest[6] = {1, 1, 2, 3, 5, 8};
    int tabTest2[3] = {13, 21, 33};
    
    srand(time(NULL)); // initialise le generateur de nb aleatoires
    
    // Test de la fonction d'affichage une fois cette derniere ecrite
    printf("Test de la fonction d'affichage\n");
    afficherTab(tabTest, 6); // doit afficher "1 1 2 3 5 8"
    afficherTab(tabTest2, 3); // doit afficher "13 21 33"
    
    // Test de la fonction de generation de tableau aleatoires
    printf("Test de la fonction de generation de tableaux aleatoires\n");
    remplirTabValeursAleatoires(tab1, TAILLE1,0, 100);
    afficherTab(tab1, TAILLE1);

    // Test de la fonction de remplissage de tableau avec les valeurs 1 a N
    printf("Test de la fonction pour remplir le tableau de 1 a N\n");
    printf("affichage du tableau tab2 avant melange :\n");
    remplirTabValeurs1aN(tab2, TAILLE2);
    afficherTab(tab2, TAILLE2);
    
    // Test de la fonction de melange de tableau
    printf("affichage du tableau tab2 apres melange :\n");
    melangerTab(tab2, TAILLE2, TAILLE2*TAILLE2);
    afficherTab(tab2, TAILLE2);
    
	exit(0);
}
