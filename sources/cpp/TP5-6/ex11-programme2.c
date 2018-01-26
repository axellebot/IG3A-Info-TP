//
// Created by Axel LE BOT on 20/12/17.
//

#include <zconf.h>
#include <sys/wait.h>

int main() {
    int result1, result2, result3;
    result1 = fork();
    result2 = fork();
    result3 = fork();

    if (result3) wait(NULL);
    if (result2) wait(NULL);
    if (result1) wait(NULL);
}
