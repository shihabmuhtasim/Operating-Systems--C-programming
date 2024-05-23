
#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>

int main()
{
int fd;
char buffer[80];
static char message[] = "Hello, world";
fd = open("myfile",O_RDWR|O_CREAT);
//fd returns any val ex -1 val if successful
if (fd != -1)
{
printf("myfile opened for read/write access\n");

//fd, message string, write inside file
//write(fd, message, sizeof(message));
lseek(fd, 2, SEEK_SET); /* go back to the beginning of the file */
read(fd, buffer, sizeof(message));
printf("%s was written to myfile \n", buffer);
close (fd);
}
}


main()
{
int pid, status;
//pid_t pid;
pid = fork();
if (pid == 0){
printf("\n I'm the child process\n");
//printf("\n I'm the child process, my pr %d", getpid());
}
else if (pid > 0){
wait(&status);
printf("\n I'm the parent process. My child pid is %d", pid);
//printf("\n I'm the parent process2. My child pid is %d", getpid());
}
else
perror("error in fork");



}


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
printf("1 \n");
pid_t pid = fork();
if(pid == 0) execl("bin/ls/","ls", NULL);
else if(pid>0) execl("bin/pwd/","pwd", NULL);
}
