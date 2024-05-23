#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>


//dining philosopher problem

//declair semaphore
sem_t chopstick[5];
//declair mutex
pthread_mutex_t mutex;
//declair philosopher function  
void philosopher_func(int *i);

int main(){
    //initialize semaphore
    for(int i=0;i<5;i++){
        sem_init(&chopstick[i],0,1);
    }
    //initialize mutex
    pthread_mutex_init(&mutex,NULL);

    //declair thread
    pthread_t philosopher[5];
    //create thread
    int philo_id[5] = {0,1,2,3,4};
    for(int i=0;i<5;i++){
        pthread_create(&philosopher[i],NULL,(void *)philosopher_func, (void *)&philo_id[i]);
    }

    //join thread
    for(int i=0;i<5;i++){
        pthread_join(philosopher[i],NULL);
    }
    //destroy semaphore
    for(int i=0;i<5;i++){
        sem_destroy(&chopstick[i]);
    }
    //destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

void philosopher_func(int *i){
    while(1){
        //think
        printf("Philosopher %d is thinking...\n",*i);
        
        //hungry
        printf("Philosopher %d is hungry...\n",*i);
        //lock mutex
        pthread_mutex_lock(&mutex);
        //if even
        if(*i%2==0){
            //wait for chopstick
            sem_wait(&chopstick[*i]);
            sem_wait(&chopstick[(*i+1)%5]);
        }
        else{
            //wait for chopstick
            sem_wait(&chopstick[(*i+1)%5]);
            sem_wait(&chopstick[*i]);
        }
        
        //unlock mutex
        pthread_mutex_unlock(&mutex);
        //eat
        printf("Philosopher %d is eating...\n",*i);
        sleep(1);
        //put down chopstick
        sem_post(&chopstick[*i]);
        sem_post(&chopstick[(*i+1)%5]);
    }
}