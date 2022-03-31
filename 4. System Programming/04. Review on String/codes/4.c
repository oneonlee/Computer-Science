#include<stdio.h>
int main(){
   char x[128];
   for(int i=0;i<128;i++){
      x[i]=i;
   }
   for(int i=0;i<128;i++){
      printf("%d%c%d\n", x[i], x[i], x[i]);
   }
}
