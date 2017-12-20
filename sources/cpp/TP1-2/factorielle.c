//
// Created by Axel LE BOT on 11/12/17.
//

#include "factorielle.h"

int factorielle(int n) {
    int i;
    int result = 1;
    for (i=1; i <= n; i++) {
        result = result* i;
    }
    return result;
}

int factorielleRecursif(int n) {
    int result;
    if (n ==1) result = 1;
    else result = factorielleRecursif(n-1) * n;
    return result;
}