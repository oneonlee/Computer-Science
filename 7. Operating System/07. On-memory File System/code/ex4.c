#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void my_show_fpos()
{
    syscall(56);
}

int main(void)
{
    char buf[25];
    int x = open("f1", O_RDONLY);
    int y = open("f2", O_RDONLY);

    my_show_fpos(); // f_pos right after opening two files
    read(x, buf, 10);
    read(y, buf, 20);
    my_show_fpos(); // f_pos after reading some bytes

    return 0;
}