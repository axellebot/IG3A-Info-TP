//
// Created by Axel LE BOT on 08/11/17.
//

void signalsHandler(int interruption) {
    printf("Signal received\n");
    switch (interruption) {
        case SIGINT:
            printf("SIGNAL SIGINT\n");
            break;
        default:
            printf("SIGNAL NOT FOUND\n");
    }
}

int main() {
    printf("Lancement du processus %i\n", getpid());
    signal(SIGINT, signalsHandler);
    while (true) {
        printf(".\n");
        sleep(1);
    }
}
