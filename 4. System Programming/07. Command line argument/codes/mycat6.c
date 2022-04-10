#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 20
#define MAX_LINE_LENGTH 100

void copy_file(char* srcname, char* destname);
void format_passwd(char* filename);
void print_directory(char* dirname);
void print_file(char* filename);
void print_hexdump(char* filename);

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        if (argv[1][0] == '-') { 
            switch (argv[1][1]) {
            case 'd': // `-d` option
                if (argc == 3) {
                    print_directory(argv[2]);
                } else {
                    fprintf(stderr, "Invalid arguments: A argument(dirname) is required.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'o': // `-o` option
                if (argc == 4) {
                    copy_file(argv[2], argv[3]);
                } else {
                    fprintf(stderr, "Invalid arguments: Two arguments(src, dest) is required.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'p': // `-p` option
                if (argc == 3) {
                    format_passwd(argv[2]);
                } else {
                    fprintf(stderr, "Invalid arguments: A argument(filename) is required.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case 'x': // `-x` option
                if (argc == 3) {
                    print_hexdump(argv[2]);
                } else {
                    fprintf(stderr, "Invalid arguments: A argument(filename) is required.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                fprintf(stderr, "Invalid option\n");
                exit(EXIT_FAILURE);
            }
        } else {
            print_file(argv[1]);
        }
    } else {
        fprintf(stderr, "Invalid arguments\n");
        exit(EXIT_FAILURE);
    }
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

void format_passwd(char* filename) {
    FILE* stream = fopen(filename, "r");
    if (stream == NULL) {
        perror("Fail to open");
        exit(EXIT_FAILURE);
    }
    const char* fieldnames[] = { "name", ", password", ", UID", ", GID", ", GECOS", ", directory", ", shell" };
    char line[MAX_LINE_LENGTH + 1];
    while (fgets(line, MAX_LINE_LENGTH, stream) != NULL) {
        int i = 0;
        char* field = strtok(line, ":");
        while (field != NULL) {
            printf("%s: %s", fieldnames[i], field);
            i += 1;
            field = strtok(NULL, ":");
        }
    }
    fclose(stream);
}

void print_directory(char* dirname) {
    DIR* dirp = opendir(dirname);
    if (dirp == NULL) {
        perror("Fail to open");
        exit(EXIT_FAILURE);
    }
    struct dirent* dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            printf("%s\n", dp->d_name);
        }
    }
    closedir(dirp);
}

void print_file(char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Fail to open");
        exit(EXIT_FAILURE);
    }
    char buf[BUFFER_SIZE];
    int chunk;
    while ((chunk = read(fd, buf, BUFFER_SIZE))) {
        write(STDOUT_FILENO, buf, chunk);
    }
    close(fd);
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
