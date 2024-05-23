#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

//define structure
struct shared{
    char sel[100];
    int b;
};

int main(){
    //struct import
    struct shared sh;

	//1 array of file descriptor
	int fd1[2];
	pid_t a;
    //for parent reading
	char buff[200];
	//2 pipes
	int pipe_1=pipe(fd1);
	if(pipe_1==-1){
		perror("pipe_1");
	}
	
    //print instructions
    printf("Provide Your Input from Given Options:\n"
    "1. Type a to Add Money\n"
    "2. Type w to Withdraw Money\n"
    "3. Type c to Check Balance\n");
    //take user input
    printf("Input your choice: ");
    scanf("%s", sh.sel);
    //set sh.b=1000
    sh.b=1000;
    a=fork();
    if (a>0){
    close(fd1[1]);
    //send the struct using shared memory
    
    void *s_m;
	int sm_id;
    sm_id=shmget((key_t)101,1024,0666|IPC_CREAT);
    s_m=shmat(sm_id,NULL,0);
    memcpy(s_m,&sh,sizeof(sh));
    
    
    //print the selection from sh.sel
    printf("Your selection: %s\n", sh.sel);
    wait(NULL);
    //read from the pipe
    read(fd1[0],buff,sizeof(buff));
    printf("%s\n",buff);
    
    }
    else if (a==0){ 
        close(fd1[0]);
        //READ THE STRUCT FROM SHARED MEMORY
        void *s_r;
        int sr_id;
        sr_id=shmget((key_t)101,1024,0666|IPC_CREAT);
        s_r=shmat(sr_id,NULL,0);
        
        //copy data of struct to sp
        struct shared sp;
        //use mem copy to copy data of s_r to sp
        memcpy(&sp,s_r,sizeof(sp));
        //print the selection from sp->sel
        printf("Your selection received: %s\n", sp.sel);
        //print the balance from sp->b
        printf("Your balance received: %d\n", sp.b);
        
        //check the selection
        if (strcmp(sp.sel,"a")==0){
            //add money input
            int add;
            printf("Enter amount to be added: ");
            scanf("%d", &add);
            //check if positive
            if (add<0){
                printf("Adding failed, invalid amount\n");
                
            }
            else{
                //add the amount
                sp.b+=add;
                //print the new balance
                printf("Balance added Successful\n");
                printf("Updated balance after addition: %d\n", sp.b);
            }
            

    }
    else if (strcmp(sp.sel,"w")==0){
        //withdraw money input
        int withdraw;
        printf("Enter amount to withdraw: ");
        scanf("%d", &withdraw);
        //check if positive
        if (withdraw<0){
            printf("Withdraw failed, invalid amount\n");
            
        }
        else{
            //check if balance is enough
            if (sp.b<withdraw){
                printf("Withdraw failed, insufficient balance\n");
                
            }
            else{
                //withdraw the amount
                sp.b-=withdraw;
                //print the new balance
                printf("Balance withdrawn Successful\n");
                printf("Updated balance after withdrawl: %d\n", sp.b);
            }
        }
    }
    else if (strcmp(sp.sel,"c")==0){
        //print the balance
        printf("Your current balance is: %d\n", sp.b);
    }
    else{
        //invalid input
        printf("Invalid selection\n");
        
    }
char buffer[100]="Thank you for using";
//write in the pipe
write(fd1[1],buffer,strlen(buffer));
}
    return 0;



}