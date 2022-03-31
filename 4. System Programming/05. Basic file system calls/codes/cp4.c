#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
	int x, y; char buf[20];
	x=open("f2", O_RDONLY, 00777);
	for(;;){
		y=read(x, buf, 1);
		if(y==0) break;
		printf("%x %d %c\n",buf[0],buf[0],buf[0]);
	}
	return 0;
}
