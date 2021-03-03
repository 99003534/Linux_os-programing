#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int no_lines, no_char, no_words;
int one,l,d,a;
char ch[10000];
one=open("count.txt",O_RDONLY);
if(one<0)
{
	perror("open");
	exit(1);
}
no_words = 0;
no_lines = 0;
while(l=read(one,ch,sizeof(ch)))
	{
    	for(a=0;a<l;a++)
        	{
            	if (ch[a] == '\n')
               	no_lines++;
            	if (ch[a] == ' ' || ch[a] == '\t' || ch[a] == '\n')
               	no_words++;
        	}
        no_char=l;
    }
    close(one);
int lines()
{
  printf("%d\n",no_lines);
}
int Char()
{
  printf("%d\n",no_char);
}
int Words()
{
  printf("%d\n",no_words);
}
lines();
Char();
Words();
return 0;
}