#include <stdio.h>
#include <unistd.h>

int main(){

    int pd[2];
    // pd[0] - odczyt z potoku
    // pd[1] - zapis do potoku
    pipe(pd);

    char buf[15]="";

    if( fork() == 0){
        if( fork() == 0){

        }
        write(pd[1], "Hello World~!", 13);
    }else{
        read(pd[0], buf, 13);
    }
    printf("%s \n", buf);
    return 0;
}
