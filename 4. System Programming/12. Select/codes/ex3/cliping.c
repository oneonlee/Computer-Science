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

#define SERV_TCP_PORT 8739
#define SERV_ADDR "165.246.38.151" //"192.168.50.122"

int main()
{
    int x, y;
    struct sockaddr_in serv_addr;
    char buf[50];
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
    // now start ping-pong-pang-pung protocol
    printf("enter ping\n");
    gets(buf);
    write(x, buf, strlen(buf)); // send "ping"
    y = read(x, buf, 50);       // read "pong"
    write(1, buf, y);           // show it
    printf("\n");

    printf("enter pang\n");
    gets(buf);
    write(x, buf, strlen(buf)); // send "ping"
    y = read(x, buf, 50);       // read "pung"
    write(1, buf, y);
    printf("\n");

    printf("enter ping\n");
    gets(buf);
    write(x, buf, strlen(buf)); // send "ping"
    y = read(x, buf, 50);       // read "protocol completed"
    write(1, buf, y);
    printf("\n");

    close(x); // disconect the communication
}