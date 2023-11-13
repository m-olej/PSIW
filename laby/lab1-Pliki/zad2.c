#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

    char cBuf;
    int lineLength = 0;

    for(int i = 1; i < argc; ++i){
        int fp = open(argv[i], O_RDWR);
        lseek(fp, 0, SEEK_SET);
        while(read(fp, &cBuf, 1) > 0){
            if( cBuf == '\n' ){
                lineLength++;
                // printf("found");
                char* dynArr = (char*)malloc( lineLength * sizeof(char));
                lseek(fp, -lineLength, SEEK_CUR);
                for( int j = 0; j < lineLength; ++j ){
                    read(fp, &cBuf, 1);
                    // printf("%c", &cBuf);
                    dynArr[j] = cBuf;
                };
                lseek(fp, -lineLength, SEEK_CUR);
                write(fp, " ", 1);
                for( int k = lineLength; k >= 0; --k){
                    // printf("%c", dynArr[k]);
                    write(fp, &dynArr[k], 1);
                };
                lineLength = 0;
            }else{
                lineLength++;
                // printf("%d", lineLength);
            };
        };
    };

    return 0;
};
