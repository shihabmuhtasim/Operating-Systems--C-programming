#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
//include fd library
#include <fcntl.h>

int main()
{

int a,b,c,d=-1;

a = fork();
b = fork();
c = fork();
int count=8;
//initialize a file descriptor system call
int fd=open("file.txt",O_CREAT|O_RDWR,O_TRUNC);
//check if the file descriptor is valid
if(fd==-1){
    printf("File descriptor is invalid");
    exit(1);
}

if (a > 0 && b>0 && c>0){
    if (a%2!=0){
        count ++;
        d=fork();
        printf("A entered\n");
        //write to the file - count: count
        
    }

    if (b%2!=0){
        count ++;
        printf("B entered\n");
        d=fork();
        
        
    }

    if (c%2!=0){
        count ++;
        printf("C entered\n");
        d=fork();  
        char msg[100];
              
    }

    if(d!=-1 && d>0  || d==-1){
        printf("Final count: %d\n", count);
        
        
    }
    
}

return 0;

}

