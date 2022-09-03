#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int x,y;
    x=fork();
    printf("hello: %d\n", x);
    y=fork();
    printf("hello: %d\n", y);
}
