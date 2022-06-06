#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

#define SERV_TCP_PORT 35530
#define SERV_ADDR "192.168.50.122" //"165.246.38.151"

int main()
{
    int x, y, k, chpid;
    struct sockaddr_in serv_addr;
    char buf[50];
    printf("========== Hi, I am the client! ==========\n");

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_ADDR);
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    // open a tcp socket
    if ((x = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error\n");
        exit(1);
    }
    printf("Socket opened successfully. Socket num is %d\n", x);

    // connect to the server
    if (connect(x, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Can't connect to the server\n");
        exit(1);
    }

    k = fork();
    if (k == 0) // child will keep writing
    {
        chpid = getpid();
        // send msg to the server
        printf("Now I am connected to the server.\n");
        for (int c = 0; c < 10; c++)
        {
            // printf("Client : ");
            fgets(buf, 50 - 1, stdin);
            buf[strlen(buf) - 1] = '\0';
            write(x, buf, strlen(buf));
            if (strcmp(buf, "bye") == 0)
            {
                kill(getppid(), 15); // kill parent process
                break;
            }
        }
    }

    else
    {
        // read from server
        for (int p = 0; p < 10; p++)
        {
            y = read(x, buf, 50 - 1);
            buf[y] = '\0';
            printf("Server : %s\n", buf);

            if (strcmp(buf, "bye") == 0)
            {
                break;
            }
        }
        kill(chpid, 15); // kill child process
    }
    close(x); // disconect the communication
}
