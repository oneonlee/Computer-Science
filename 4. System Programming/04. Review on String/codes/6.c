#include <stdio.h>
#include <string.h>

int main(){
        char inputStr[10];
	
	printf("Enter a string\n");
        scanf("%s", inputStr);
        	
	int i = 0;
	while (i < strlen(inputStr)) {
		if (inputStr[i] == '0') {break;}
		else {printf("%c\n", inputStr[i]);}
		i++;
	}
}
