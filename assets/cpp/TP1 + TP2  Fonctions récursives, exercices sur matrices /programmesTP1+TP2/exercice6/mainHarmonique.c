#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double harmonique(int n) {
    // @params : n entier
    // action : calcule harmonique(n) en iteratif
    // returns : le nombre harmonique de n

    // [a completer] code de la fonction Harmonique
}

double harmoniqueRecursif(int n) {
    // @params : n entier
    // action : calcule harmonique(n) en recursif
    // returns : le nombre harmonique de n

    // [a completer] code de la fonction HarmoniqueRecursif
}


int main() {
    double a;
    printf("calcul de harmonique(5) en iteratif : \n");
    a=harmonique(5);
    printf("harmonique(5) = %f\n",a);
    printf("calcul de harmonique(5) en recursif : \n");
    a=harmoniqueRecursif(5);
    printf("harmonique(5) = %f\n",a);
    
}