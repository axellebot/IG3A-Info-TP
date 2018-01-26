//
// Created by Axel LE BOT on 20/12/17.
//

#include <zconf.h>

int main(){
    if(fork() > 0){
        fork();
    }
}