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
#define SERV_ADDR "192.168.50.122" // "165.246.240.101" //"165.246.38.151"

int main()
{
    int s1, s2, x, y, k, chpid;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[50];
    socklen_t xx;

    printf("========== Hi, I am the server! ==========\n");

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = PF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_ADDR);
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    // open a tcp socket
    if ((s1 = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket creation error\n");
        exit(1);
    }
    printf("Socket opened successfully. Socket num is %d\n", s1);

    // bind ip
    x = bind(s1, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (x < 0)
    {
        printf("Binding failed\n");
        exit(1);
    }
    printf("Binding passed\n");
    listen(s1, 5);
    xx = sizeof(cli_addr);
    s2 = accept(s1, (struct sockaddr *)&cli_addr, &xx);
    printf("We passed accept. New socket num is %d\n", s2);

    k = fork();
    if (k == 0) // child will keep reading
    {
        printf("Now I am connected to the client.\n");
        chpid = getpid();
        // read msg from client
        for (int c = 0; c < 10; c++)
        {
            y = read(s2, buf, 50 - 1);
            buf[y] = '\0';
            printf("Client : %s\n", buf);

            if (strcmp(buf, "bye") == 0)
            {
                break;
            }
        }
        kill(getppid(), 15); // kill parent process
    }
    else // parent keep writing
    {
        // send msg to the client
        for (int p = 0; p < 10; p++)
        {
            // printf("Server : ");
            fgets(buf, 50 - 1, stdin);
            buf[strlen(buf) - 1] = '\0';
            write(s2, buf, strlen(buf));
            if (strcmp(buf, "bye") == 0)
            {
                kill(chpid, 15); // kill child process
                break;
            }
        }
    }

    close(s2); // disconnect the connection
    close(s1); // close the original socket
}
