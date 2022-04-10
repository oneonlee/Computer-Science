#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	char chunkID[10];
	int chunkSize;
	char format[10];
	short AudioFormat;
	short NumChannel;
	int SampleRate;
	int ByteRate;
	short BlockAlign;
	short BitsPerSample;
	char data[20];
	int x,y;

	x = open("./swvader03.wav", O_RDONLY, 00777);
	x = read(x, chunkID, 4);
	chunkID[y] = 0;
	y = read(x, &chunkSize, 4);
	y = read(x, format, 4);
	format[y] = 0;

	printf("chunkID : %s ", chunkID);
	printf("chunkSize : %d ", chunkSize);
	printf("format : %s ", format);
	printf("\n");

	y = read(x, chunkID, 4);
	chunkID[y] = 0;
	y = read(x, &chunkSize, 4);
	y = read(x, &AudioFormat, 2);
	y = read(x, &NumChannel, 2);
	y = read(x, &SampleRate, 4);
	y = read(x, &ByteRate, 4);
	y = read(x, &BlockAlign, 2);
	y = read(x, &BitsPerSample, 2);

	printf("chunkID : %s ", chunkID);
	printf("chunkSize : %d ", chunkSize);
	printf("AudioFormat : %d ", AudioFormat);
	printf("NumChannel : %d ", NumChannel);
	printf("ByteRate : %d ", ByteRate);
	printf("BlockAlign : %d ", BlockAlign);
	printf("BitsPerSample : %d", BitsPerSample);
	printf("\n");

	y = read(x, chunkID, 4);
	chunkID[y] = 0;
	y = read(x, &chunkSize, 4);

	printf("chunkID : %s ",chunkID);
	printf("chunkSize : %d", chunkSize);
	printf("\n");

	return 0;
}
