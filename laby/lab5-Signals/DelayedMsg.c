#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]){

    int time = atoi(argv[1]);

    printf("Check: %d", time);
    if(fork() == 0){
        sleept(time);
        printf("This is THE message\n");
        kill(getppid(), 9);
    }


    return 0;
}
