#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(void) {
    int x, x1;
    x = open("f1", O_RDONLY, 00777);
    x1 = open("f2", O_WRONLY | O_CREAT | O_TRUNC, 00777);
    char buf[512];
    int cnt = 0;
    int y;
    for (;;) {
        y = read(x, buf + cnt, 1);
        if (y == 0)
            break;
        cnt++;
    }
    write(x1, buf, cnt);
    return 0;
}
