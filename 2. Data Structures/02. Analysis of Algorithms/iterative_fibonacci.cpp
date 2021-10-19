#include <iostream>
using namespace std;

int fibonacci(int n); // iterative fibonacci implementation

int main()
{
    int n;
    cout << "Enter an integer n for fibonacci(n): ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int fib0 = 0;
    int fib1 = 1;

    for (int i = 2; i <= n; ++i)
    {
        int temp = fib1;
        fib1 = fib0 + fib1;
        fib0 = temp;
    }

    return fib1;
}