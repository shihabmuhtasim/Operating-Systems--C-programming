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
pthread_t ticket_sell[2];
pthread_t ticket_buy[5];

pthread_cond_t  ticket= PTHREAD_COND_INITIALIZER;
//functions
void *ticket_sell_func(void *arg);
void *ticket_buy_func(void *arg);

//struct
struct ticket{
    int customer_id;
    int ticket_req;
};
struct ticket t;

int main(){
    //initialize mutex
    pthread_mutex_init(&mutex,NULL);
    //thread create
    
    for (int i = 0; i < 2; i++){
        pthread_create(&ticket_sell[i],NULL,ticket_sell_func,&i);
    }
    for (int i = 0; i < 5; i++){
        pthread_create(&ticket_buy[i],NULL,ticket_buy_func,&i);
    }

    //thread join
    for (int i = 0; i < 1; i++){
        pthread_join(ticket_sell[i],NULL);
    }
    for (int i = 0; i < 5; i++){
        pthread_join(ticket_buy[i],NULL);
    }
    //destroy mutex
    pthread_mutex_destroy(&mutex);
}


void *ticket_sell_func(void *arg){
    while (1){
    pthread_mutex_lock(&mutex);
    //wait
    pthread_cond_wait(&ticket,&mutex);
    
    int customer_id=t.customer_id;
    int ticket_req =t.ticket_req;
    printf("Ticket sell request for %d tickets by customer %d\n",ticket_req, customer_id);

    ticket_count-= ticket_req;


    printf("Ticket sold. Remaining ticket: %d\n",ticket_count);
    pthread_mutex_unlock(&mutex);

    }
        
        
    
}

void *ticket_buy_func(void *arg){
    pthread_mutex_lock(&mutex);
    printf("How many tickets you want to buy?\n");
    int customer_id= *(int *)arg;
    //inp how many tickets
    int tickets_buy;
    scanf("%d",&tickets_buy);

    if (tickets_buy > ticket_count){
        printf("Not enough tickets\n");
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    
    t.customer_id = customer_id;
    t.ticket_req = tickets_buy;
    //send signal 
    pthread_cond_signal(&ticket);

    //ssend signal
    pthread_mutex_unlock(&mutex);
    sleep(1);


}
