#include <stdio.h>
#include <string.h>

int main() {
    char * x[10];
    x[0]="hi"; x[1]="bye"; x[2]="hello";
    printf("%s %s %s\n", x[0],x[1],x[2]);
}
