#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
        char ChunkID[10]; // use char array for text data
        int ChunkSize; // use "int" for 4 byte data
        char Format[10];
        char Subchunk1ID[10];
	int Subchunk1Size;
        short AudioFormat, NumChannels;  // use "short" for 2 byte data
	int SampleRate, ByteRate;
	short BlockAlign, BitsPerSample;
	char Subchunk2ID[10];
	int Subchunk2Size;

        int x=open("./swvader03.wav", O_RDONLY, 00777);
        int y=read(x, ChunkID, 4);  // read first 4 bytes into ChunkID[]
        ChunkID[y]='\0';           // to print as a string
	read(x, &ChunkSize, 4); // read next 4 bytes and store at address &ChunkSize
	y=read(x, Format, 4); // read "WAVE"
        Format[y]='\0';
	Subchunk1ID[read(x, Subchunk1ID, 4)]='\0';
	read(x, &Subchunk1Size, 4);
        read(x, &AudioFormat, 2); // read next 2 bytes and store at address &AudioFormat
        read(x, &NumChannels, 2);
	read(x, &SampleRate, 4);
	read(x, &ByteRate, 4);
	read(x, &BlockAlign, 2);
	read(x, &BitsPerSample, 2);
	Subchunk2ID[read(x, Subchunk2ID, 4)]='\0';
	read(x, &Subchunk2Size, 4);

        printf("Chunk ID:%s\n", ChunkID);
        printf("Chunk Size:%d\n", ChunkSize);
        printf("Format:%s\n", Format); 
        printf("Subchunk1 ID:%s\n", Subchunk1ID);
        printf("Subchunk1 Size:%d\n", Subchunk1Size);
        printf("Audio Format:%d\n", AudioFormat);
        printf("Num Channels:%d\n", NumChannels);
        printf("Sample Rate:%d\n", SampleRate);
        printf("Byte Rate:%d\n", ByteRate);
        printf("Block Align:%d\n", BlockAlign);
        printf("Bits per Sample:%d\n", BitsPerSample);
        printf("Subchunk2 ID:%s\n", Subchunk2ID);
        printf("Sunchunk2 Size:%d\n", Subchunk2Size);
	return 0;
}
