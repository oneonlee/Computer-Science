#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/select.h>

#define BUFFER_SIZE 50
#define SERV_TCP_PORT 8739
#define SERV_ADDR "165.246.38.151" //"192.168.50.122"

int main()
{
    int x, y, i;
    struct sockaddr_in serv_addr;
    char buf[BUFFER_SIZE];
    printf("Hi, I am the client\n");

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_ADDR);
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    // open a tcp socket
    if ((x = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket creation error\n");
        exit(1);
    }
    printf("socket opened successfully. socket num is %d\n", x);

    // connect to the server
    if (connect(x, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("can't connect to the server\n");
        exit(1);
    }

    printf("client => serv : (Enter hello) ");
    fgets(buf, BUFFER_SIZE - 1, stdin);
    write(x, buf, strlen(buf) - 1); // send "hello"

    y = read(x, buf, 50); // read "name?"
    buf[y] = '\0';
    printf("serv => client : %s\n", buf);

    if (strcmp(buf, "name?") != 0)
    {
        fprintf(stderr, "Error occurred by the protocol.\n");
        close(x);
        exit(EXIT_FAILURE);
    }

    printf("client => serv : (Enter name) ");
    fgets(buf, BUFFER_SIZE - 1, stdin);
    write(x, buf, strlen(buf) - 1); // send name

    y = read(x, buf, BUFFER_SIZE - 1); // read "Ready?"
    buf[y] = '\0';
    printf("serv => client : %s\n", buf); // ex5 : print server message
    if (strcmp(buf, "Ready?") != 0)
    {
        fprintf(stderr, "Error occurred by the protocol.\n");
        close(x);
        exit(EXIT_FAILURE);
    }
    printf("client => serv : (Enter yes/no) ");
    fgets(buf, BUFFER_SIZE - 1, stdin); // ex5 : enter "yes"
    write(x, buf, strlen(buf) - 1);     // ex5 : send "yes"

    y = read(x, buf, BUFFER_SIZE - 1); // ex5 : read "client list"s
    buf[y] = '\0';
    printf("serv => client : %s\n", buf); // ex5 : print server message ("client list"s)
    printf("client => serv : (Enter partner) ");
    fgets(buf, BUFFER_SIZE - 1, stdin); // ex5 : enter client lists
    write(x, buf, strlen(buf) - 1);     // ex5 : send client

    y = read(x, buf, BUFFER_SIZE - 1); // ex5 : read "Go!"
    buf[y] = '\0';
    printf("serv => client : %s\n", buf); // ex5 : print server message ("Go!")

    if (strcmp(buf, "Go!") != 0)
    {
        fprintf(stderr, "Error occurred by the protocol.\n");
        close(x);
        exit(EXIT_FAILURE);
    }

    int ch = fork(); // ex4 : 프로세스 복제
    // ex4 : child는 송신 담당, parents는 수신 담당
    if (ch == 0)
    {
        printf("(Chat)\n");

        while (1)
        {
            fgets(buf, BUFFER_SIZE - 1, stdin);
            write(x, buf, strlen(buf) - 1);
        }
    }
    else
    {
        while (1)
        {
            y = read(x, buf, BUFFER_SIZE - 1);
            if (y > 0)
            {
                buf[y] = '\0';
                printf("%s\n", buf);
            }
        }
    }

    close(x); // disconect the communication

    return 0;
}