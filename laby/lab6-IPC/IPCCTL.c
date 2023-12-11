#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char* argv[]){

    msgctl(0x513807b8, IPC_RMID, NULL);

    return 0;
}
