
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<fcntl.h>
#include <string.h>


int main()
{

int a,b,c,status,pid;
//pid_t pid;
a = fork();
b = fork();
c = fork();
int count=8;

int fd;
char buffer[80];
fd = open("task3_pids.txt",O_RDWR|O_CREAT |O_TRUNC);
if (a == 0 || b==0 || c==0) {
    int pid=getpid();
    printf("\n I am  child  my pid is %d\n",pid);
    static char message[1000];
    sprintf(message, "PID: %d", pid);
    strcat(message, "\n");
    write(fd, message, strlen(message));

    if (pid%2!=0){

        int x=fork();
        if (x == 0) {
                int child_pid = getpid();
                printf("\n I am grandchild my pid is %d\n", child_pid);
                sprintf(message, "PID: %d\n", child_pid);
                write(fd, message, strlen(message));

            }
        else {
                wait(NULL); // Wait for the grandchild process to finish
            }
    }
    
}

else if (a > 0 && b>0 && c>0){
       
    
    int parent_pid = getpid();
        char message[1000];
        sprintf(message, "PID parent: %d\n", parent_pid);
        write(fd, message, strlen(message));
    //printf("Final count :%d \n",count);
    
}


return 0;

}



