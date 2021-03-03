#include<stdio.h>
#include<time.h>
int main()
{
	time_t currenttime;
	struct tm *tm_currenttime;
	int hours,min,sec;
	currenttime=time(NULL);
	tm_currenttime=localtime(&currenttime);
	hours=tm_currenttime->tm_hour;
	min=tm_currenttime->tm_min;
	sec=tm_currenttime->tm_sec;
	printf("TIME is %d : %d : %d",hours,min,sec);
}