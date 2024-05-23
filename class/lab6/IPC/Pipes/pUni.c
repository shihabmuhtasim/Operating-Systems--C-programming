#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <wait.h>

int main(){
	//pipe
	int fd[2];
	pid_t a;
	char buff[200];
	//pass fd to pipe
	int p=pipe(fd);
	//printf("p: %d\n",p);
	if(p==-1){
		perror("pipe");
	}
	a=fork();
	if(a<0){
		perror("fork");
	}
	else if(a==0){
		//as fd0 not needed 
		close(fd[0]);
		printf("Give input:\n");
		//read / input take from terminal
		read(0,buff,sizeof(buff));
		printf("Writing data for sending_____\n");
		//write to fd1
		write(fd[1],buff,sizeof(buff));
		printf("Writing done_____\n");
		close(fd[1]);
	}
	else{
		wait(NULL);
		// parent read from fd0 so close fd1
		close(fd[1]);
		printf("Reading data after receiving_____\n");
		read(fd[0],buff,sizeof(buff));
		printf("Data received:\n%s\n",buff);
		close(fd[0]);
	}

	
	

	return 0;
}
