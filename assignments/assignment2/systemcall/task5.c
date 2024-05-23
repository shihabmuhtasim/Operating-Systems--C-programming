#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();
    if(pid > 0)
    {  
        printf("1 Parent process pid: %d", getpid());
        printf("\n");
    
    }
    else if(pid == 0)
    {
        printf("2 Child process pid: %d", getpid());
        printf("\n");
        int gc1;
        gc1 = fork();
        if(gc1 == 0)
        {
            printf("3 Grandchild process pid: %d", getpid());
            printf("\n");
        }
        else if (gc1>0)
        {
            int gc2;
            gc2 = fork();
            if(gc2 == 0)
            {
                wait(NULL);
                printf("4 Grandchild process pid: %d", getpid());
                printf("\n");
            }
            else if(gc2 > 0)
            {
                int gc3;
                gc3 = fork();
                if(gc3 == 0)
                {
                    wait(NULL);
                    printf("5 Grandchild process pid: %d", getpid());
                    printf("\n");
                }
        
                    

            }
        }
    }
return 0;

}


