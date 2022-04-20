#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	for (int i=argc-1; i>0; i--){
		printf("%s", argv[i]);
	} 
	printf("\n");
	return 0;
}
