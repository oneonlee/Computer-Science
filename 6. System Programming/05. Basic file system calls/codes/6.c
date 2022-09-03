#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int x;
	x = open("f3", O_RDWR|O_CREAT|O_TRUNC, 007777); // create f3
	write(x, "hello there", 11); // write 11 bytes in f3

	return 0;
}
