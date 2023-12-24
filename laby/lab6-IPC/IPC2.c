#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char* argv[]){

    int ipcId = msgget(0x666, 0666 | IPC_CREAT);

    // constant implementation

    struct msgbuf{
        long type;
        char msgText[50];
        int typeInt;
    };
    if(fork() == 0){
        for(int i = 0; i < 9; ++i){
            struct msgbuf try;
            try.type = i + 1;
            try.typeInt = i + 1;
            strcpy(try.msgText, "Message Text");
            msgsnd(ipcId, &try, strlen(try.msgText) + 1 + sizeof(int), 0);
        }
    }else{
        for(int j = 0; j < 9; ++j){
        struct msgbuf rcv_msg;
        msgrcv(ipcId, &rcv_msg, 50 + sizeof(int), j+1, 0);
        printf("Wiadomosc: %s, typ: %d\n", rcv_msg.msgText, rcv_msg.typeInt);
        }
    }

    return 0;
}
