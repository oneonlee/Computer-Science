#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void my_show_fpos()
{
    syscall(56);
}

int main(void)
{
    char buf[10];
    int f1 = open("./f1", O_RDONLY, 00777);
    int f2 = open("./f2", O_WRONLY, 00777);
    printf("f1 and f2 are %d %d\n", f1, f2); // make sure they are 3 and 4
    if (fork() == 0)
    {
        my_show_fpos();
        read(f1, buf, 1);
        sleep(2);
        my_show_fpos();
        write(f2, buf, 1);
    }
    else
    {
        sleep(1);
        my_show_fpos();
        read(f1, buf, 1);
        write(f2, buf, 1);
    }

    return 0;
}