#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *t_func1(void *arg);
void *t_func2(void *arg);
void *t_ret;
int main(){
    pthread_t t[4];
    //stores the outputs of the 3 threads
    int store[3];
    //craete threads
    for (int i=0;i<3;i++){
        pthread_create(&t[i],NULL,(void *)t_func1,NULL);
        pthread_join(t[i],&t_ret);
        store[i] = (int)t_ret;
    }
    pthread_create(&t[3],NULL,(void *)t_func2,(void *)store);
    pthread_join(t[3],NULL);
    return 0;

}
void *t_func1(void *arg){
    char msg[1000];
    printf("Enter a message: ");
    scanf("%s",msg);
    //printf("Thread - %s msg \n",msg);

    int sum = 0;
    for (int i = 0; msg[i] != '\0'; i++) {
        sum += (int)msg[i];
    }
    //printf("Sum of ASCII values: %d\n", sum);
    pthread_exit(sum);
    
    sleep(1);
  
}

void *t_func2(void *arg){
    int *x=arg;
    printf("Entered in Thread :%d, %d, %d\n",x[0],x[1],x[2]);
    if (x[0]==x[1]==x[2]){
        printf("Youreka! \n");
    }
    else if (x[0]!=x[1] && x[1]==x[2] && x[0]==x[2]||x[0]==x[1] && x[1]!=x[2] && x[0]==x[2]||x[0]==x[1] && x[1]==x[2] && x[0]!=x[2]){
        printf("Miracle\n");
    }
    else{
        printf("Hasta la vista\n");
    }
    sleep(1);
    
}