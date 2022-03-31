#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
	int x1, x2, y;
	char buf[50];

	x1=open("f1", O_RDONLY, 00777); // open f1 for reading
	x2=open("f2", O_RDWR|O_CREAT|O_TRUNC, 00777); // open f2 for writing
	y=read(x1, buf, 20); // read max 20 bytes. return actual number of bytes read in y.
	write(x2, buf, y); // write y bytes in buf to f2

	return 0;
}
