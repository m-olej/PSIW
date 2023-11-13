#include <stdio.h>
#include <unistd.h>

int main(){

    // \n oproznia buffor. Proces potomny dostaje kazda zmienna rowniez zawartosc buffora
    printf("Poczatek");
    fork();
    printf("Koniec \n");
    return 0;
};
