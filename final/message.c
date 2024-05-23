#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

//message sharing system -producer and consumer

//define signal 
pthread_cond_t  full= PTHREAD_COND_INITIALIZER;
pthread_cond_t  empty= PTHREAD_COND_INITIALIZER;
//define mutex
pthread_mutex_t mutex;
//define buffer
char buffer[100];
//define source
char source[100];

//functions
void * producer(void *id);
void * consumer(void *id);

int main(){
    //define thread
    pthread_t thread[2];
    //define thread id
    int thread_id[2] = {0,1};
    //sender thread
    pthread_create(&thread[0], NULL, producer, (void *)&thread_id[0]);
    //receiver thread
    pthread_create(&thread[1], NULL, consumer, (void *)&thread_id[1]);
    //wait for the threads to finish
    for(int i = 0; i < 2; i++){
        pthread_join(thread[i], NULL);
    }
    //destroy mutex
    pthread_mutex_destroy(&mutex);
    
}

void * consumer(void *id){
    for(int i = 0; i < 5; i++){
        //lock mutex
        pthread_mutex_lock(&mutex);
        //wait for producer to produce
        while (buffer[0] == '\0') // wait until buffer is not empty
            pthread_cond_wait(&full, &mutex);
        //print the message
        printf("Consumer is consuming message: %s\n", buffer);
        buffer[0] = '\0'; // clear the buffer
        //unlock mutex
        pthread_mutex_unlock(&mutex);
        //signal producer
        pthread_cond_signal(&empty);
    }
    return NULL;
}

void * producer(void *id){
    for(int i = 0; i < 5; i++){
        //lock mutex
        pthread_mutex_lock(&mutex);
        //wait until buffer is empty
        while (buffer[0] != '\0')
            pthread_cond_wait(&empty, &mutex);
        //take user input to buffer
        printf("Enter a message:");
        scanf("%s", source);
        //copy source to buffer
        strcpy(buffer, source);
        //unlock mutex
        pthread_mutex_unlock(&mutex);
        //signal consumer
        pthread_cond_signal(&full);
    }
    return NULL;
}