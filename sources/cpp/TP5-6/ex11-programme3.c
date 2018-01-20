//
// Created by Axel LE BOT on 20/12/17.
//

int main() {
    int result1, result2, result3;
    result1 = fork();
    if (result1 == 0) {
        result2 = fork();
        if (result2 == 0) {
            result3 = fork();
            if (result3) {
                wait(NULL);
            }
            wait(NULL);
        }
        wait(NULL);
    }
}