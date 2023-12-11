#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char* argv[]){

    int ipcId = msgget(0x123, 0600 | IPC_CREAT);

    struct msgbuf {
        long type;
        char text[1024];
    } my_msg;

    msgrcv(ipcId, &my_msg, 1024, 5, 0);
    printf("%s", my_msg.text);
    return 0;
}
