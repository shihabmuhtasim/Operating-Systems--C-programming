//include librarys for fork
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//main function
int main() {
    //create a child process
    int pid = fork();
    //if child process
    if (pid == 0) {
        //use excel to replace the child process with the task4_1.c
        execl("./task4_1", "./task4_1", "1", "2", "3", "4", "5", NULL);

    }

    if(pid > 0){
        wait(NULL);
        //use excel to replace parent with task4_2.c
        execl("./task4_2", "./task4_2", "1", "2", "3", "4", "5", NULL);
    }
    
    
    
    
    
    
    
    }