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

void handle_protocol(int x, fd_set *pset, int state[]);
void handle_state_1(int x, fd_set *pset, char *buf, int state[]);
void handle_state_2(int x, fd_set *pset, char *buf, int state[]);
void handle_state_3(int x, fd_set *pset, char *buf, int state[]);

int main()
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
    int maxfd = 50;   // just monitor max 50 sockets
    int state[maxfd]; // ex2 : 각 소켓별 상태를 저장하는 배열 선언

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
                    state[s2] = 1; // ex2 : 해당 소켓의 상태를 1로 초기화
                    printf("new cli at socket %d\n", s2);
                    FD_SET(s2, &pset); // and include this socket in pset
                }
                else
                { // data packet. do ping-pong-pang-pung protocol
                    handle_protocol(x, &pset, state);
                }
            }
        }
    }
}

void handle_state_1(int x, fd_set *pset, char *buf, int state[])
{
    // socket x is in state 1. Expecting "ping" in buf. if we have ping, send "pong" and
    // just update state[x]=2; otherwise send error message and disconnect the connection

    if (strcmp(buf, "ping") == 0)
    { // if it is a ping
        printf("received ping from socket %d\n", x);
        write(x, "pong", 4); // send pong
        printf("sent pong to socket %d\n", x);
    }
    else
    {
        printf("received other message from socket %d\n", x);
        write(x, "Error! You should enter \"ping\". Try again!", 44); // send pong
        printf("sent error message to socket %d\n", x);
        close(x);        // ex 2-1 : and stop the protocol
        FD_CLR(x, pset); // ex 2-1 : no more monitoring on this socket
    }
    state[x] = 2; // ex 2 : 상태 값을 2로 설정
}

void handle_state_2(int x, fd_set *pset, char *buf, int state[])
{
    // socket x is in state 2. we are expecting "pang" in buf. If we have "pang", send "pung"
    // and close the connection. If we didn’t receive “pang”, send “protocol error” to the
    // client and disconnect.
    if (strcmp(buf, "pang") == 0)
    { // it it is a pang
        printf("received pang from socket %d\n", x);
        write(x, "pung", 4); // send pung
        printf("sent pung to socket %d\n", x);
    }

    else
    {
        printf("received other message from socket %d\n", x);
        write(x, "Error! You should enter \"pang\". Try again!", 44); // send pong
        printf("sent error message to socket %d\n", x);
        close(x);        // and stop the protocol
        FD_CLR(x, pset); // no more monitoring on this socket
    }

    state[x] = 3; // ex 3 : 상태 값을 3으로 설정
}

void handle_state_3(int x, fd_set *pset, char *buf, int state[])
{
    // socket x is in state 2. we are expecting "pang" in buf. If we have "pang", send "pung"
    // and close the connection. If we didn’t receive “pang”, send “protocol error” to the
    // client and disconnect.
    if (strcmp(buf, "ping") == 0)
    { // it it is a pang
        printf("received pang from socket %d\n", x);
        write(x, "protocol completed", 18); // send "protocol completed"
        printf("protocol completed (socket %d)\n", x);
    }

    else
    {
        printf("received other message from socket %d\n", x);
        write(x, "Error! You should enter \"ping\". Try again!", 44); // send pong
        printf("sent error message to socket %d\n", x);
    }
    close(x);        // and stop the protocol
    FD_CLR(x, pset); // no more monitoring on this socket
}

void handle_protocol(int x, fd_set *pset, int state[])
{
    // we have data packet in socket x. state[x] shows the state of socket x.
    // handle the protocol.
    int y;
    char buf[50];
    y = read(x, buf, 50); // read data
    buf[y] = 0;           // make it a string
    if (state[x] == 1)    // ex2 : 상태가 1인 경우
        handle_state_1(x, pset, buf, state);
    else if (state[x] == 2) // ex2 : 상태가 2인 경우
        handle_state_2(x, pset, buf, state);
    else if (state[x] == 3) // ex3 : 상태가 3인 경우
        handle_state_3(x, pset, buf, state);
}