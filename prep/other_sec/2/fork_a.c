#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//take user input int, child process calculate square of ints upto that int if inp odd, if inp even grnchild process find cube, then back to parent.


int main(){
    printf("Enter a integer : \n");
    int input;
    scanf("%d",&input);
    int pid;
    pid=fork();
    if (pid ==0){
        if (input %2!=0){
        
            for (int i=0; i<input; i++){
                printf("Seuqare of %d is %d\n", i, i*i);
            }

        }
        else{

            int pid2;
            pid2=fork();
            if (pid2==0){
                printf("Grandchild process\n");
                printf("Cube is %d", input*input*input);


            }
            else{
                wait(NULL);
            }
        }
    }
    else{
        wait(NULL);
        printf("Parent done");
    }


    
    
}

