#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    if( fork() != 0 ){
        exit(getpid());
    }else{
        sleep(2);
        printf("PPID: %d", getppid());
        sleep(10);
    }


    return 0;
}
