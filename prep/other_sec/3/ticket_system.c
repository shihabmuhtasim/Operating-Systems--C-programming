#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

//make a ticket system using semaphore with 2 threads- ticket sell and buy
//ticket sell thread will sell ticket and ticket buy thread send buy request
pthread_mutex_t mutex;
int ticket_count = 100;
//threads init
pthread_t ticket_sell;
pthread_t ticket_buy;

//functions
void *ticket_sell_func(void *arg);
void *ticket_buy_func(void *arg);

int main(){
    //initialize mutex
    pthread_mutex_init(&mutex,NULL);
    //thread create
    
    pthread_create(&ticket_buy,NULL,ticket_buy_func,NULL);

    //thread join
    pthread_join(ticket_sell,NULL);
    pthread_join(ticket_buy,NULL);
}


void *ticket_sell_func(void *arg){
        int tickets_sell = *(int *)arg;
        printf("Ticket sell request for %d tickets\n",tickets_sell);
        //sell ticket
        pthread_mutex_lock(&mutex);
        ticket_count-= tickets_sell;
        printf("Ticket sold. Remaining ticket: %d\n",ticket_count);
        pthread_mutex_unlock(&mutex);
        
        sleep(1);
    
}

void *ticket_buy_func(void *arg){
    while(1){
        printf("How many tickets you want to buy?\n");
        //inp how many tickets
        int tickets_buy;
        scanf("%d",&tickets_buy);
        //buy ticket
        pthread_create(&ticket_sell,NULL,ticket_sell_func,&tickets_buy);
        sleep(1);
    }
}
