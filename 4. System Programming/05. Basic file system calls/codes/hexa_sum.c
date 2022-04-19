// hexademical sum

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 20

int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDONLY, 00777);
	unsigned char buf[BUFFER_SIZE];
	
	int chunk;
	int sum = 0;
	while ((chunk = read(fd, buf, BUFFER_SIZE))) {
		for (int i = 0; i < chunk; i++) {
			// printf("%x ", buf[i]);
			sum += buf[i];	
		}
	}
	printf("sum : %x\n", sum);
	close(fd);
	return 0;
}
