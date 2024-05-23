#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//copy contents of one file to another

int main(){

    int f1, f2;

    f1 = open("f11.txt",O_RDWR);
    f2 = open("f12.txt",O_RDWR|O_CREAT |O_TRUNC);
    char buffer[80];
    //read using read(fd, buffer, size); from f1 to buffer
    while (read(f1, buffer, 80) > 0){
        //write using write(fd, buffer, size); from buffer to f2
        write(f2, buffer, 80);
    }
    //check if read reached end of file 
    
}