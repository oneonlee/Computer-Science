#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
int A[8192][8192];

double getUnixTime()
{
    struct timeval tv;
    gettimeofday(&tv, (void *)NULL);        // get current time
    return (tv.tv_sec + tv.tv_usec / 1.0e6) // return it in seconds
}

int main()
{
    int i, j;
    double stime, etime, diff;

    stime = getUnixTime(); // starting time
    syscall(58);           // display pfcnt

    for (i = 0; i < 8192; i++)
        for (j = 0; j < 8192; j++)
            A[i][j] = 3;

    syscall(58);           // display pfcnt again
    etime = getUnixTime(); // ending time
    diff = etime - stime;  // the difference
    printf("The elapsed time: %f\n", diff);

    return 0;
}