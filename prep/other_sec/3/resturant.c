#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

//10 people go to resturant 5 can eat at a time

//define semaphore
sem_t sem;
//define signal 
pthread_cond_t  full= PTHREAD_COND_INITIALIZER;

void resturant(int *id);

int main()
{
    int i;
    pthread_t thread[10];
    int thread_id[]={0,1,2,3,4,5,6,7,8,9};
    //initialize semaphore
    sem_init(&sem, 0, 5);
    for(i = 0; i < 10; i++)
    {   

        pthread_create(&thread[i], NULL, (void *)resturant, (void *)&thread_id[i]);
    }
    for(i = 0; i < 10; i++)
    {
        pthread_join(thread[i], NULL);
    }
    //destroy semaphore
    sem_destroy(&sem);
    return 0;
}
void resturant(int *id)
{
    //wait for semaphore
    sem_wait(&sem);
    printf("Person %d is eating\n", *id);
    sleep(2);
    printf("Person %d is done eating\n", *id);
    //signal semaphore
    sem_post(&sem);
}