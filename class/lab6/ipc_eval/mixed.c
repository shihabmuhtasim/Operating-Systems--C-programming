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

//define structure
struct shared{
    char sel[100];
    int type;
};

int main(){

    //struct import
    struct shared sh;

    //1 array of file descriptor
    int fd[2];
    pid_t a;
    //for parent reading
    char buff[200];
    //1 pipe
    int pipe_1=pipe(fd);
    if(pipe_1==-1){
        perror("pipe_1");
    }

    //init shared memory key
    
    key_t key = ftok("mixed.c", 'A');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }
    


    a=fork();
    if(a<0){
        perror("fork");
    }
    if(a>0){
        sprintf(sh.sel,"Hello from parent");
        strcpy(buff,sh.sel);
        //parent process
        close(fd[0]);
        //write to pipe 
        write(fd[1],&sh,sizeof(sh));
        close(fd[1]);
        wait(NULL);
        //receive from grandchild using message passing
        struct shared sp3;
        int msg_id2;
        int rcv;
        msg_id2 = msgget(key, 0666 | IPC_CREAT);
        msgrcv(msg_id2,(void *)&sp3,sizeof(sp3.sel),0,IPC_NOWAIT);
       
        printf("Parent:%s\n",sp3.sel);

    }
    else{
        struct shared sp;
        //child
        close(fd[1]);
        //read from pipe
        read(fd[0], &sp, sizeof(sp));
        close(fd[0]);
        printf("Child:%s\n",sp.sel); 

        //set sp.sel to hello from child
        sprintf(sp.sel,"Hello from child");
        //send  using shared memory
        void *s_m;
	    int sm_id;
        sm_id=shmget(key,1024,0666|IPC_CREAT);
        s_m=shmat(sm_id,NULL,0);
        memcpy(s_m,&sp,sizeof(sp));
        pid_t b;
        b=fork();
        if (b>0){
            wait(NULL);
        }
        else{
            void *s_r;
            int sr_id;
            //receive from parent using shared memory
            sr_id=shmget(key,1024,0666|IPC_CREAT);
            s_r=shmat(sr_id,NULL,0);
            struct shared sp2;
            memcpy(&sp2,s_r,sizeof(sp2));
            printf("Grandchild:%s\n",sp2.sel);
            sprintf(sp2.sel,"Hello from grandchild");
            sp2.type=2;
            //send to parent using message passing system 
            int msg_id;
            int snt;
            //send using msg pasing
            msg_id = msgget(key, 0666 | IPC_CREAT);
            snt = msgsnd(msg_id, (void *)&sp2, sizeof(sp2.sel), 0);
            if (snt == -1) {
                perror("msgsnd");
                exit(1);
            }
    


        }

        

    }
}