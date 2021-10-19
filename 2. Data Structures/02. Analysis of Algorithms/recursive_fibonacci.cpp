#include <iostream>
using namespace std;

int fibonacci(int n); // recursive fibonacci implementation

int main()
{
    int n;
    cout << "Enter an integer n for fibonacci(n): ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
}

int fibonacci(int n)
{
    if ((n == 0) || (n == 1))
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}