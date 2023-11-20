#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <ctype.h>
int main(){

    int fd[2];
    pipe( fd );
    char buf[20];

    if (fork() == 0){
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls", "ls", "-a", NULL);
    }else
    {
        close(fd[1]);
        dup2(fd[0],0);
        while(read(fd[0], buf, 1)){
            printf("%c", toupper(buf[0]));
        }
    }

    return 0;
}
