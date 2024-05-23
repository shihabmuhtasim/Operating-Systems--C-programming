#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
	pid_t p_id;
	p_id=getpid();
	void *s_m;
	char buff[200];
	int sm_id; 
	//1024 byte mem create, store id in sm_id
	//used key 101
	sm_id=shmget((key_t)101,1024,0666|IPC_CREAT);
	printf("ID of sender process: %d\n",p_id);
	printf("ID of SM: %d\n",sm_id);
	//attach the process to the shared memory
	//i can write here in sm
	s_m=shmat(sm_id,NULL,0);
	printf("Process attached at %p with id %d\n",s_m,p_id);
	printf("Write data for sending:\n");
	//take user input
	read(0,buff,sizeof(buff));
	//copy buff to sm
	strcpy(s_m,buff);
	printf("Writting complete by process with id %d\n",p_id);
	printf("Data written: %s\n",(char *)s_m);
	


	return 0;
}

