#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    int n = 5, res;
    res = factorial(n);
    cout << "Factorial of " << n << " is " << res << endl;

    return 0;
}

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}