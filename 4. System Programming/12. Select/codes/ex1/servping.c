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

#define SERV_TCP_PORT 9004
#define SERV_ADDR "165.246.38.151"

void handle_protocol(int x, fd_set *pset);

void main()
{
    int s1, s2, i, x, y;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[50];
    socklen_t xx;

    printf("Hi, I am the server\n");

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_ADDR);
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    // open a tcp socket
    if ((s1 = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket creation error\n");
        exit(1);
    }
    printf("socket opened successfully. socket num is %d\n", s1);

    // bind ip
    x = bind(s1, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (x < 0)
    {
        printf("binding failed\n");
        exit(1);
    }
    printf("binding passed\n");
    listen(s1, 5);
    xx = sizeof(cli_addr);

    // now start ping-pong-pang-pung
    // pset remembers all sockets to monitor
    // rset is the copy of pset passed to select
    fd_set rset, pset;
    int maxfd = 50; // just monitor max 50 sockets

    FD_ZERO(&rset); // init rset
    FD_ZERO(&pset); // init pset

    // step 1. monitor conn req packet
    FD_SET(s1, &pset);
    // and loop on select
    for (i = 0; i < 20; i++)
    {                                           // should be infinite loop in real life
        rset = pset;                            // step 2
        select(maxfd, &rset, NULL, NULL, NULL); // step 3
        // now we have some packets
        for (x = 0; x < maxfd; x++)
        { // check which socket has a packet
            if (FD_ISSET(x, &rset))
            { // socket x has a packet
                // s1 is a special socket for which we have to do "accept"
                // otherwise do ping-pong-pang-pung
                if (x == s1)
                { // new client has arrived
                    // create a socket for this client
                    s2 = accept(s1, (struct sockaddr *)&cli_addr, &xx);
                    printf("new cli at socket %d\n", s2);
                    FD_SET(s2, &pset); // and include this socket in pset
                }
                else
                { // data packet. do ping-pong-pang-pung protocol
                    handle_protocol(x, &pset);
                }
            }
        }
    }
}
void handle_protocol(int x, fd_set *pset)
{
    // we have a data packet in socket x. do protocol
    int y;
    char buf[50];
    y = read(x, buf, 50); // read data
    buf[y] = 0;           // make it a string
    if (strcmp(buf, "ping") == 0)
    { // if it is a ping
        printf("received ping from socket %d\n", x);
        write(x, "pong", 4); // send pong
        printf("sent pong to socket %d\n", x);
    }
    else if (strcmp(buf, "pang") == 0)
    { // it it is a pang
        printf("received pang from socket %d\n", x);
        write(x, "pung", 4); // send pung
        printf("sent pung to socket %d\n", x);
        close(x);        // and stop the protocol
        FD_CLR(x, pset); // no more monitoring on this socket
    }
}