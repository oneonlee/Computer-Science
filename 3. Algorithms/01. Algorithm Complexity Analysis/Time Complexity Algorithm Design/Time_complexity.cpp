#include <iostream>
#include <ctime>
using namespace std;

// 재귀함수로 구현(exp time)
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int i, j, k, input;
    float res_cb, res_exp;
    clock_t start_cb, start_exp, end_cb, end_exp;

    cin >> input;

    // 각 행렬에 대한 동적 할당 및 초기값 설정
    int **array_a = new int *[input];
    int **array_b = new int *[input];
    int **array_c = new int *[input];
    int **array_d = new int *[input]; // 행렬-a x 행렬-b 곱셈 결과 저장 행렬
    int **array_e = new int *[input]; // 행렬-d x 행렬-c 곱셈 결과 저장 행렬

    for (j = 0; j < input; j++)
    {
        array_a[j] = new int[input];
        array_b[j] = new int[input];
        array_c[j] = new int[input];
        array_d[j] = new int[input];
        array_e[j] = new int[input];
    }

    // 초기값 설정
    for (i = 0; i < input; i++)
    {
        for (j = 0; j < input; j++)
        {
            array_a[i][j] = j;
            array_b[i][j] = j + 1;
            array_c[i][j] = j + 2;

            // 결과를 저장할 행렬이기 때문에 초기값은 모두 0
            array_d[i][j] = 0;
            array_e[i][j] = 0;
        }
    }

    start_cb = clock();
    
    // 행렬 곱 시작
    for (i = 0; i < input; i++)
    {
        for (j = 0; j < input; j++)
        {
            for (k = 0; k < input; k++)
            {
                array_d[i][j] += array_a[i][k] * array_b[k][j];
            }
            for (k = 0; k < input; k++)
            {
                array_e[i][j] += array_d[i][k] * array_c[k][j];
            }
        }
    }
    end_cb = clock();
    res_cb = (float)(end_cb - start_cb);

    cout << "n^3(Cubic complexity) time cost: " << res_cb << "ms" << endl;

    // 메모리 해제
    for (j = 0; j < input; j++)
    {
        delete[] array_a[j];
        delete[] array_b[j];
        delete[] array_c[j];
        delete[] array_d[j];
        delete[] array_e[j];
    }
    delete[] array_a;
    delete[] array_b;
    delete[] array_c;
    delete[] array_d;
    delete[] array_e;


    // 피보나치 수열

    start_exp = clock();
    for (int i = 1; i <= input; i++)
    {
        fib(i);
    }
    end_exp = clock();
    res_exp = (float)(end_exp - start_exp);
    cout << "2^n(Exponential complexity) time cost: " << res_exp << "ms" << endl;

    return 0;
}
