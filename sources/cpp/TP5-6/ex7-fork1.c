//
// Created by Axel LE BOT on 20/12/17.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int result;
    result = fork();

    if (result == 0) {
        int pid;
        pid = getpid();
        int ppid;
        ppid = getppid();
        printf("Je suis le fils : %d et mon parent est %d \n", pid, ppid);
    } else {
        int pid;
        pid = getpid();
        int ppid;
        ppid = getppid();
        printf("Je suis le parent : %d et mon parent est %d \n", pid, ppid);
    }
    wait(NULL);
}