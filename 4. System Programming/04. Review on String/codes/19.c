#include <stdio.h>
#include <string.h>

int main() {
    char * strarr[10]={NULL};
    strarr[0] = new char [20];
    strcpy(strarr[0],"hello");
    strarr[1] = new char [20];
    strcpy(strarr[1],"bye");
    printf("%s %s\n", strarr[0], strarr[1]);
}
