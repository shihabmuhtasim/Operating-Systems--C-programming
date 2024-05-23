
#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h> 

int main(int argc, char* argv[]){

    //
    printf("Total argument passed:%d\n",argc);
    printf("File name [1]:%s\n",argv[1]);

    int fd;
    char buffer[80];
    

    fd = open(argv[1],O_RDWR|O_CREAT |O_TRUNC);
    //fd returns  -1 val if unsuccessful
    if (fd != -1){
    printf("myfile opened for read/write access\n");
    }
    //static char message[] = "Hello, world";
    while(1){

        char message[1000];
        //scanf so that it can read all at once till enter
        scanf("%[^\n]", message);

        if (strcmp(message,"-1")==0){
            break;
        }
            
        write(fd, message, strlen(message));
        //go to next line cursor in fd
        write(fd, "\n", 1);
        getchar();//to read enter key
        
    }
    
}