#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#define SERV_TCP_PORT 32330
#define SERV_ADDR "172.30.1.29"

int main()
{
   int s1, s2, x, y, ch;
   struct sockaddr_in serv_addr, cli_addr;
   char buf[50];
   char fileName[50];
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

   // listen
   listen(s1, 5);
   xx = sizeof(cli_addr);

   // now wait for clients
   for (int i = 0; i < 20; i++)
   {
      s2 = accept(s1, (struct sockaddr *)&cli_addr, &xx);
      printf("we passed accept. new socket num is %d\n", s2);

      // now we have a new client. make a child to handle it
      ch = fork();
      if (ch == 0)
      { // this child will handle the newly arrived client
         // process simple ftp protocol

         // read msg from client
         y = read(s2, buf, 50);
         buf[y] = 0;
         printf("client => server: %s\n", buf);

         if (strcmp(buf, "hello") == 0)
         {
            char *init_response = "What file do you want?";
            write(s2, init_response, strlen(init_response));
            printf("server => client: %s\n", init_response);

            wait(0);

            // read name of the file from client
            y = read(s2, fileName, 50);
            fileName[y] = 0;
            printf("client => server: %s\n", fileName);

            // send contents of the file
            int fd = open(fileName, O_RDONLY, 00777);

            for (;;)
            {
               y = read(fd, buf, 50);
               if (y == 0)
                  break;
               buf[y] = '\0';
               write(s2, buf, strlen(buf));
               printf("%s", buf);
            }
            buf[0] = -1;
            write(s2, buf, 1);
         }
         close(s2); // disconnect the connection
         close(s1); // close the original socket
         exit(0);   // child has completed the mission. exit now.
      }
   }
   return 0;
}
