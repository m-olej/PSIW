#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
int main(){

    int fd[2];
    pipe( fd );

    if (fork() == 0){
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls", "ls", "-a", NULL);
    }else
    {
        close(fd[1]);
        dup2(fd[0],0);
        execlp("wc", "wc", NULL);
    }
        printf("%d", fd[0]);

    return 0;
}
