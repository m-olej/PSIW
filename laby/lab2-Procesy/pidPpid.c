#include <stdio.h>
#include <unistd.h>

int main() {

    if( fork() == 0){
        printf("Proces potomny PID: %d, PPID: %d \n", getpid(), getppid());
    }else{
        printf("Proces macierzysty PID: %d, PPID: %d \n", getpid(), getppid());
    }
    return 0;
}
