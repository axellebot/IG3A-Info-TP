//
// Created by Axel LE BOT on 11/12/17.
//

#include "harmonique.h"

double harmonique(int n) {
    int i;
    int result = 1;
    for (i = 1; i <= n; i++) {
        result = result + (1 / i);
    }
    return result;
}

double harmoniqueRecursif(int n) {
    int result;
    if (n == 1) result = 1;
    else result = harmoniqueRecursif(n - 1) + (1 / n);
    return result;
}