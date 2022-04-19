#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	for (int i=0; i<3; i++) {
		int x = fork();
		if (x==0){
			printf("Child(%d)'s PID: %d\n", i, getpid());
			fflush(stdout);         // to make printf work immediately
			exit(0);
		}
	}

	return 0;
}
