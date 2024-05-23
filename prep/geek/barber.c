#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
//barbar shop problem
void *function1(int *arg);
void *function2(void *arg);
sem_t seat;
sem_t b;
pthread_mutex_t mutex;
pthread_cond_t full= PTHREAD_COND_INITIALIZER;
pthread_cond_t empty= PTHREAD_COND_INITIALIZER;
void *t_ret;
int cus=0;


int main(){
    
    sem_init(&seat,0,5);
    sem_init(&b,0,1);
    pthread_mutex_init(&mutex,NULL);
    pthread_t barber;
    pthread_t customer[10];
    int cus_id[]={1,2,3,4,5,6,7,8,9,10};
    int id=0;
    pthread_create(&barber,NULL,(void *)function1,(void *)&id);
    for (int i=0;i<10;i++){
        pthread_create(&customer[i],NULL,(void *)function2,(void *)&cus_id[i]);

    }
    
    pthread_join(barber,NULL);
    for (int i=0;i<10;i++){
        pthread_join(customer[i],NULL);
        
    }
    sem_destroy(&seat);
    sem_destroy(&b);
    pthread_mutex_destroy(&mutex);
    return 0;

}

void *function1(int *arg){
    
    //pthread_cond_wait(&signal,&mutex); pthread_cond_signal(&signal);
    
    while(1){
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&full,&mutex);
        sem_wait(&b);
        printf("Barber%d is cutting hair of customer %d\n",*arg,cus);
        sleep(1);
        printf("Barber%d is DONE cutting hair of customer %d\n",*arg,cus);
        sem_post(&b);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
}

void *function2(void *arg){
    int id = *(int *)arg;
    //pthread_cond_wait(&signal,&mutex); pthread_cond_signal(&signal);
    //
    
    sem_wait(&seat);
    printf("customer%d is waiting\n",id);
    pthread_cond_signal(&full);
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&empty,&mutex);
    printf("customer%d got a seat at Barbers\n",id);
    cus=id;
    sem_post(&seat);
    pthread_mutex_unlock(&mutex);

    


}