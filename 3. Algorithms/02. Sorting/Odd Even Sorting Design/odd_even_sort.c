#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N 100000

void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

void oddEvenSort(int arr[], int n) {
    int isSorted = FALSE; 
 
    while (!isSorted) {
        isSorted = TRUE;
 
        for (int i = 0; i <= n-2; i = i+2) {
            if (arr[i] > arr[i+1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                isSorted = FALSE;
              }
        }

        // N이 클 경우 주석처리
        printf("odd index\n");
        printArray(arr, n);
        
        for (int i = 1; i <= n-2; i = i+2) {
            if (arr[i] > arr[i+1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;

                isSorted = FALSE;
            }
        }

        // N이 클 경우 주석처리
        printf("even index\n");
        printArray(arr, n);
    }
}

int main()
{
    int arr[] = {2, 10, 5, 3, 7, 9, 4, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    oddEvenSort(arr, n);

    printf("최종 정렬 결과");
    printArray(arr, n);
    
    // N 값이 큰 경우 동적할당 사용
    // 아래 코드 사용할 경우 oddEvenSort함수에서 출력부분 주석처리 할 것

    // int *a = malloc(sizeof(int *) * N);
    // double start_time;

    // for (int i = 0; i < N + 1; i++) {
    //         a[i] = 	(rand() % 10000) + 1;
    //     }

    // srand(time(NULL));
    // start_time = clock();
    // oddEvenSort(a, N);
    // printf("Odd-Even 정렬 실행 시간 (N = %d): %.0f초\n", N, (clock() - start_time) / CLOCKS_PER_SEC);

    // free(a); // 메모리 해제

    return 0;
}