#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
int m_arr[20];
int m_top=-1;
sem_t *qs,*ps;
pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;


void* push(void* pv) //consumer
{

    int *val=(int*)pv;

    sem_wait(ps);

   // pthread_mutex_lock(&m1);
if(m_top<=10){
        m_arr[++m_top]=val;
         printf("pushed val:%d\n",val);
         pthread_mutex_unlock(&m1);
    }
   //pthread_mutex_unlock(&m1);
  sem_post(ps);
sem_post(qs);
   
   
}
void* pop(void* pv) //producer
{
 sem_wait(qs);
sem_wait(ps);

    int temp=0;
   
   // pthread_mutex_lock(&m1);
if(m_top!=-1){
        //temp+=1;
        temp=m_arr[m_top--];
       
        printf("VAlue:%d\n",temp);
        //pthread_mutex_unlock(&m1);
    }
    //pthread_mutex_unlock(&m1);
   sem_post(ps);
//pthread_exit(temp);
}
int main()
{

    int i,value;
pthread_t pt1,pt2; //thread handle

//        ps=sem_open("/s1",O_CREAT, 0666, 1);
//qs=sem_open("/s2",O_CREAT, 0666, 0);
   
    for(i=0;i<10;i++){
   //pthread_mutex_lock(&m1);
           pthread_create(&pt1,NULL,push,(void*)i);
           
    }
for(i=0;i<10;i++){


         pthread_create(&pt2,NULL,pop,NULL);
       
         
     }

pthread_join(pt1,NULL);
pthread_join(pt2, NULL );
   sem_unlink("s1");
sem_unlink("s2");
   // pthread_mutex_destroy(&m1);
//printf("VAlue:%d",value);
return 0; //exit(0);

}
