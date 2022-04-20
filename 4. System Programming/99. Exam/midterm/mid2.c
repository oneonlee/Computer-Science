#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int file_num = argc - 1;

	int fd[file_num];
	long long total_size[file_num];
	struct stat sb[file_num];
	for (int i=0; i<file_num; i++){
		fd[i] = open(argv[i+1], O_RDONLY);
	
		fstat(fd[i], &sb[i]);
		total_size[i] = sb[i].st_size;
	}
	
	long long sum=0;
	for (int i=0; i<file_num; i++){
		printf("%s: %lldbytes\n", argv[i+1], total_size[i]);
		sum = sum + total_size[i];
	}	

	printf("The total size: %lld\n", sum);

	return 0;
}
