#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    FILE *filep1, *filep2; 
    char c; 
  
    //printf("Enter the filename to open for reading \n"); 
   // scanf("%s", name); 
  
    // Open one file for reading 
    filep1 = fopen("name.txt", "r"); 
    if (filep1 == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    //printf("Enter the filename to open for writing \n"); 
    //scanf("%s", name.txt); 
  
    // Open another file for writing 
    filep2 = fopen("name2.txt","w"); 
    if (filep2 == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(filep1); 
    while (c != EOF) 
    { 
        fputc(c,filep2); 
        c = fgetc(filep1); 
    } 
  
    printf("\nContents copied to name2.txt "); 
  
    fclose(filep1); 
    fclose(filep2); 
    return 0; 
}
