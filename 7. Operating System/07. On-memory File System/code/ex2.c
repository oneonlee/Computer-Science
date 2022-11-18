#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char buf[100];
    int x = open("/aa/bb", O_RDONLY, 00777);
    int y = fork();
    int z;

    if (y == 0)
    {
        z = read(x, buf, 10);
        buf[z] = 0;
        printf("child read %s\n", buf);
    }
    else
    {
        z = read(x, buf, 10);
        buf[z] = 0;
        printf("parent read %s\n", buf);
    }

    return 0;
}