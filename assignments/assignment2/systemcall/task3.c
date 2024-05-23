#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
//include fd library
#include <fcntl.h>
#include <signal.h>


int main()
{
//initialize a file descriptor system call
int fd=open("count.txt",O_CREAT|O_RDWR| O_TRUNC);
//check if the file descriptor is valid
if(fd==-1){
    printf("File descriptor is invalid");
    exit(1);
}

int a,b,c,d=-1,e=-1,f=-1;

a = fork();
b = fork();
c = fork();

//write to the file - current process id
char msg[100];
sprintf(msg, "%d\n", getpid());
write(fd, msg, strlen(msg));
fsync(fd);


if (a > 0 && b>0 && c>0){
    //read how many lines are in file
    char buffer[2];
    //buffer is not null terminated so need to access using [0]
    //making null terminated
    buffer[1]='\0';
    int n;
    lseek(fd, 0, SEEK_SET);
    int count=0;

    n=read(fd, buffer, 1);
    
    
    //compare if buffer has '\n' character
    if (buffer[0] == '\n'){
        count=1;}

    while (n>0){
        if (buffer[0] == '\n'){
            count++;
        }
        n=read(fd, buffer, 1);
        
        
    }
    //printf("Number of lines in file: %d\n", count);
    close(fd);

    if (a%2!=0){
        count++;
        d=fork();
        
        
        
    }

    if (b%2!=0){
        count++;
        e=fork();
           
    }

    if (c%2!=0){
        count++;
        f=fork();  
                   
    }


     printf("Number of processes created: %d\n", count);
        kill(0, SIGTERM);
        exit(1);
    

    

    
    
    
    
}

return 0;

}

