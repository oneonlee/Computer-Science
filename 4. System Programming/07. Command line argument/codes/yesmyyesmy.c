// a program that modifies any given wave file such that it repeats the first half of the sound.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SUBCHUNK2SIZE_OFFSET 40

int main(int argc, char *argv[]) {
        int x = open(argv[1], O_RDWR, 00777);

        int Subchunk2Size;
        lseek(x, SUBCHUNK2SIZE_OFFSET, SEEK_SET);
        read(x, &Subchunk2Size, 4);

        int halfSize = Subchunk2Size/2;

        char buf = 0;

        for (int i=SUBCHUNK2SIZE_OFFSET; i<SUBCHUNK2SIZE_OFFSET + halfSize; i++) {
		lseek(x, i, SEEK_SET);
		read(x, &buf, 1);
		lseek(x, i+halfSize, SEEK_SET);
                write(x, &buf, 1);
        }

        return 0;
}
