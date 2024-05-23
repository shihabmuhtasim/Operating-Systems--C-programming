#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


struct msg{
	long int type;
	char txt[200];
};


int main(){
    pid_t a;
    int msg_id;
    int snt;
    //structure defined
    struct msg s_data;
    char buff[200];
    key_t key = ftok("passing.c", 'A');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msg_id = msgget(key, 0666 | IPC_CREAT);
    if (msg_id == -1) {
        perror("msgget");
        exit(1);
    }
    
    printf("Please enter the workspace name:\n");
	//user input
	read(0,buff,sizeof(buff));
    //set buff to s_data.txt
    //fork call
    a=fork();
    if (a>0){
    //check if input is cse321
    if (strncmp(buff,"cse321",6)!=0){
        printf("Invalid workspace name\n");
        kill(0, SIGTERM);
        exit(1);

        }
        
    strcpy(s_data.txt, buff);
    //set type of message to 2
    
    s_data.type = 2;
    //send message
    snt = msgsnd(msg_id, (void *)&s_data, sizeof(s_data.txt), 0);
    printf("Workspace name sent to otp generator from log in: %s\n",s_data.txt);
    if (snt == -1) {
        perror("msgsnd");
        exit(1);
        
    }
    wait(NULL);
    struct msg d_data;
    //receive message using frist come first serve
    msgrcv(msg_id, (void *)&d_data, sizeof(d_data.txt), 0,IPC_NOWAIT);
    //print the message received
    printf("Login received OTP from OTP generator: %s\n", d_data.txt);
    struct msg e_data;
    //receive again
    //receive message
    msgrcv(msg_id,(void *)&e_data,sizeof(e_data.txt),0,IPC_NOWAIT);        
    //print the message received
    printf("Login received OTP from Mail: %s\n", e_data.txt);

    msgctl(msg_id,IPC_RMID,0);

    }

    else if (a==0){
        int type=2;
        struct msg r_data;
        int rcv;
        char buff1[200];
        //can i set the type to 2 manually?
        msgrcv(msg_id,(void *)&r_data,sizeof(r_data.txt),type,IPC_NOWAIT);
        printf("OTP generator received workspace name from login: %s\n",r_data.txt);
        pid_t p_id1;
        p_id1=getpid();
        //store pid in r_data.txt
        sprintf(buff1,"%d",p_id1);
        strcpy(r_data.txt,buff1);
        //set type to 1
        r_data.type=1;
        //send message
        snt = msgsnd(msg_id, (void *)&r_data, sizeof(r_data.txt), 0);
        printf("OTP sent to log in from otp generator: %s\n",r_data.txt);
        pid_t b;
        b=fork();
        if (b>0){
            
        //set type to 3 for child process
        r_data.type=3;
        //send message
        snt = msgsnd(msg_id, (void *)&r_data, sizeof(r_data.txt), 0);
        //print the message sent
        printf("Otp sent to mail from OTP generator: %s\n",r_data.txt);
        wait(NULL);
        }
        else if (b==0){
            //set type to 3
            int type=3;
            struct msg c_data;
            
            //receive message
            msgrcv(msg_id,(void *)&c_data,sizeof(c_data.txt),type,IPC_NOWAIT);
            //print the message received
            printf("Mail received OTP from OTP generator : %s\n",c_data.txt);
            //set type to 4
            c_data.type=4;
            //send message
            snt = msgsnd(msg_id, (void *)&c_data, sizeof(c_data.txt), 0);
            
        }

    }

}