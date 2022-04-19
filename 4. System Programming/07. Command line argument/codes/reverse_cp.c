#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_LINES_COUNT 100

int main(int argc, char* argv[]) {
    if (argc == 3) {
        FILE* in_stream = fopen(argv[1], "r");
        FILE* out_stream = fopen(argv[2], "w");
        if (in_stream == NULL || out_stream == NULL) {
            perror("Fail to open");
            exit(EXIT_FAILURE);
        }
        char buf[MAX_LINES_COUNT][MAX_LINE_LENGTH + 1];
        int idx = 0;
        while (fgets(buf[idx++], MAX_LINE_LENGTH, in_stream) != NULL) {
        }
        while (idx > 0) {
            fprintf(out_stream, "%s", buf[--idx]);
        }
        fclose(in_stream);
        fclose(out_stream);
    } else {
        fprintf(stderr, "Invalid arguments\n");
    }
    return 0;
}

