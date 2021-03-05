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
	int ret;
	mqd_t mqid3;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqid3=mq_open("/mque1",O_WRONLY|O_CREAT,0666,&attr);
	if(mqid3<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str1[]="temp.c";
	int len=strlen(str1);
	ret=mq_send(mqid3,str1,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid3);
	return 0;
}