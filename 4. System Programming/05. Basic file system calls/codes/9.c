#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 20

int main() {
        char src[20];
        char dest[20];

        printf ("Enter src file name\n");
        scanf("%s", src);

        printf ("Enter dest file name\n");
        scanf("%s", dest);

        int x1 = open(src,  O_RDONLY, 00777);
        int x2 = open(dest, O_RDWR|O_CREAT|O_TRUNC, 00777);
        char buf[BUFFER_SIZE];
        int y;

        for(;;){
                y = read(x1, buf, 20);
                if (y==0) break;
                write(x2, buf, y);
        }
        
        printf("%s is copied into %s successfully.", src, dest);

        return 0;
}
