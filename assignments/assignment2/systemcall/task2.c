#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>

int main()
{
int pid, status, pid2;
//pid_t pid;
pid = fork();

if (pid > 0){
wait(&status);
printf("\n I am parent\n");
}
else if (pid == 0){
pid2=fork();
if (pid2>0){
    wait(&status);
    printf("\n I am child");
}
else if (pid2==0){
    printf("\n I am grandchild");
}
else{
    perror("error in fork");
}
}
else{
perror("error in fork");

}
return 0;

}

