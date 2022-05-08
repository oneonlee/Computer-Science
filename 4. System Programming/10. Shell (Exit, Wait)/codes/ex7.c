#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int x, y, status;
    char buf[50];
    char *argv[10];
    char *token; // buf의 token
    int n;       // n은 *argv[]의 인덱스

    for (int i = 0; i < 10; i++)
    { // use a finite loop instead of an infinite one
        printf("$ ");
        // scanf("%s", buf);		// get command
        fgets(buf, 49, stdin);    // scanf 대신 fgets 사용
        buf[strlen(buf) - 1] = 0; // enter 입력 제거
        token = strtok(buf, " "); // 첫 token 생성

        n = 0; // 배열 인덱스 초기화
        while (token != NULL)
        {                              // token을 다 만들 때까지 반복
            argv[n] = token;           // token을 argv 배열에 저장
            token = strtok(NULL, " "); // 다음 token 생성
            n++;
        }
        argv[n] = 0; // 배열 끝 처리

        if (strcmp(argv[0], "exit") == 0)
            exit(1);

        x = fork();
        if (x == 0)
        { // child
            // child가 실행하는 명령어 출력
            printf("I am child to execute ");
            for (int j = 0; j < n; j++) // 배열의 길이(n)만큼 반복
                printf("%s ", argv[j]);
            printf("\n");

            // 절대경로로 입력 받았을 경우
            if (argv[0][0] == '.' || argv[0][0] == '/')
            {
                if (execve(argv[0], argv, NULL) < 0)
                {
                    perror("Fail to execute");
                    exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
            }

            // 상대경로로 입력 받았을 경우
            char *env = strtok(getenv("PATH"), ":");
            while (env != NULL)
            {
                char execname[50];
                sprintf(execname, "%s/%s", env, argv[0]); // 절대경로를 가진 명령어로 변환
                y = execve(execname, argv, 0);
                if (y < 0)
                {
                    env = strtok(NULL, ":");
                }
                else
                {
                    exit(EXIT_SUCCESS);
                }
            }
            perror("Fail to execute");
            exit(EXIT_FAILURE);
        }
        else
        {
            if (strcmp(argv[n - 1], "&") != 0) // 마지막이 &가 아닐 때만
                wait(&status);                 // child가 끝날 때까지 대기
            else                               // 아닌 경우
                sleep(1);                      // 대기하지 않고 1초동안 sleep
        }
    }
}
