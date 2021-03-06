#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char a[100];

    char ch;
    int identities,terms,strings;


    /* Input path of files to merge to third file */
    printf("Enter source file path: ");
    scanf("%s", a);

    /* Open source files in 'r' mode */
    file = fopen(a, "r");
    /* Check if file opened successfully */
    if (file == NULL)
    {
        printf("unable to open Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    
    identities = terms = strings = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        identities++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            strings++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
          terms++;
    }
    /* Increment words and lines for last word */
    if (identities > 0)
    {
        terms++;
        strings++;
    }

    /* Print file statistics */
    printf("\n");
    printf("Total characters = %d\n", identities);
    printf("Total words      = %d\n", terms);
    printf("Total lines      = %d\n", strings);


    /* Close files to release resources */
    fclose(file);

    return 0;
}