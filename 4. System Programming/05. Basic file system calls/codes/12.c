#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int x = open("f8", O_CREAT|O_RDWR|O_TRUNC, 00777);
	write(x, "ab", 2);
	int y = 10;
	write(x, &y, 4);
	write(x, "cd", 2);
	y = 235;
	write(x, &y, 4);

	return 0;
}
