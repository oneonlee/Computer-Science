#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 20

void print_hexdump(char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Invalid arguments: A argument is required.\n");
        exit(EXIT_FAILURE);
    }
    print_hexdump(argv[1]);
    return 0;
}

void print_hexdump(char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Fail to open");
        exit(EXIT_FAILURE);
    }
    char buf[BUFFER_SIZE];
    int chunk;
    while ((chunk = read(fd, buf, BUFFER_SIZE))) {
        for (int i = 0; i < chunk; i += 1) {
            printf("%x ", buf[i]);
        }
    }
    printf("\n");
    close(fd);
}
