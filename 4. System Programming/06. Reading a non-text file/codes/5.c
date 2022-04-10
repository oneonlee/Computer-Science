#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SUBCHUNK2SIZE_OFFSET 40

int main() {
        int x = open("swcp.wav", O_RDWR, 00777);

        int Subchunk2Size;
        lseek(x, SUBCHUNK2SIZE_OFFSET, SEEK_SET);
        read(x, &Subchunk2Size, 4);

        int halfSize = Subchunk2Size/2;

        char buf = 0;

        for (int i=halfSize; i<Subchunk2Size; i++) {
		lseek(x, i, SEEK_SET);
		read(x, &buf, 1);
		lseek(x, i+SUBCHUNK2SIZE_OFFSET-halfSize, SEEK_SET);
                write(x, &buf, 1);
        }

        return 0;
}
