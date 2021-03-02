//#include "mystring.h"
#include "myutils.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdarg.h>



 /*
int main()
{
   int number;
   long fact = 1;
   int result;
 
   /*printf("Enter a number to calculate it's factorial\n");
   scanf("%d",&number);
 
   printf("%d! = %ld\n", number, factorial(number));
 
   return 0;
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
    return 0;
}*/
 
long factorial(int n)
{
   int c;
   long result = 1;
 
   for( c = 1 ; c <= n ; c++ )
         result = result*c;
 
   return result;
}



int checkPalindrome(int number)
{
  int temp, remainder, rev=0;
  temp = number;

  while( number!=0 )
  {
     remainder = number % 10;
     rev = rev*10 + remainder;
     number /= 10;
  }

  if ( rev == temp ) return 0;
  else return 1;
}

 

 int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}

int vsum(int a, ...) 
{
    // define type of variable
    va_list L;
    int z;

    z = 0;

    va_start(L, a);

    // Loop to adding the int values
    for (int i=0; i < a; i++)
    {
        z = z + va_arg(L, int);
    }

    va_end(L);

    return z;
}