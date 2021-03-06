#include "mystring.h"
#include "myutils.h"
#include "bitmask.h"
#include<stdio.h>
#include<string.h>
int main()
{   
    int number;
    long fact = 1;
    int result;
    int k =4;
    int num = 5;

    char city[20] = "HYDERABAD";
    char town[20] = "MANGALORE";
    char abc[20];
    printf("%d\n",mystrlen(city));
    printf("%s\n",mystrcpy(abc,city));
    printf("%s\n",mystrcat(city,town));
    printf("%d",mystrcmp(city,town));
    printf("%d\n",factorial(3));
    if(checkPalindrome(number) == 0){
        printf("%d is a palindrome number.\n",number);}
    else if(checkPalindrome(number) == 1){
        printf("%d is not a palindrome number.\n",number);
    }
    result = check_prime(86);
    if ( result == 1 ){
      printf("It is prime number.\n");
    }
   else if(result == 0){
      printf("It is not prime number.\n");
   }
    printf("%d\n", vsum(3, 2, 3, 4));
    printf("setting %d th of %d is %d \n",k,num,set(num,k));
    printf("setting %d th of %d is %d \n",k,num,clear(num,k));
    printf("setting %d th of %d is %d \n",k,num,flip(num,k));

    return 0;
}




