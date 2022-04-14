#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
   int x;
   x=fork();
   printf("hello. my pid is %d\n", getpid());
   printf("and my parent pid is %d\n", getppid());
   for(;;);
}
