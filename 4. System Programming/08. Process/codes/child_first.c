#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int x;
	x = fork();

	if (x!=0){
		sleep(1); // sleep 1 sec
		printf("parent: %d\n", getpid());
	}
	else {
		printf("child: %d\n", getpid());
	}
	return 0;	
}
