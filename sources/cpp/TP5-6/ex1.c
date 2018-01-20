//
// Created by Axel LE BOT on 08/11/17.
//

int main() {
    printf("Lancement du processus %i\n", getpid());
    while (true) {
        sleep(1);
        printf(".\n");
    }
}