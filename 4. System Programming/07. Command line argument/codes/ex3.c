#include <stdio.h>

int main(int argc, char * argv[]){
   printf("hi\n");
   printf("%d\n", argc);
   printf("%s\n", argv[0]); // the first command line argument . the program name
   printf("%s\n", argv[1]); // the second command line argument
   printf("%s\n", argv[2]); // the third command line argument
}
