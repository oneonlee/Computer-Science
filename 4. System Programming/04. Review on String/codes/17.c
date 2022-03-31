#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* strs[100];
    int i = 0;
    while (1) {
        printf("Enter a name\n");
        strs[i] = new char [sizeof(char) * 100];
        gets(strs[i]);
        if (strcmp(strs[i], "bye\0") == 0) {
            printf("There were %d names.\nThe names were\n", i);
            break;
        }
        i += 1;
    }
    int j;
    for (j = 0; j < i; j += 1) {
        printf("%s ", strs[j]);
    }
    return 0;
}
