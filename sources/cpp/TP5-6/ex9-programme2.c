//
// Created by Axel LE BOT on 20/12/17.
//

int main(){
    if(fork() > 0){
        fork();
    }
}