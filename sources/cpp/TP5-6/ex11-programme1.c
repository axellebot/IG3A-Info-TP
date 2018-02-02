//
// Created by Axel LE BOT on 20/12/17.
//

#include <zconf.h>
#include <sys/wait.h>

int main() {
    int result, a = 0;
    result = fork();
    if (result) wait(NULL);
    if (result > 0)
        a = 5;
}
