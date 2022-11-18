#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char buf[100];
    int x = open("/aa/bb", O_RDONLY, 00777);
    int y = read(x, buf, 10);
    buf[y] = '\0';
    printf("we read %s\n", buf);

    lseek(x, 20, SEEK_SET);
    y = read(x, buf, 10);
    buf[y] = '\0';
    printf("we read %s\n", buf);

    int x1 = dup(x);
    y = read(x1, buf, 10);
    buf[y] = '\0';
    printf("we read %s\n", buf);

    link("/aa/bb", "/aa/newbb");
    int x2 = open("/aa/newbb", O_RDONLY, 00777);
    y = read(x2, buf, 10);
    buf[y] = '\0';
    printf("we read %s\n", buf);

    return 0;
}