// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// int main(){
// printf(“1 \n”);
// pid_t pid = fork();
// if(pid == 0) execl("/usr/bin/ls”,“ls”, NULL);
// else if(pid>0) execl("bin/pwd/”,“pwd”, NULL);
// }

// #include<stdio.h>
// int main(int argc, char* argv[]){
//     printf("Program-1 arguments passed: %d", argc);
//     for(int i=0; i<argc; i++){
//     printf("%s", argv[i]);
// }
// }

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Program-2 Running…");
    pid_t pid, status;
    pid = fork();
    if (pid == 0)
        execl("./pr1", "./pr1", "a", "b", "c", "d", NULL);
    else if (pid > 0)
    {
        wait(&status);
        execl("/usr/bin/pwd", "pwd", NULL);
    }
}

//gcc ex.c -o ex && ./ex 1 2 3 4 5