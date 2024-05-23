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



