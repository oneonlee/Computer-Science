#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
   int x, i;
   for(i=0;i<5;i++){
      x=fork();
      if (x==0){ // child
         int k;
         for(k=0;k<10;k++){
            printf("%d-th child running %d-th iteration(pid: %d)\n", i, k, getpid());
	    fflush(stdout);         // to make printf work immediately
            sleep(1);              // sleep 1 second
        }
      } 
   }
   // now parent
   printf("parent exits\n");
}
