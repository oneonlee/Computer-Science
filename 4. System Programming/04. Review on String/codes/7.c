#include <stdio.h>
#include <string.h>

int main() {
	char inputStr[50];
	
	while(1) {
		printf("Enter a string\n");
		scanf("%s", inputStr);
		printf("You entered %s. length=%lu\n", inputStr, strlen(inputStr));
		
		if (strcmp(inputStr, "hello") == 0) {
			printf("Yes it is hello. Bye.\n");
			break;
		}
		else {printf("No it is not hello.\n\n");}
	}
}
