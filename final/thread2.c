#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
//p readers and q writers
void *reader(void *arg);
void *writer(void *arg);
sem_t sem;
pthread_mutex_t mutex;
pthread_cond_t full= PTHREAD_COND_INITIALIZER;
pthread_cond_t empty= PTHREAD_COND_INITIALIZER;
void *t_ret;
char database[100];


int main(){
    int p ;
    int q;
    printf("Enter the number of readers: ");
    scanf("%d",&p);
    printf("Enter the number of writers: ");
    scanf("%d",&q);
    sem_init(&sem,0,1); 
    pthread_mutex_init(&mutex,NULL);
    pthread_t thread[p];
    pthread_t thread2[q];
    int thread1_id[p];
    int thread2_id[q];
    for (int i=0; i<p; i++)
    {
        thread1_id[i]=i;
    }
    for (int j=0; j<q; j++)
    {
        thread2_id[j]=j;
    }

    for (int i=0; i<p; i++)
    {
        pthread_create(&thread[i],NULL,(void *)reader,(void *)&thread1_id[i]);
    }
    for (int j=0; j<q; j++)
    {
        pthread_create(&thread2[j],NULL,(void *)writer,(void *)&thread2_id[j]);
    }
    
    
    for (int i=0; i<p; i++)
    {
        pthread_join(thread[i],&t_ret);
    }
    for (int j=0; j<q; j++)
    {
        pthread_join(thread2[j],&t_ret);
    }
    sem_destroy(&sem);
    pthread_mutex_destroy(&mutex);
    return 0;

}

void *reader(void *arg){
    int id = *(int *)arg;
    //pthread_cond_wait(&value,&mutex); pthread_cond_signal(&value);
    //printf("%d \n",id); or  printf("%d",*arg);
    //printf("REader%d \n",id);
    
    //while buffer empty
    while (database[0]=='\0'){
        pthread_cond_wait(&full,&mutex);}
    pthread_mutex_lock(&mutex);
    //read from database
    printf("Reader %d read %s\n",id,database);
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&empty);

}
void *writer(void *arg){
    int id = *(int *)arg;
    //pthread_cond_wait(&value,&mutex); pthread_cond_signal(&value);
    //printf("%d \n",id); or  printf("%d",*arg);
    //printf("Writer:%d \n",id);
    sem_wait(&sem);
    
    //while buffer full
    while (database[0]!='\0'){
    pthread_cond_wait(&empty,&mutex);}
    pthread_mutex_lock(&mutex);
    //write to database hello writer id
    sprintf(database,"Hello from writer %d",id);
    printf("Writer %d wrote %s\n",id,database);
    sem_post(&sem);
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);  

}
















// pthread_mutex_lock(&mutex);
//         pthread_cond_wait(&full,&mutex);
//         sem_wait(&b);
// 
//         sem_post(&b);
//         pthread_cond_signal(&empty);
//         pthread_mutex_unlock(&mutex);