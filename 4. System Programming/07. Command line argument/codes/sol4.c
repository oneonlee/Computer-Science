// 파일 헤더
#include <fcntl.h>
// 입출력 헤더
#include <stdio.h>
// 시스템 헤더
#include <stdlib.h>
// stat 구조체 헤더
#include <sys/stat.h>
// 파일 헤더
#include <unistd.h>

// 프로그램 인자를 받는 main 함수
int main(int argc, char* argv[]) {
    // argc는 인자 갯수
    // argv는 인자 내용
    if (argc == 4) { // 인자 갯수가 3개일 때만 작동, 프로그램 명 포함되니 argc는 4임
        int fd = open(argv[1], O_RDWR, 00777); // 읽기쓰기 모드로 파일 열기
        // fd는 파일 디스크립터
        if (fd == -1) { // 만약 파일 열기에 실패하면
            perror("Fail to open"); // 오류 메세지를 출력하고
            exit(EXIT_FAILURE); // 실패 반환 코드로 프로그램 종료 
        }
        struct stat s; // 파일 구조체 선언
        // s는 파일 구조체로 파일에 대한 정보를 담을 예정
        fstat(fd, &s); // fd의 정보를 s에 담음
        char* buf = malloc(sizeof(char) * s.st_size); // 파일 크기만큼 메모리를 동적할당 함
        // buf는 읽은 파일을 내용을 담을 배열임 
        read(fd, buf, s.st_size); // 파일 내용을 모두 읽어서 buf에 저장
        for (int i = 0; i < s.st_size; i += 1) { // 파일 처음부터 끝까지 buf 배열을 순회하며
            // i는 현재 검사중인 buf 위치
            if (buf[i] == argv[2][0]) { // buf[i] 문자가 두번쨰 인자면(문자기 때문에 [0]으로 가져옴)
                buf[i] = argv[3][0]; // buf[i]를 세번쨰 인자로 치환한다. (문자기 때문에 [0]으로 가져옴)
            }
        }
        lseek(fd, 0, SEEK_SET); // 파일 맨 앞으로 돌아와서
        write(fd, buf, s.st_size); // buf를 파일에 덮어쓰운다.
        free(buf); // 동적할당한 메모리를 해지한다.
        close(fd); // 사용한 파일 디스크립터를 해지한다.
    } else {
        fprintf(stderr, "Invalid arguments\n"); // 표준오류출력으로 메세지를 출력한다,
        exit(EXIT_FAILURE); // 실패 반환 코드로 프로그램 종료 
    }
    return 0; // 0으로 종료
}
