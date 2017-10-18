#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generationTableaux.h"
#include "manipTableauxNonTries.h"
#include "modifTableauxNonTries.h"
#include "algosTri.h"
#include "manipTableauxTries.h"

#define TAILLE1 20
#define TAILLE2 30
#define TAILLEMAX 5


void displayHeaderExercice(int number){
    printf("\n-----------Exercice %d-----------\n",number);
}

int main() {

    int tab1[TAILLE1];
    int tab2[TAILLE2];
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
    
    //Test de la fonction somme des nombres du tableau
    printf("affichage de la somme des valeurs du tableau tab2 : %i \n",sommeElementsTab(tab2,TAILLE2));
    afficherTab(tab2, TAILLE2);

    //Test de la fonction moyenne des nombres du tableau
    printf("affichage de la moyenne des valeurs du tableau tab2 : %i \n",moyenneValeursTab(tab2,TAILLE2));
    afficherTab(tab2, TAILLE2);

    // Test de la fonction d'occurence
    printf("affichage de la présence du nombre '1' dans tab2 :\n");
    printf("Présence de '1' : %d \n",valeurContenueDansTabNonTrie(tab2,TAILLE2,1));
    afficherTab(tab2,TAILLE2);

    // Test de la fonction d'occurence
    printf("affichage de l'occurence du nombre '1' dans tab2 :\n");
    printf("Occurence de '1' : %i \n",nbOccurencesValeurDansTabNonTrie(tab2,TAILLE2,1));
    afficherTab(tab2,TAILLE2);

    //Exercice 2
    displayHeaderExercice(2);

    int tab3[TAILLEMAX];
    int taille =0;
    int resultat;
    int valeur=0;

    //Test ajout de valeurs
    valeur =4;
    printf("Test ajout de valeur : %i \n",valeur);
    resultat = ajoutValeurTabNonTrie(tab3,taille,TAILLEMAX,valeur);
    if(resultat ==1){
        taille++;
    }
    valeur =12;
    printf("Test ajout de valeur : %i \n",valeur);
    resultat = ajoutValeurTabNonTrie(tab3,taille,TAILLEMAX,valeur);
    if(resultat ==1){
        taille++;
    }
    valeur =12;
    printf("Test ajout de valeur : %i \n",valeur);
    resultat = ajoutValeurTabNonTrie(tab3,taille,TAILLEMAX,valeur);
    if(resultat ==1){
        taille++;
    }
    valeur =8;
    printf("Test ajout de valeur : %i \n",valeur);
    resultat = ajoutValeurTabNonTrie(tab3,taille,TAILLEMAX,valeur);
    if(resultat ==1){
        taille++;
    }
    afficherTab(tab3,taille);

    //Test suppression valeur 4
    valeur = 4;
    printf("Test suppression valeur : %i\n",valeur);
    resultat = supprimeValeurTabNonTrie(tab3,taille,valeur);
    if(resultat==1){
        taille --;
    }
    afficherTab(tab3,taille);

    //Test suppression de toutes les valeurs 12
    valeur = 12;
    printf("Test suppression valeurs %i\n",valeur);
    resultat = supprimeToutesLesValeursTabNonTrie(tab3,taille,12);
    if(resultat >0){
        taille=taille-resultat;
    }
    afficherTab(tab3,taille);

    //Exercice 3
    displayHeaderExercice(3);
    printf("Test trie à bulle : %d\n",valeur);
    int tab4[TAILLE1];
    remplirTabValeursAleatoires(tab4, TAILLE1,0, 100);
    afficherTab(tab4,TAILLE1);
    triABulle(tab4,TAILLE1);
    afficherTab(tab4,TAILLE1);
    printf("Test trie selection : %d \n",valeur);
    remplirTabValeursAleatoires(tab4, TAILLE1,0, 100);
    afficherTab(tab4,TAILLE1);
    triSelection(tab4,TAILLE1);
    afficherTab(tab4,TAILLE1);

    //Exercice 4
    displayHeaderExercice(4);
    afficherTab(tab4,TAILLE1);
    printf("Test valeur contenu : \n");
    printf("valeur %i contenu dans le tableau : %d \n",5,valeurContenueDansTabTrie(tab4,TAILLE1,5));
    printf("Test occurence: \n");
    printf("valeur %i contenu dans le tableau : %i \n",5,nbOccurencesValeurDansTabTrie(tab4,TAILLE1,5));

    exit(0);
}
