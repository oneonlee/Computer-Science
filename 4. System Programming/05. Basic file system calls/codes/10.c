// mycat program

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	char buf[20];
	char fName[10];

	printf("Enter file name\n");
	scanf("%s", fName);
	int x = open(fName, O_RDONLY, 00777);
	 	
	printf("The content of %s is :\n", fName);
	int y;
	for(;;){
		y=read(x, buf, 20);
		if (y==0) break;
		buf[y] = '\0';
		printf("%s", buf);
	}		

	return 0;
}
