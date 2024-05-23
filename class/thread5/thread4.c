#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int t_id[5]={1,2,3,4,5};
void *t_func(int *id);
int main(){
	pthread_t t[5];
	for (int i=0;i<5;i++){
		pthread_create(&t[i],NULL,(void *)t_func,&t_id[i]);

	}
	//join doesnt need the location
	
	for(int i=0;i<5;i++){
		pthread_join(t[i],NULL);
	}
	
	return 0;
}
void *t_func(int *id){
	printf("Entered in Thread %d...\n",*id);
	for(int i=0;i<5;i++){
		printf("Thread %d Turn %d\n",*id,i);
		sleep(1);
	}
	printf("Ending Thread %d...\n",*id);
}
