#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 20
#define MAX_FILENAME_LENGTH 20

int main(void) {
    printf("Enter file name\n");
    char filename[MAX_FILENAME_LENGTH];
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strlen(filename) - 1] = '\0';

    printf("The content of %s is: \n", filename);

    int fd = open(filename, O_RDONLY);
    unsigned char buf[BUFFER_SIZE];
    int chunk;
    while ((chunk = read(fd, buf, BUFFER_SIZE))) {
        for (int i = 0; i < chunk; i += 1) {
            printf("%x ", buf[i]);
        }
    }
    printf("\n");
    close(fd);
    return 0;
}