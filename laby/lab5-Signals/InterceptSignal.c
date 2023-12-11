#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// signal handler

void sighdl(int sigcode){
    printf("Received signal: %d \n", sigcode);
    if(sigcode == 2){
        raise(9);
    }
    return;
}

int main(){

    for(int i=1; i<32; ++i){
        signal(i, sighdl);
    }

    while(1){

    }
    return 0;
}

