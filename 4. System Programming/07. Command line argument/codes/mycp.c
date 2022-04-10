#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 20

void copy_file(char* srcname, char* destname);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Invalid arguments: Two arguments(src, dest) are required.\n");
        exit(EXIT_FAILURE);
    }
    copy_file(argv[1], argv[2]);
    return 0;
}

void copy_file(char* srcname, char* destname) {
    int in_fd = open(srcname, O_RDONLY);
    int out_fd = open(destname, O_WRONLY | O_CREAT | O_TRUNC, 00777);
    if (in_fd == -1 || out_fd == -1) {
        perror("Fail to open");
        exit(EXIT_FAILURE);
    }
    char buf[BUFFER_SIZE];
    int chunk;
    while ((chunk = read(in_fd, buf, BUFFER_SIZE)) > 0) {
        write(out_fd, buf, chunk);
    }
    close(in_fd);
    close(out_fd);
}
