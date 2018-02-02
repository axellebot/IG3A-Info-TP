//
// Created by Axel LE BOT on 17/11/17.
//

#include "libs.h"
#include <stdio.h>

void displayHeader(int level, char *string){
    switch(level){
        case 1:
            printf("\n////////////////////////////////////\n///////////////  %s ///////////////\n////////////////////////////////////\n",
                   string);
            break;
        case 2 :
        default:
            printf("\n----------- %s-----------\n", string);
            break;
    }
}

bool endOfProgram(){
    char s;
    printf("\nStop ? [Y/n] : ");
    scanf("%s", &s);
    return !(s == 'N' || s == 'n');
}
