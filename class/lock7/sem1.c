#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
//thread ids
int t_id[4]={1,2,3,4};
//thread functions
void *t_func(int *id);
//shared variable resource
int count=0;
//type of semaphore
sem_t s; 

int main(){
	//declaring threads
	pthread_t t[4];
	//initializing semaphore
	//0 maens all thread can access the semaphore
	//3 means 3 threads can access the semaphore at a time
	sem_init(&s,0,3);
	
	for(int i=0;i<4;i++){
		pthread_create(&t[i],NULL,(void *)t_func,&t_id[i]);
	}
	
	
	for(int i=0;i<4;i++){
		pthread_join(t[i],NULL);
	}
	//realaes semaphore memory
	sem_destroy(&s);
	printf("Total count: %d\n",count);
	return 0;
}
void *t_func(int *id){
	//s -- semaphore
	sem_wait(&s);
	printf("Entered in Thread %d...\n",*id);
	for(int i=0;i<10000000000;i++){
		
		count++;
		sem_post(&s);
	}
	
}
