#include <stdio.h>
#include <string.h>  // you need this header file for string functions
void main(){
   char x, y;
   x='a'; y=97;
   printf("%d %c %d %c\n", x, x, y, y);
   char * x1 = "hello";
   printf("%s %p %s %p\n", x1, x1, "hello", "hello"); // use %p for address
}

