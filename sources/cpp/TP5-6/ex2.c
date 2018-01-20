//
// Created by Axel LE BOT on 08/11/17.
//

void signalsHandler(int interruption) {
    printf("Signal received\n");
    switch (interruption) {
        case SIGINT:
            printf("SIGNAL SIGINT\n");
            break;
        case SIGUSR1 :
            printf("SIGNAL SIGUSR1\n");
            break;
        default:
            printf("SIGNAL NOT FOUND\n");
    }
}

int main() {
    signal(SIGINT, signalsHandler);
    signal(SIGUSR1, signalsHandler);

    while (true) {
        sleep(1);
        printf(".\n");
    }
}
