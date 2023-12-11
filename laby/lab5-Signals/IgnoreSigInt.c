#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    signal(SIGINT, SIG_IGN);

    printf("You can't stop me !!!\n");
    for(int i=1; i <= 10; ++i){
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}
