#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char * env = strtok(getenv("PATH"), ":"); 
    while (env != NULL) {
	printf("%s\n", env);
	env = strtok(NULL, ":");
    }
    return 0;
}
