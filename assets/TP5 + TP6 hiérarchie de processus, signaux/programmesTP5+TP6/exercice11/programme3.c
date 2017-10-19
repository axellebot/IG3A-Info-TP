int main() {
    int result1, result2, result3;
    result1 = fork();
    if (result1 ==0) {
        result2 = fork();
        if (result2 == 0) {
            result3 = fork();
        }	
    }
}