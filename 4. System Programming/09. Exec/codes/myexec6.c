#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    for (int idx = 0; idx < 5; idx += 1) {
        if (fork() == 0){
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
        } else {
            wait(NULL);
        }
    }
    return 0;
}

