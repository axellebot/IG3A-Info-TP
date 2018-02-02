//
// Created by axel on 26/01/18.
//

#include <stdio.h>
#include <zconf.h>

int main() {
    int val = 0;
    scanf("%i", &val);

    int result;
    if ((val == 1) || (val == 2)) {
        result = fork();
        if (result == 0) {
            if (val == 1) {
                execve("/bin/hostname", "hostname", NULL);
            } else {
                execve("/bin/date", "date", NULL);
            }
        }
    }
}