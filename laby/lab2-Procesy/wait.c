#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    int status;

    if( fork() == 0){
        kill(getpid(), 9);
    }else{
        wait(&status);
        printf("Status: %x \n", status);
        printf("Status: %04x \n", status);
    }
    return 0;
}
