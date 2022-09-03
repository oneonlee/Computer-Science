#include <stdio.h>
#include <string.h>

int main() {
   char x[10];
   strcpy(x, "hello");
   strcpy(x, "hi");
   for(int i=0;i<10;i++){
      printf("%d ", x[i]);
   }  
}
