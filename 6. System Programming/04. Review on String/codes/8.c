#include <stdio.h>
#include <string.h>

int main() {
        char inputStr[50];
	char aStr[50];
	char bStr[50];
	char cStr[50];

        printf("Enter a string\n");
        scanf("%s", inputStr);

	strcpy(aStr, inputStr);
        strcpy(bStr, inputStr);      
	strcpy(cStr, inputStr);        

	aStr[0] = 'a';
	bStr[0] = 'b';
	cStr[0] = 'c';

	printf("After copying and changing the first letter\n");
	printf("%s %s %s\n", aStr, bStr, cStr);
}
