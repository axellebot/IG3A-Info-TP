//
// Created by Axel LE BOT on 20/12/17.
//

int main(){
    int counter = 0;
    while(counter < 3){
        if(fork() > 0)
            counter++;
        else
            counter = 3;
    }
}