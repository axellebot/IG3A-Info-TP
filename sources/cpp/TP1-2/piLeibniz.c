//
// Created by Axel LE BOT on 11/12/17.
//

#include <math.h>

double PiLeibniz(int n){
    int i;
    double result = 4 / 1;
    for(i = 1; i <= n; i++){
        result = result + (pow(-1, i)) / ((2 * i) + 1);
    }
    return result;
}

double PiLeibnizRecursif(int n){
    double result;
    return (n == 1) ? 1 : PiLeibniz(n - 1) + (pow(-1, n)) / ((2 * n) + 1);
}
