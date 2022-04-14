#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void checkSort(int a[], int n) {
    int i, sorted;
    sorted = TRUE;
    for (i = 0; i < n; i++) {
        if (a[i] > a[i+1]) {
            sorted = FALSE;
        }
        if (!sorted) {
            break;
        }
    }
    if (sorted) {
        printf("정렬 완료.\n");
    } else {
        printf("정렬 오류!!\n");
    }
}

// h값 변화시키면서 정답 확인
void shellSort(int a[], int n) {
    int i, j, h, v;
    for (h = 1; h < n; h = 3 * h + 1) {}
    for (; h > 0; h = h/3) {
        for (i = h + 1; i <= n; i++) {
            v = a[i];
            j = i;

            while (j > h && a[j-h] > v) {
                a[j] = a[j - h];
                j -= h;
            }

            a[j] = v;
        }
    }
}

int main() {
    int i, j;
    int N[5] = {100000, 500000, 1000000, 5000000, 10000000};
    
    for (i = 0; i < 5; i++) {
        int *a = malloc(sizeof(int *) * N[i]); // 동적 할당
        double start_time;

        a[0] = -1;
        srand(time(NULL));

        for (j = 1; j <= N[i] + 1; j++) {
            a[j] = rand();
        }

        start_time = clock();
        shellSort(a, N[i]);
        printf("증가식: 3h + 1, 감소식: h/3");
        printf("쉘 정렬 실행 시간 (N = %d): %.0f초\n", N[i], (clock() - start_time) / CLOCKS_PER_SEC);
        checkSort(a, N[i]);
        free(a); // 메모리 해제
    }

    return 0;
}