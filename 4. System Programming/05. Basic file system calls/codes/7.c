#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 20

int main() {
	int x1 = open("4.c",  O_RDONLY, 00777);
	int x2 = open("cp4.c", O_RDWR|O_CREAT|O_TRUNC, 00777);
	char buf[BUFFER_SIZE];
	int y;

	for(;;){
		y = read(x1, buf, 20);
		if (y==0) break;
		write(x2, buf, y);
	}
	return 0;
}
