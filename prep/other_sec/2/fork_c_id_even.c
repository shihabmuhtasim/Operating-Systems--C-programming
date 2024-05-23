#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//mod id og gc % child-

int main(){
    
    int pid;
    pid=fork();
    if (pid ==0){

        int pid2;
        pid2=fork();
        if (pid2>0){
            int c;
            c=getpid();
            printf("C%d\n",c);
            printf("gc%d\n",pid2);
            int r=pid2%c;
            printf("LAST%d\n",  r);
            
        }
    }

}
    



