#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char* argv[]){

    struct timeval time1;
    struct timeval time2;


    int runtime_s, runtime_usec;

    gettimeofday(&time1, NULL);
    if ( fork() == 0 ){
        execvp(argv[1], argv+1);
    }else{
    wait(NULL);
    gettimeofday(&time2, NULL);
    runtime_s = time2.tv_sec - time1.tv_sec;
    runtime_usec = time2.tv_usec - time1.tv_usec;
    printf("Runtime of %s: %d seconds and %d microseconds\n", argv[1], runtime_s, runtime_usec);
    }


    return 0;
}
