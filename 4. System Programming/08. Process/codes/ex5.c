#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
   int x,y;
   x=fork();
   y=fork();
   printf("hello: %d %d\n", x, y);
}
