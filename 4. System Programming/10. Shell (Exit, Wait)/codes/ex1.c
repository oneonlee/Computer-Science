#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int x, y, status, i;
	char buf[50];
	char * argv[10];

	for (int i=0; i<10; i++) { // use a finite loop instead of an infinite one
		printf("$ ");
		scanf("%s", buf); // get command
		argv[0] = buf;
		argv[1] = 0;
		
		x = fork();
		if (x==0) { // child
			printf("I am child to execute %s\n", buf);
			y = execve(buf, argv, 0);
			if (y<0) {
				perror("exec failed");
				exit(1);
			}
		} else {
			wait(&status);
		}
	}
}
