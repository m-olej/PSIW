#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    printf("Begin \n");

    if(fork() == 0){
        execl("/bin/ls", "ls", "-a", NULL);
    }else{
    wait(NULL);
    printf("End \n");
    }


    return 0;
}
