#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define BufferSize 10

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
int MaxItems;

void *producer(void *pno)
{   
    int itm;
    for(int i = 0; i < MaxItems; i++) {
        itm = rand(); 
        sem_wait(&empty);
        while (((in + 1) % BufferSize) == out)
        {
           buffer[in] = itm;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
           in = (in + 1) % BufferSize;     
        }
        sem_post(&full);
    }
}
void *consumer(void *cno)
{
    int itm=0;
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        while (in == out) 
        {
           itm = buffer[out];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),itm, out); 
           out = (out + 1) % BufferSize; 
        }
        sem_post(&empty);
    }
}

int main()
{

    pthread_t pro[5],con[5];
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    int a[6] = {1,2,3,4,5,6}; 

    for(int i = 0; i < 6; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 6; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 6; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 6; i++) {
        pthread_join(con[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}