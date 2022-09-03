#include <stdio.h>
#include <string.h>

int main(){
	char inputStr[10];
	printf("Enter a string\n");
	scanf("%s", inputStr);
	printf("The length is %lu\n", strlen(inputStr));
}
