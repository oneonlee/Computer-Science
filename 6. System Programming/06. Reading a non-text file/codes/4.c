#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SUBCHUNK2SIZE_OFFSET 40

int main() {
	int x = open("sw2.wav", O_RDWR, 00777);

	int Subchunk2Size;
	lseek(x, SUBCHUNK2SIZE_OFFSET, SEEK_SET);
	read(x, &Subchunk2Size, 4);

	int halfSize = Subchunk2Size/2;

	
	char buf = 0;

	for (int i=0; i<halfSize; i++) {
		write(x, &buf, 1);
	}

	return 0;
}
