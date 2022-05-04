#include <stdio.h>
#include <string.h>

// 재시작 위치 
int next[50];

void InitNext(char *p) {
    int i, j, M = strlen(p);
    next[0] = -1; // 0번째 인덱스는 항상 0으로 설정

    for (i = 0, j = -1; i < M; i++, j++) {
        // j가 -1부터 시작하는 것은 혹시 위에서 next[0]에 -1을 할당하지 않은 경우 대비
        // 재시작 위치를 구하는 것이기 때문에 i가 j 보다 1 더 큼
        next[i] = (p[i] == p[j]) ? next[j] : j;
        while((j >= 0) &&(p[i] != p[j]))
            j = next[j];
    }
}

int KMP(char *p, char *t) {
    int i, j, M = strlen(p), N = strlen(t);
    
    // next배열에 재시작 위치 설정
    InitNext(p);
    
    for (i = 0, j = 0; j < M && i < N; i++, j++) {
        while((j >= 0) && (t[i] != p[j]))
            j = next[j];
    }

    if (j == M)
        return i - M;
    else
        return i;
}

int main() {
    char text[500] = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";
    char pattern[50] = "algorithm";
    int M, N, pos, previous = 0, i = 0;

    M = strlen(pattern);
    N = strlen(text);

    // break 만나야 끝남
    while (1) {
        pos = KMP(pattern, text + i); // 패턴이 나타난 현재 위치
        pos += previous;
        i = pos + M;

        if (i <= N)
            printf("패턴이 발생한 위치: %d\n", pos);
        else
            break;

        previous = i;
    }

    printf("탐색 종료");

    return 0;
}