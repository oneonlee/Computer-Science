#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#define SERV_TCP_PORT 32330
#define SERV_ADDR "172.30.1.29" //"165.246.240.109"//"192.168.50.122"//"165.246.38.151"

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

   // send msg to the server
   printf("client => server: ");
   char *init_request = "hello";
   write(x, init_request, strlen(init_request));
   printf("%s\n", init_request);

   // read from server
   y = read(x, buf, 50);
   buf[y] = 0;
   printf("server => client: %s\n", buf);

   if (strcmp(buf, "What file do you want?") == 0)
   {
      printf("client => server: ");

      // send name of the file to the server
      fgets(buf, 50, stdin);
      buf[strlen(buf) - 1] = '\0';
      write(x, buf, strlen(buf));

      // receive contents of the file
      char *endString = "END";
      printf("server => client: \n");
      for (;;)
      {
         y = read(x, buf, 50);
         buf[y] = '\0';
         if (buf[y - 1] == -1)
         {
            buf[y - 1] = ' ';
            printf("%s", buf);
            break;
         }
         printf("%s", buf);
      }
   }
   close(x); // disconect the communication
}
