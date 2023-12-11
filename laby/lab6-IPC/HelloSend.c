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

    strcpy(my_msg.text, "Hello");
    my_msg.type = 6;
    msgsnd(ipcId, &my_msg, strlen(my_msg.text) + 1, 0);

    return 0;
}
