#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int ret,i,status;
	printf("welcome..pid=%d\n",getpid());
	ret=fork();
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
		
        int k;
        char str[20];
        scanf("%s",str);
        k=execl("/usr/bin/pwd",str,NULL);
        
		if(k<0)
		{
			perror("execl");
			exit(1);
		
        }
        exit(5);
	}
	else	
	{
		printf("parent--hello,pid=%d,ppid=%d\n",
			getpid(),getppid());
		waitpid(-1,&status,0); 
		printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
	}
	return 0;
}