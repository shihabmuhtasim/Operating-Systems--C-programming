#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

//define structure
struct shared{
    char sel[100];
    int b;
};

int main(){
    //struct import
    struct shared sh;
    

	//2 array of file descriptor
	int fd[2],fd1[2];
	pid_t a;
    //for parent reading
	char buff[200];
	//2 pipes
	int pipe_1=pipe(fd);
	int pipe_2=pipe(fd1);
	if(pipe_1==-1){
		perror("pipe_1");
	}
	if(pipe_2==-1){
		perror("pipe_2");
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
    //send the structure data using pipe 1
    close(fd[0]);
    close(fd1[1]);
    write(fd[1],&sh,sizeof(sh));
    //print the selection from sh.sel
    printf("Your selection: %s\n", sh.sel);
    wait(NULL);
    //read from the pipe
    read(fd1[0],buff,sizeof(buff));
    printf("%s\n",buff);
    
    }
    else if (a==0){ 
        //receive the structure data using pipe 1
        close(fd[1]);
        close(fd1[0]);
        read(fd[0],&sh,sizeof(sh));
        
        //check the selection
        if (strcmp(sh.sel,"a")==0){
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
                sh.b+=add;
                //print the new balance
                printf("Balance added Successful\n");
                printf("Updated balance after addition: %d\n", sh.b);
            }
            

    }
    else if (strcmp(sh.sel,"w")==0){
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
            if (sh.b<withdraw){
                printf("Withdraw failed, insufficient balance\n");
                
            }
            else{
                //withdraw the amount
                sh.b-=withdraw;
                //print the new balance
                printf("Balance withdrawn Successful\n");
                printf("Updated balance after withdrawl: %d\n", sh.b);
            }
        }
    }
    else if (strcmp(sh.sel,"c")==0){
        //print the balance
        printf("Your current balance is: %d\n", sh.b);
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