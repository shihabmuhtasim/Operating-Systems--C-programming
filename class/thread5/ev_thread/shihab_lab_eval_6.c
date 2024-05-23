#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//define function for thread task
void *t_func1(void *arg);
void *t_func2(void *arg);
void *t_ret_sum;
void *t_ret_mul;


//main function for thread
int main(){
    //define a file descriptor
    int fd;
    char buffer[80];
    fd = open("21301610.txt",O_RDWR|O_CREAT |O_TRUNC);

    int pid;
    //define array
    int arr[4]={1,2,3,4};
    //define thread 
    pthread_t t[2];
    //fork
    pid=fork();
    //check if clild
    if(pid>0){
        
        //child process
        //mul array thread call
        //create thread and pass the array
        pthread_create(&t[0],NULL,(void *)t_func1,(void *)arr);
        //join thread
        pthread_join(t[0],&t_ret_sum);
        printf("%d",(int)t_ret_sum);
        //take the return value to string and store in message
        //write to the fd 
        char store2[80];
        sprintf(store2,"SUM: %d\n",(int)t_ret_sum);
        write(fd,store2,strlen(store2));
        
        
    }
    else{
        //parent process
        //create thread and pass the array
        pthread_create(&t[1],NULL,(void *)t_func2,(void *)arr);
        pthread_join(t[1],&t_ret_mul);
        printf("%d",(int)(t_ret_mul));
        //write to student id file
        //store the return value to string and store in a buffer
        char store[80];
        sprintf(store,"MUL: %d",(int)t_ret_mul);
        write(fd,store,strlen(store));
        }
    }
    
    


//declair function for thread
void *t_func1(void *arg){
    //get array from *arg
    int *arr=(int *)arg;
    int mul=1;
    for(int i=0;i<4;i++){
        mul=mul*arr[i];
    }
    printf("MUL:");
    pthread_exit((void *)mul);



}

void *t_func2(void *arg){
    //get array from *arg
    int *arr=(int *)arg;
    int sum=0;
    for(int i=0;i<4;i++){
        sum=sum+arr[i];
    }
    printf("SUM: ");
    //return sum
    pthread_exit((void *)sum);
}  





