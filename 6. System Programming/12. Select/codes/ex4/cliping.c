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
    // now start ping-pong-pang-pung protocol
    printf("client => serv : (Enter ping) ");
    fgets(buf, BUFFER_SIZE - 1, stdin);
    write(x, buf, strlen(buf) - 1); // send "ping"

    y = read(x, buf, 50); // read "pong"
    buf[y] = '\0';
    printf("serv => client : %s\n", buf);

    if (strcmp(buf, "pong") != 0)
    {
        fprintf(stderr, "Error occurred by the protocol.\n");
        close(x);
        exit(EXIT_FAILURE);
    }

    printf("client => serv : (Enter pang) ");
    fgets(buf, BUFFER_SIZE - 1, stdin);
    write(x, buf, strlen(buf) - 1); // send "pang"

    y = read(x, buf, BUFFER_SIZE - 1); // read "pung"
    buf[y] = '\0';
    printf("serv => client : %s\n", buf);

    if (strcmp(buf, "pung. Process completed. Start chatting.") != 0)
    {
        fprintf(stderr, "Error occurred by the protocol.\n");
        close(x);
        exit(EXIT_FAILURE);
    }

    int ch = fork();
    if (ch == 0)
    {
        printf("(Chat)\n");

        for (i = 0; i < 5; i++)
        {
            // printf("client => serv : (Chat) ");
            fgets(buf, BUFFER_SIZE - 1, stdin);
            write(x, buf, strlen(buf) - 1);
            // write(x, buf, BUFFER_SIZE - 1);
        }
        close(x);
        exit(0);
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            y = read(x, buf, BUFFER_SIZE - 1);
            if (y > 0)
            {
                buf[y] = '\0';
                printf("%s", buf);

                // printf("server => client: %s\n", buf);
            }
        }
    }

    close(x); // disconect the communication
}