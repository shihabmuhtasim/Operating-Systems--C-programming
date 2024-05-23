#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg{
	long int type;
	char txt[200];
};

int main(){
	pid_t p_id;
	int msg_id;
	int snt;
	//structure defined
	struct msg s_data;
	char buff[200];
	p_id=getpid();
	//create message queue
	msg_id=msgget((key_t)12,0666|IPC_CREAT);

	if (msg_id==-1){
		printf("Error\n");
	}
	printf("Write:\n");
	//user input
	read(0,buff,sizeof(buff));
	//type of message set to 2
	s_data.type=2;
	strcpy(s_data.txt,buff);
	//location of structure s_data
	//location of structure, text size,flag- nowait- doesnt wait for msg
	snt=msgsnd(msg_id,(void *)&s_data,sizeof(s_data.txt),0);
	if(snt==-1){
		printf("Error\n");
	}

	printf("Data Sent:\n%s\n",s_data.txt);

	return 0;
}

