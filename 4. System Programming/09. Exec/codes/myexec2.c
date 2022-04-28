#include <stdio.h>
#include <unistd.h>

int main(){
   char *x[10];
   x[0]="/bin/ls";
   x[1]="-l";
   x[2]=0;              // argument list should end with 0
   execve(x[0], x, 0);  // change to /bin/cat with one argument f1
}
