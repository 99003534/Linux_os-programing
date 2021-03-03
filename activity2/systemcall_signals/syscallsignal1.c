#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int one,two,nbytes, flag;
	one=open("first.txt",O_RDONLY);
	two=open("second.txt",O_WRONLY|O_CREAT, 0666);
	if(one<0 || two<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(one,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	flag = write(two,buf,nbytes);
	close(one);
	close(two);
	if(flag)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}