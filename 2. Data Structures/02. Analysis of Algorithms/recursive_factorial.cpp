// iteration & recursive factorial

#include <iostream>
using namespace std;

long long int iteration_factorial(unsigned long long int n)
{
    unsigned long long int value = 1;
    for (unsigned long long int i = 1; i <= n; i++)
    { // n번 반복
        value = value * i;
    }
    return value;
}

unsigned long long int factorial(unsigned long long int n)
{ // recursive
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    unsigned long long int n = 5, result;
    result = iteration_factorial(n);
    // result = factorial(n);

    cout << result;
    return 0;
}
