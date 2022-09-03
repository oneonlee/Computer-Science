#include <stdio.h>
#include <unistd.h>

int main(){
   execve("./ex1",0 , 0); // change to ./ex1 with no additional argument
   printf("I am ex2\n");
}
