#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int x,y;
    char buf[20];

    x=open(argv[1], O_RDONLY, 00777); // open the specified file
    if (x==-1){ // if there is an error
        perror("error in open"); // report it
        exit(1); // and stop the program
    }
    for(;;){
        y=read(x, buf, 20); // read max 20 bytes
        if (y==0) break; // if end-of-file, get out
        write(1, buf, y); // write to terminal
    }
}
