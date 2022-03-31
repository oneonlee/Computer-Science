#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter a sentence\n");
    char s1[99];
    fgets(s1, 99, stdin);
    printf("You entered %s\n", s1);

    char s2[50];
    strcpy(s2, s1);
    
    char s3[50];
    strcpy(s3, s1);


    char *tmp = strtok(s2, " ");

    int i=0;
    while (tmp != NULL)
    {
        tmp = strtok(NULL, " ");
        i++;
    }

    printf("There were %d words:\n", i);

    char *ptr = strtok(s1, " ");
    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    printf("The original sentence was %s\n", s3);
    return 0;
}
