#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *func_thread(int *n);
void *t_ret;
int num=3;
int main(){
	pthread_t t1;
	pthread_create(&t1,NULL,(void *)func_thread,&num);

	//t_ret stores the str that retuens
	pthread_join(t1,&t_ret);
	//t_ret has mem add of the void str, then * char turns it into str
	printf("Thread returned: %s\n",(char *)t_ret); 
	
	return 0;
}

void *func_thread(int *n){
	printf("Entered in Thread:\n");
	if(*n % 2==0){
		pthread_exit("Even");
	}
	else{
		pthread_exit("Odd");
	}
}
