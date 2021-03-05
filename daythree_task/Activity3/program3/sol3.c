#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 6
#define BufferSize 6

int inn = 0;
int outt = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;
void *producer(void *pno)
{
    int itm;
    for(int i = 0; i < MaxItems; i++) {
        itm = rand();
        pthread_mutex_lock(&mutex);
         while (((inn + 1) % BufferSize) == outt)
        {
           buffer[inn] = itm;
           printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[inn],inn);
           inn = (inn + 1) % BufferSize;
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cno)
{
    int itm=0;
    for(int i = 0; i < MaxItems; i++) {
        pthread_mutex_lock(&mutex);
        while (inn == outt)
        {
           itm = buffer[outt];
           printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),itm, outt);
           outt = (outt + 1) % BufferSize;
        }
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
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

    pthread_mutex_destroy(&mutex);
    return 0;
}