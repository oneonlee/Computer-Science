// - state 1
//   - The server is expecting "hello" for this client.
//   - When "hello" arrives, the server sends "name?"
// - state 2
//   - The server is expecting client ID from this client.
//   - The server rembers this client's ID in `cli[x].name`, where `x` is the socket number of this client.
//   - The server asks "ready?".
// - state 3
//   - The server is expecting "yes" from this client.
//   - The server sends all client name whose state is greater than or equal to `3`.
// - state 4
//   - The server is expecting the chatting partner's ID from this client.
//   - The server remembers partner socket number in `cli[x].partner`.
//   - Send "go" to the client.
// - state 5
//   - The client is now in chatting session.
//   - The server is expecting some chat message from this client.
//   - The server sends this message to `cli[x].partner`.

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

struct client // ex 5 : 구조체 선언
{
    char name[20]; // ex 5 : 클라이언트 이름
    char age[5];   // ex 5 : 클라이언트 나이
    int partner;   // ex 6 : the socket number of the chatting partner of this client
    int state;
};

void handle_protocol(int x, fd_set *pset, int state[], struct client cli[]);
void handle_state_1(int x, fd_set *pset, char *buf, int state[], struct client cli[]);
void handle_state_2(int x, fd_set *pset, char *buf, int state[], struct client cli[]);
void handle_state_3(int x, fd_set *pset, char *buf, int state[], struct client cli[]);
void handle_state_4(int x, fd_set *pset, char *buf, int state[], struct client cli[]);
void handle_state_5(int x, fd_set *pset, char *buf, int state[], struct client cli[]);

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

    // pset remembers all sockets to monitor
    // rset is the copy of pset passed to select
    int maxfd = 50;   // just monitor max 50 sockets
    int state[maxfd]; // ex2 : 각 소켓별 상태를 저장하는 배열 선언

    struct client cli[50]; // ex5 : 구조체 생성
    for (i = 0; i < 50; i++)
        cli[i].state = 0; // ex7 : 모든 후보 소켓들의 초기 state는 0으로 설정

    fd_set rset, pset;
    FD_ZERO(&rset); // init rset
    FD_ZERO(&pset); // init pset

    // step 1. monitor conn req packet
    FD_SET(s1, &pset);
    // and loop on select
    for (i = 0; i < 40; i++)                    // ex6 : select 루프 횟수를 20에서 40으로 변경
    {                                           // should be infinite loop in real life
        rset = pset;                            // step 2
        select(maxfd, &rset, NULL, NULL, NULL); // step 3
        // now we have some packets
        for (x = 0; x < maxfd; x++)
        { // check which socket has a packet
            if (FD_ISSET(x, &rset))
            { // socket x has a packet
                // s1 is a special socket for which we have to do "accept"
                if (x == s1)
                { // new client has arrived
                    // create a socket for this client
                    s2 = accept(s1, (struct sockaddr *)&cli_addr, &xx);
                    cli[s2].state = 1; // ex7 : 새로 생성된 클라이언트 소켓의 상태를 1로 설정
                    printf("new cli at socket %d\n", s2);
                    FD_SET(s2, &pset); // and include this socket in pset
                }
                else
                {
                    handle_protocol(x, &pset, state, cli);
                }
            }
        }
    }
}

void handle_state_1(int x, fd_set *pset, char *buf, int state[], struct client cli[])
{
    if (strcmp(buf, "hello") == 0) // ex7 : "hello"를 받으면
    {
        printf("client at socket %d => serv: hello\n", x);
        write(x, "name?", 5); // ex7 : send "name?"
        printf("serv => client at socket %d: name?\n", x);
    }
    else
    {
        printf("client at socket %d => serv: other message\n", x);
        write(x, "Error! You should enter \"hello\". Try again!", 44); // send Error message
        printf("serv => client at socket %d: Error! You should enter \"hello\". Try again!\n", x);
        close(x);        // ex 2-1 : and stop the protocol
        FD_CLR(x, pset); // ex 2-1 : no more monitoring on this socket
    }
    cli[x].state = 2; // ex 2 : 상태 값을 2로 설정
}

void handle_state_2(int x, fd_set *pset, char *buf, int state[], struct client cli[])
{
    strcpy(cli[x].name, buf);                                    // ex7 : buf(이름)를 해당 소켓의 구조체의 이름 항목으로 복사
    printf("client at socket %d => serv: %s\n", x, cli[x].name); // 대답 출력
    write(x, "Ready?", 6);                                       // ex7 : "Ready?" 메시지 전송
    printf("serv => client at socket %d: Ready?\n", x);
    cli[x].state += 1; // ex3 : 상태 값을 3으로 설정
}

void handle_state_3(int x, fd_set *pset, char *buf, int state[], struct client cli[])
{
    int i;
    printf("client at socket %d => serv: %s\n", x, buf); // 대답 출력
    if (strcmp(buf, "yes") == 0)                         // ex7 : "Ready?"에 대한 대답으로 "yes"를 받으면
    {
        // ex7 : client list를 보냄
        strcpy(buf, "client list (");
        for (i = 0; i < 50; i++)
        {
            if (x != i && cli[i].state > 2)
            {
                strcat(buf, cli[i].name);
                strcat(buf, ", ");
            }
        }
        if (buf[strlen(buf) - 2] == ',')
        {
            buf[strlen(buf) - 2] = '\0';
        }
        strcat(buf, ")");
        write(x, buf, strlen(buf));
        printf("serv => client at socket %d: %s\n", x, buf);
        cli[x].state += 1;
    }
    else
    {
        printf("client at socket %d => serv: other message\n", x);
        write(x, "You are not ready yet!", 22); // ex7 : send Error message
        printf("serv => client at socket %d: You are not ready yet!\n", x);
        close(x);        // ex 2-1 : and stop the protocol
        FD_CLR(x, pset); // ex 2-1 : no more monitoring on this socket
    }
}

void handle_state_4(int x, fd_set *pset, char *buf, int state[], struct client cli[])
{
    int i;
    printf("client at socket %d => serv: %s\n", x, buf);
    for (i = 0; i < 50; i++)
    {
        if (x != i && cli[i].state > 2 && strcmp(cli[i].name, buf) == 0) // ex6 : 입력받은 chat partner(buf)와 동일한 client name이 있으면,
        {
            cli[x].partner = i; // ex6 : 해당 소켓 번호를 partner 변수에 저장
            write(x, "Go!", 3); // ex7 : chatting 시작 메시지 전송
            cli[x].state += 1;  // ex5 : 상태 값을 5으로 설정
            break;
        }
    }
}

void handle_state_5(int x, fd_set *pset, char *buf, int state[], struct client cli[]) // 채팅 송수신이 가능한 상태
{
    char msg[50];
    int len = sprintf(msg, "%s => %s : %s", cli[x].name, cli[cli[x].partner].name, buf);
    write(cli[x].partner, msg, len); // ex6 : partner에게 메세지 전송
    printf("%s\n", msg);
    cli[x].state++; // 상태 + 1
}

void handle_protocol(int x, fd_set *pset, int state[], struct client cli[])
{
    // we have data packet in socket x.
    // cli[x].state shows the state of socket x.
    // handle the protocol.
    int y;
    char buf[50];
    y = read(x, buf, 50);                            // read data
    buf[y] = 0;                                      // make it a string
    if (cli[x].state == 1)                           // ex2 : 상태가 1인 경우
        handle_state_1(x, pset, buf, state, cli);    // hello 도착, pong 전송 상태
    else if (cli[x].state == 2)                      // ex2 : 상태가 2인 경우
        handle_state_2(x, pset, buf, state, cli);    // pang 도착, pung 전송 상태
    else if (cli[x].state == 3)                      // ex5 : 상태가 3인 경우
        handle_state_3(x, pset, buf, state, cli);    // ex5 : name 도착, age 요청 상태
    else if (cli[x].state == 4)                      // ex5 : 상태가 3인 경우
        handle_state_4(x, pset, buf, state, cli);    // ex5 : name 도착, age 요청 상태
    else if (cli[x].state >= 5 && cli[x].state <= 9) // ex4 : 채팅 송수신이 가능한 상태 (sequence 완료)
        handle_state_5(x, pset, buf, state, cli);
    else if (cli[x].state == 10) // ex4 : 한 클라이언트가 채팅을 5번 이상 입력했다면,
    {
        close(x);        // 소켓을 닫고
        FD_CLR(x, pset); // pset에서 해당 소켓 clear
    }
}