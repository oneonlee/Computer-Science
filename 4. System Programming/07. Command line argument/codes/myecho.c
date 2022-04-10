#include <stdio.h>
int main(int argc, char *argv[]){
    int i;
    for(i=1;i<argc;i++){ // skip program name
        printf("%s ", argv[i]); // and display all the arguments
    }
    printf("\n");
}
