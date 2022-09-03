#include <stdio.h>
#include <string.h>

int main() {
	char temp0[20], temp1[10], temp2[10];
	printf("enter src file name\n");
	gets(temp0);
	strcpy(temp1, temp0);
	printf("enter dest file name\n");
	gets(temp0);
	strcpy(temp2,temp0);
	printf("src file:%s dest file:%s\n", temp1, temp2);

	return 0;
}
