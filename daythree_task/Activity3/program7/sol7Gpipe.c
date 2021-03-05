#include"sol7.h"
void main() 
{
    int a1;
    a1 = mkfifo("pipeA",0666);
    if(a1<0)
        printf("\npipeA was not created");
    else
        printf("\npipeA created");
    int a2;
    a2 = mkfifo("pipeB",0666);
    if(a2<0)
        printf("\npipeB was not created");
    else
        printf("\npipeB is created\n");
}