#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
   int x,y;
   x=getpid();
   y=getppid();
   printf("PID:%d PPID:%d\n", x, y);
   for(;;);   // to make this process alive
}
