#include <stdio.h>
#include <string.h>

int main(){
    char x[20];
    strcpy(x, "hello"); // this is ok
    x="hello"; // this is an error. "hello" is an address and we can't store address in
    // x which is not a pointer variable
}
