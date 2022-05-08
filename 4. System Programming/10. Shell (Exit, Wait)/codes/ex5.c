#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int x, y, status;
	char buf[50];
	char * argv[10];
	char * token;	// buf의 token
	int  n;		// n은 *argv[]의 인덱스 

	for (int i=0; i<10; i++) { // use a finite loop instead of an infinite one
		printf("$ ");
		//scanf("%s", buf);		// get command
		fgets(buf, 49, stdin);		// scanf 대신 fgets 사용
		buf[strlen(buf)-1] = 0;		// enter 입력 제거
		token = strtok(buf, " ");	// 첫 token 생성
	
		n = 0;		// 배열 인덱스 초기화
		while (token != NULL) {			// token을 다 만들 때까지 반복
			argv[n] = token;		// token을 argv 배열에 저장
			token = strtok(NULL, " ");	// 다음 token 생성
			n++;
		}
		argv[n] = 0;	// 배열 끝 처리

		if (strcmp(argv[0], "exit") == 0) exit(1);

		x = fork();
		if (x == 0) { // child
			// child가 실행하는 명령어 출력
			printf("I am child to execute ");
			for(int j=0; j<n; j++)	// 배열의 길이(n)만큼 반복
				printf("%s ", argv[j]);
			printf("\n");

			y = execve(argv[0], argv, 0);
			if (y < 0) {
				perror("exec failed");
				exit(1);
			}
		} else {
			if (strcmp(argv[n-1], "&") != 0) // 마지막이 &가 아닐 때만
				wait(&status);		// child가 끝날 때까지 대기
			else				// 아닌 경우
				sleep(1);		// 대기하지 않고 1초동안 sleep
		}
	}
}
