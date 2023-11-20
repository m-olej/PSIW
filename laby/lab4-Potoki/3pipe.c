#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(){
    int pd1[2];
    pipe(pd1);

    if(fork() == 0){
        close(pd1[0]);
        dup2(pd1[1], 1);
        execlp("ps", "ps", "-ef", NULL);
    }else{
        int pd2[2];
        pipe(pd2);
        if(fork() == 0){
            close(pd1[1]);
            close(pd2[0]);
            dup2(pd1[0], 0);
            dup2(pd2[1],1);
            execlp("tr", "tr", "-s", " ", " :", NULL);

        }else{
            close(pd1[0]);
            close(pd1[1]);
            int pd3[2];
            pipe(pd3);
            if( fork() == 0){
            close(pd2[1]);
            close(pd3[0]);
                dup2(pd2[0],0);
                dup2(pd3[1],1);
                execlp("cut", "cut", "-d", ":", "-f1", NULL);
            }else{
                close(pd2[1]);
                close(pd2[0]);
                int pd4[2];
                pipe(pd4);
                if(fork() == 0){

            close(pd3[1]);
            close(pd4[0]);
                    dup2(pd3[0],0);
                    dup2(pd4[1],1);
                    execlp("sort", "sort", NULL);
                }else{
                    close(pd3[1]);
                    close(pd3[0]);
                    int pd5[2];
                    pipe(pd5);
                    if( fork() == 0){

            close(pd4[1]);
            close(pd5[0]);
                        dup2(pd4[0],0);
                        dup2(pd5[1],1);
                        execlp("uniq", "uniq", "-c", NULL);
                    }else{
                        close(pd4[1]);
                        close(pd4[0]);
                        if(fork() == 0){
            close(pd5[1]);
                            dup2(pd5[0],0);
                            execlp("sort", "sort", "-n", NULL);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
