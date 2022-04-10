#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void show_file(char * fname);
void display_content(int x); // function prototype

int main(int argc, char *argv[]){
    if (argc >= 2){
    	show_file(argv[1]);
    }
    if (argc >= 3){
	show_file(argv[2]);
    }
}

void show_file(char *fname){
    int x;
    x=open(fname, O_RDONLY, 00777); // open the specified file
    if (x==-1){ // if there is an error
        perror("error in open"); // report it
        exit(1); // and stop the program
    }
    display_content(x);
}

void display_content(int x){ // display the content of file x in the screen
    char buf[20];
    int y;
    for(;;){
        y=read(x, buf, 20); // read max 20 bytes
        if (y==0) break; // if end-of-file, get out
        write(1, buf, y); // write to terminal
    }
}
