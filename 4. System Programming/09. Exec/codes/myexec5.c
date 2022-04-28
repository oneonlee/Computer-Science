#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
   char cmd[50];
   printf("command> ");
   fgets(cmd, 50, stdin);
   cmd[strlen(cmd) -1] = '\0';


   char *token[50];
   int i = 0;
   token[i] = strtok(cmd, " ");
   for(;;){
      i=i+1;
      token[i] = strtok(NULL, " ");
      if (token[i]==NULL) {
     	token[i] = 0;
	break;
      }
   }   
   execve(token[0], token, 0);  
}
