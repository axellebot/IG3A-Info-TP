//
// Created by Axel LE BOT on 19/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "generationTableaux.h"
#include "algosTri.h"
#include "manipTableauxNonTries.h"
#include "modifTableauxNonTries.h"
#include "manipTableauxTries.h"
#include "modifTableauxTries.h"
#include "factorielle.h"
#include "harmonique.h"
#include "piLeibniz.h"
#include "bubbleBreaker.h"
#include "../libs/libs.h"

//Exercice 1
void exercice1(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 1");
    int tabTest[6] = {1, 1, 2, 3, 5, 8};
    int tabTest2[3] = {13, 21, 33};
    int taille1 = 20, taille2 = 20;
    int tab1[taille1];
    int tab2[taille2];

    // Test de la fonction d'affichage une fois cette derniere ecrite
    printf("Test de la fonction d'affichage\n");
    afficherTab(tabTest, 6); // doit afficher "1 1 2 3 5 8"
    afficherTab(tabTest2, 3); // doit afficher "13 21 33"

    // Test de la fonction de generation de tableau aleatoires
    printf("Test de la fonction de generation de tableaux aleatoires\n");
    remplirTabValeursAleatoires(tab1, taille1, 0, 100);
    afficherTab(tab1, taille1);

    // Test de la fonction de remplissage de tableau avec les valeurs 1 a N
    printf("Test de la fonction pour remplir le tableau de 1 a N\n");
    printf("affichage du tableau tab2 avant melange :\n");
    remplirTabValeurs1aN(tab2, taille2);
    afficherTab(tab2, taille2);

    // Test de la fonction de melange de tableau
    printf("affichage du tableau tab2 apres melange :\n");
    melangerTab(tab2, taille2, taille2 * taille2);
    afficherTab(tab2, taille2);

    //Test de la fonction somme des nombres du tableau
    printf("affichage de la somme des valeurs du tableau tab2 : %i \n", sommeElementsTab(tab2, taille2));
    afficherTab(tab2, taille2);

    //Test de la fonction moyenne des nombres du tableau
    printf("affichage de la moyenne des valeurs du tableau tab2 : %i \n", moyenneValeursTab(tab2, taille2));
    afficherTab(tab2, taille2);

    // Test de la fonction d'occurence
    printf("affichage de la présence du nombre '1' dans tab2 :\n");
    printf("Présence de '1' : %d \n", valeurContenueDansTabNonTrie(tab2, taille2, 1));
    afficherTab(tab2, taille2);

    // Test de la fonction d'occurence
    printf("affichage de l'occurence du nombre '1' dans tab2 :\n");
    printf("Occurence de '1' : %i \n", nbOccurencesValeurDansTabNonTrie(tab2, taille2, 1));
    afficherTab(tab2, taille2);
}

//Exercice 2
void exercice2(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 2");

    int tailleMax = 5;
    int tab3[tailleMax];
    int taille = 0;
    int resultat;
    int valeur = 0;

    //Test ajout de valeurs
    valeur = 4;
    printf("Test ajout de valeur : %i \n", valeur);
    resultat = ajoutValeurTabNonTrie(tab3, taille, tailleMax, valeur);
    if(resultat == 1){
        taille++;
    }
    valeur = 12;
    printf("Test ajout de valeur : %i \n", valeur);
    resultat = ajoutValeurTabNonTrie(tab3, taille, tailleMax, valeur);
    if(resultat == 1){
        taille++;
    }
    valeur = 12;
    printf("Test ajout de valeur : %i \n", valeur);
    resultat = ajoutValeurTabNonTrie(tab3, taille, tailleMax, valeur);
    if(resultat == 1){
        taille++;
    }
    valeur = 8;
    printf("Test ajout de valeur : %i \n", valeur);
    resultat = ajoutValeurTabNonTrie(tab3, taille, tailleMax, valeur);
    if(resultat == 1){
        taille++;
    }
    afficherTab(tab3, taille);

    //Test suppression valeur 4
    valeur = 4;
    printf("Test suppression valeur : %i\n", valeur);
    resultat = supprimeValeurTabNonTrie(tab3, taille, valeur);
    if(resultat == 1){
        taille--;
    }
    afficherTab(tab3, taille);

    //Test suppression de toutes les valeurs 12
    valeur = 12;
    printf("Test suppression valeurs %i\n", valeur);
    resultat = supprimeToutesLesValeursTabNonTrie(tab3, taille, 12);
    if(resultat > 0){
        taille = taille - resultat;
    }
    afficherTab(tab3, taille);
}

//Exercice 3
void exercice3(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 3");
    int taille = 20;
    printf("Test trie à bulle :\n");
    int tab[taille];
    remplirTabValeursAleatoires(tab, taille, 0, 100);
    afficherTab(tab, taille);
    triABulle(tab, taille);
    afficherTab(tab, taille);
    printf("Test trie selection :\n");
    remplirTabValeursAleatoires(tab, taille, 0, 100);
    afficherTab(tab, taille);
    triSelection(tab, taille);
    afficherTab(tab, taille);
}

//Exercice 4
void exercice4(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 4");
    int taille = 20;

    int tab[taille];
    remplirTabValeursAleatoires(tab, taille, 0, 100);

    afficherTab(tab, taille);
    printf("Test valeur contenu : \n");
    printf("valeur %i contenu dans le tableau : %d \n", 5, valeurContenueDansTabTrie(tab, taille, 5));
    printf("Test occurence: \n");
    printf("valeur %i contenu dans le tableau : %i \n", 5, nbOccurencesValeurDansTabTrie(tab, taille, 5));
}

//Exercice 5
void exercice5(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 5");
    int taille = 20;

    int tab[taille];

    remplirTabValeursAleatoires(tab, taille, 0, 100);
    triABulle(tab, taille);

    int res5 = 0;
    res5 = supprimeToutesLesValeursTabTrie(tab, taille, tab[taille - 1]);

    printf("%i", res5);
}

//Exercice 6
void exercice6(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 6");

    int value = 0;
    printf("Entrer un nombre pour les algos :");
    scanf("%d", &value);
    printf("\n");

    //Factorielle
    printf("calcul de factorielle(%d) en iteratif : \n", value);
    printf("factorielle(%d) = %d\n", value, factorielle(value));
    printf("calcul de factorielle(%d) en recursif : \n", value);
    printf("factorielle(%d) = %d\n", value, factorielleRecursif(value));

    //Harmonique
    printf("calcul de harmonique(%d) en iteratif : \n", value);
    printf("harmonique(%d) = %lf\n", value, harmonique(value));
    printf("calcul de harmonique(%d) en recursif : \n", value);
    printf("harmonique(%d) = %lf\n", value, harmoniqueRecursif(value));

    //PiLeibniz
    printf("calcul de PiLeibniz(%d) en iteratif : \n", value);
    printf("PiLeibniz(%d) = %f\n", value, PiLeibniz(value));
    printf("calcul de PiLeibniz(%d) en recursif : \n", value);
    printf("PiLeibniz(%d) = %f\n", value, PiLeibnizRecursif(value));
}

//Exercice 7
void exercice7(){
    displayHeader(HEADER_LEVEL_EXERCICE, "Exercice 7");
    int taille1 = 9, taille2 = 15;
    int M[9][15] = {
            {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1},
            {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1},
            {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0},
            {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    };

    printf("etat de la matrice avant selection de cellule:");
    afficheMatrice(taille1, taille2, M);

    // selection de la case (8,0)
    remplir(taille1, taille2, M, 8, 0);
    printf("etat de la matrice apres selection d'une cellule:");
    afficheMatrice(taille1, taille2, M);
}

int main(){
    srand(time(NULL)); // initialise le generateur de nb aleatoires

    displayHeader(HEADER_LEVEL_TP, "TP 1-2");

    bool finished = false;
    int ex = 0;
    while(!finished){
        printf("Select an exercice [1-7] : ");
        scanf("%d", &ex);
        switch(ex){
            case 1:
                exercice1();
                break;
            case 2:
                exercice2();
                break;
            case 3:
                exercice3();
                break;
            case 4:
                exercice4();
                break;
            case 5:
                exercice5();
                break;
            case 6:
                exercice6();
                break;
            case 7:
                exercice7();
                break;
            default:
                printf("404 Not found");
        }
        finished = endOfProgram();
    }

    printf("Bye !!!");
    exit(0);
}
