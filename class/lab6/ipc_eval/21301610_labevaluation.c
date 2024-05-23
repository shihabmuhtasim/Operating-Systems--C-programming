#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <signal.h>
#include <sys/msg.h>



int main(){
    pid_t a;
    //pipe
    int fd[2],fd1[2];
    char buff[200];
    int pipe_1=pipe(fd);
    int pipe_2=pipe(fd1);
    //define number
    int b;
    printf("Enter a number: ");
    scanf("%d",&b);
 
    a=fork();
    if (a<0){
        perror("fork");
    }
    if(a>0){
        close(fd[0]);
        write(fd[1],&b,sizeof(b));
        close(fd[1]);
        wait(NULL);
        //receive from child
        int fac2;
        close(fd1[1]);
        read(fd1[0],&fac2,sizeof(fac2));
        printf("Factorial of %d is %d\n",b,fac2);
        close(fd1[0]);

    }
    else{
        close(fd[1]);
        read(fd[0],&b,sizeof(b));
        //print b
        //printf("%d\n",b);
        close(fd[0]);
        //find the factorial of b
        int fac=1;
        for(int i=1;i<=b;i++){
            fac=fac*i;
        }
        //send the factorial to parent
        close(fd1[0]);
        write(fd1[1],&fac,sizeof(fac));
        close(fd1[1]);

    }


}