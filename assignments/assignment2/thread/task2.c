#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *t_func1(void *arg);
int main(){
    pthread_t t[5];

    for (int i=0;i<5;i++){
        pthread_create(&t[i],NULL,(void *)t_func1,&i);
        pthread_join(t[i],NULL);
    }
    return 0;

}
void *t_func1(void *arg){
    int *x=arg;

    for (int i=1;i<6;i++){
        printf("Thread - %d prints %d\n",*x, i);
        
    }
    sleep(1);

    
    
    
}