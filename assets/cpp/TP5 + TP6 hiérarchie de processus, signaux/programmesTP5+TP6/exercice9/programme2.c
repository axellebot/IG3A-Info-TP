int main() {
    if (fork() > 0) {
        fork();
    }
}