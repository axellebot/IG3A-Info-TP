//
// Created by Axel LE BOT on 08/11/17.
//

#include <stdio.h>
#include <zconf.h>

int main() {
    printf("Lancement du processus %i\n", getpid());
    while (1) {
        printf(".\n");
        sleep(1);
    }
}
