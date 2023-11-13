#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    if(fork() == 0){
        exit(getpid());
    }else{
        if( fork() == 0){
            exit(getpid());
        }else{
            if( fork() == 0){
                exit(getpid());
            }else{
            printf("Zombi chodza na okolo~!");
            sleep(10);
            };
        };
    };
};
