#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define TRUE 1
#define FALSE 0

void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void maxHeapify(int a[], int h, int m) {
    int v = a[h];
    int i;
    
    for (i = 2 * h; i <= m; i = i * 2) {
        if (i < m && a[i] < a[i + 1]) {
            i = i + 1;
        }
        
        if (v >= a[i]) { 
            break;
        } else {
            a[i / 2] = a[i]; 
        }
    }

    a[i / 2] = v;
}

void maxHeapSort(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(a, i, n);
    }

    for (int i = n - 1; i >= 1; i--) {
        swap(a, 1, i + 1);
        maxHeapify(a, 1, i);
    }
}

void minHeapify(int a[], int h, int m) {
    int v = a[h];
    int i;

    for (i = 2 * h; i <= m; i = i * 2) {
        if (i < m && a[i] > a[i + 1]) { 
            i = i + 1;
        }

        if (v <= a[i]) { 
            break;
        } else {
            a[i / 2] = a[i]; 
        }
    }

    a[i / 2] = v;
}

void minHeapSort(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        minHeapify(a, i, n);
    }

    for (int i = n - 1; i >= 1; i--) {
        swap(a, 1, i + 1);
        minHeapify(a, 1, i);
    }
}

void checkMaxSort(int a[], int n) {
    int i, sorted;
    sorted = TRUE;
    
    for (i = 1; i < n - 1; i++) { 
        if (a[i] > a[i + 1]) {
            sorted = FALSE;
        }

        if (!sorted)
            break;
    }
    
    if (sorted) {
        printf("Maxheap sorting complete!\n");
    } else {
        printf("Error during sorting...\n");
    }
}

void checkMinSort(int a[], int n) {
    int i, sorted;
    sorted = TRUE;
    
    for (i = 1; i < n - 1; i++) { 
        if (a[i] < a[i + 1]) { 
            sorted = FALSE;
        }

        if (!sorted)
            break;
    }
    
    if (sorted) {
        printf("Minheap sorting complete!\n");
    } else {
        printf("Error during sorting...\n");
    }
}

int main() {
    clock_t start, end;
    double result;

    int arr1[11] = {0, 6, 2, 8, 1, 3, 9, 4, 5, 10, 7};
    int arr2[11] = {0, 6, 2, 8, 1, 3, 9, 4, 5, 10, 7};
    
    int *maxInput = malloc(sizeof(int *) * N + 1);
    int *minInput = malloc(sizeof(int *) * N + 1);

    maxHeapSort(arr1, 11 - 1);
    printf("MaxHeap 정렬 결과\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    minHeapSort(arr2, 11 - 1);
    printf("MinHeap 정렬 결과\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", arr2[i]);
    }
    
    printf("\n");

    srand(time(NULL));
    
    for (int i = 0; i < N; i++) { 
        maxInput[i] = rand() % N;
        minInput[i] = maxInput[i];
    }

    start = clock();
    maxHeapSort(maxInput, N);
    end = clock();
    result = (double)(end - start);
    
    checkMaxSort(maxInput, N+1);
    printf("Maxheap sorting (N=%d) time cost: %.2f ms\n", N, result);

    start = clock();
    minHeapSort(minInput, N);
    end = clock();
    result = (double)(end - start);
    
    checkMinSort(minInput, N+1);
    printf("Minheap sorting (N=%d) time cost:  %.2f ms\n", N, result);

    return 0;
}
