#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void display_root_f1(void)
{
    char buf[100];
    int x = open("/f1", O_RDONLY);
    int y = read(x, buf, 100);
    buf[y] = '\0';
    printf("%s\n", buf);
}

void display_f1(void)
{
    char buf[100];
    int x = open("f1", O_RDONLY);
    int y = read(x, buf, 100);
    buf[y] = '\0';
    printf("%s\n", buf);
}

int main(void)
{
    display_root_f1();
    chroot(".");
    display_root_f1();
    display_f1();
    chdir("d1");
    display_f1();
    return 0;
}