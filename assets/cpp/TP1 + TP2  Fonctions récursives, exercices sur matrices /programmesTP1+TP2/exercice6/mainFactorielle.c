#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorielle(int n) {
    // @params : n entier
    // action : calcule factorielle(n) en iteratif
    // returns : la factorielle de n
    int i;
    int result = 1;
    for (i=1; i <= n; i++) {
        result = result* i;
    }
    return result;
}

int factorielleRecursif(int n) {
    // @params : n entier
    // action : calcule factorielle(n) en recursif
    // returns : la factorielle de n
    int i;
    int result;
    if (n ==1) {
        result = 1;
    }
    else {
        result = factorielleRecursif(n-1) * n;
    }
    return result;
}


int main() {
    int a;
    printf("calcul de factorielle(5) en iteratif : \n");
    a=factorielle(5);
    printf("factorielle(5) = %d\n",a);
    printf("calcul de factorielle(5) en recursif : \n");
    a=factorielleRecursif(5);
    printf("factorielle(5) = %d\n",a);
    
}
