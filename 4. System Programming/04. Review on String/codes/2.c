#include <stdio.h>
int main(){
	char x[10];    // x is a character array with 10 rooms
	x[0]='a'; x[1]='b'; x[2]='c'; x[3]='d'; x[4]='e';
	x[5]='f'; x[6]='g'; x[7]='h'; x[8]='i'; x[9]='j';
	int i;
	for(i=0;i<10;i++){  
	   printf("%d %c \n", x[i], x[i]);  // print each character with its ascii number
	}
}
