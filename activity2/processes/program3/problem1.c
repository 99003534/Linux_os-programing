#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int temp,status;
char cmd[8];
temp=fork();
if(temp<0)
{
printf("Wrong");
}
else if(temp==0)
{
printf("Please entered the cmd");
scanf("%s",cmd);
execlp(cmd,cmd,NULL);
exit(0);
}
else
{
waitpid(-1,&status,0);
printf("The child has created\n");
printf("The status is %d",WEXITSTATUS(status));
}
}