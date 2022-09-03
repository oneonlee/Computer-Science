
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Enter file name to split\n");
    char fName[10];
    fgets(fName, 20, stdin);    
    size_t len = strlen(fName);
    fName[len - 1] = '\0';

    int fd = open(fName, O_RDONLY, 00777);

    struct stat sb;
    fstat(fd, &sb);
    long long totalSize = sb.st_size;
    long long smallSize = totalSize / 3;

    printf("%s is split into ", fName);
    char* buf = (char*) malloc(sizeof(char) * smallSize);
    int temp;
    
    for (int i = 1; i <= 3; i += 1) {
	fName[len - 1] = (char)(i + '0');
        int segment_fd = open(fName, O_WRONLY | O_CREAT | O_TRUNC, 00777);
        
        if (i != 3) {
            temp = read(fd, buf, smallSize);
            printf("%s, ", fName);
        } else {
            temp = read(fd, buf, totalSize - smallSize * 2);
            printf("and %s.\n", fName);
        }
        write(segment_fd, buf, temp);
        close(segment_fd);
    }
    return 0;
}










