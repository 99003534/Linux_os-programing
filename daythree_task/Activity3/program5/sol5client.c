
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int ret,nbytes1;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid3;
	mqid3=mq_open("/mque1",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid3<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf1[8192];
	int maxlength=256,prio;
	nbytes1=mq_receive(mqid3,buf1,maxlength,&prio);
	if(nbytes1<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf1[nbytes1]='\0';
	int k;
    printf("%s",buf1);

	k =execlp("/bin/gcc","gcc",buf1,0);
    if(k<0)
		{
			perror("execlp");
			exit(1);
		}
		exit(5);
		
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buf1,nbytes1,prio);
	mq_close(mqid3);
	return 0;
}