#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

//write grandchild's pid in file and parent read it
int main(){
    int pid, pid2;
    int fd;
    //open file for read write
    fd = open("file.txt",O_RDWR|O_CREAT,0666);
    pid = fork();
    if(pid == 0){
        printf("Child entered\n");
        pid2 = fork();
        if(pid2 == 0){
            printf("Grandchild entered\n");
            char buffer[100];
            sprintf(buffer,"%d",getpid());
            write(fd, buffer, strlen(buffer));
            fsync(fd); // force write to file
        }
        else{
            wait(NULL);
            printf("Grandchild pid %d\n",pid2);
        }
    }
    else{
        wait(NULL);
        printf("Parent\n");
        char buffer2[100];
        //parent read from file
        lseek(fd, 0, SEEK_SET); // reset file pointer to start
        read(fd,buffer2,100);
        //print buffer2
        printf("Grandchild pid from parent %s\n",buffer2);
    }
    close(fd);
    return 0;
}