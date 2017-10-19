#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double PiLeibniz(int n) {
    // @params : n entier
    // action : calcule PiLeibniz(n) en iteratif
    // returns : le nombre Pi via la formule de Leibniz de n

    // [a completer] code de la fonction PiLeibniz
}

double PiLeibnizRecursif(int n) {
    // @params : n entier
    // action : calcule PiLeibniz(n) en recursif
    // returns : le nombre Pi via la formule de Leibniz de n

    // [a completer] code de la fonction PiLeibnizRecursif
}


int main() {
    double a;
    printf("calcul de PiLeibniz(5) en iteratif : \n");
    a=PiLeibniz(5);
    printf("PiLeibniz(5) = %f\n",a);
    printf("calcul de PiLeibniz(5) en recursif : \n");
    a=PiLeibnizRecursif(5);
    printf("PiLeibniz(5) = %f\n",a);
    
}