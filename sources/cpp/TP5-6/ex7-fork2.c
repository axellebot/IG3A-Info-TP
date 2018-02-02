//
// Created by Axel LE BOT on 20/12/17.
//

#include <stdio.h>
#include <zconf.h>
#include <sys/wait.h>

int main() {
    int result1, result2;
    result1 = fork();
    int pid, ppid;
    if (result1 == 0) {
        pid = getpid();
        ppid = getppid();
        printf("Je suis le parent : %d et mon parent est %d \n", pid, ppid);
        result2 = fork();

        if (result2 == 0) {
            pid = getpid();
            ppid = getppid();
            printf("Je suis le fils : %d et mon parent est %d \n", pid, ppid);
        }
    } else {
        pid = getpid();
        ppid = getppid();
        printf("Je suis le grand-parent : %d et mon parent est %d \n", pid, ppid);
    }
    wait(NULL);
}
