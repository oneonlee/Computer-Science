# Analysis of Algorithms

- [1. Recursion](#1-recursion)
- [2. Analysis of Algorithms](#2-analysis-of-algorithms)
- [3. Big-Oh Notation](#3-big-oh-notation)
- [4. Exception Handling](#4-exception-handling)

## 1. Recursion

우리는 for 반복문이나 while 반복문과 같은 반복문을 작성해서 반복을 구현할 수 있음을 보았다. 반복을 얻는 또 다른 방법은 함수가 자신의 정의 내에서 자신을 호출할 때 발생하는 재귀(recursion)를 통해서이다.

### General Procedure

1. Initialize the algorithm with a value to start with (e.g.,viaparameters).
2. If the current value(s) being processed matches the base case, solve it and return the value.
3. If not,redefine the answer in terms of a smaller or simpler sub-problem(s).
4. Run the algorithm on the sub-problem.
5. Combine the results in the formulation of th eanswer.
6. Return the results.

### Characteristic of Recursion

All recursive methods have the following characteristics:

- One or more base cases (the simplest case) are used to stop recursion.
- Every recursive call reduces the original problem, bringing it increasingly closer to a base case until it becomes that case.

### Designing Recursive Functions

- Step 1. Identify the base case
  - The base case is the part of the recursion not defined in terms of itself,
    - e.g., 𝑓0 = 0, 𝑓1 = 1
  - This is when the recursion stops!
    - Really an infinite series of function calls until your computer crashes
- Step 2. Identify the recursive process
  - This is the algorithmic processor algorithmic formula
- Step 3. Write the code

### ex1> Counting

```cpp
#include <iostream>
using namespace std;

int counting(int n, int val);

int main()
{
    int n, val = 0, res;
    cout << "Enter a positive integer : ";
    cin >> n;

    res = counting(n, val);
    cout << "The " << n << "th integer is " << res << endl;
}

int counting(int n, int val)
{
    if (n == 0)
    {
        cout << "Base case" << endl;
        return 0;
    }
    else
    {
        cout << n << endl;
        val = val + 1;
    }
    return counting(n - 1, val) + 1;
}
```

### ex2> Factorial

#### Iterative

```cpp
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
```

#### Recursive

![IMG_243E92A1E3AD-1](https://user-images.githubusercontent.com/73745836/137916691-9ecde91c-8912-4b51-a6f5-2be660c6ab1b.jpeg)

```cpp
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
```

### ex3> Fibonacci

- Begins with 0 and 1 (Base Case)
- The Fibonacci series can be defined recursively as follows:
  - fibonacci(0) = 0
  - fibonacci(1) = 1
  - fibonacci(n) = fibonacci(n – 1) + fibonacci(n – 2)

#### Recursive

```cpp
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
```

#### Iterative

```cpp
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
```

### Downside of Recursion

- Recursion is not always efficient!
- Take for instance, the Fibonacci sequence

![IMG_734251D8B1E4-1](https://user-images.githubusercontent.com/73745836/137921793-d185c3e8-8d2d-4759-b76e-89c4161f045b.jpeg)

## 2. Analysis of Algorithms

Seven functions that often appear in algorithm analysis:

- Constant ≈ 1
- Logarithmic ≈ logn
- Linear ≈ n
- N-Log-N ≈ nlogn
- Quadratic ≈ n^2
- Cubic ≈ n^3
- Exponential ≈ 2^n

![IMG_DDB67E86BA1E-1](https://user-images.githubusercontent.com/73745836/137924442-49402e29-2ba2-44b3-9ef9-621a92c58215.jpeg)

### Functions Graphed Using “Normal” Scale

![IMG_7BC97DC6891E-1](https://user-images.githubusercontent.com/73745836/137924546-559af989-785f-49bd-aaf6-f70b3d0fbecd.jpeg)

### Why Growth Rate Matters

![IMG_F8748871339F-1](https://user-images.githubusercontent.com/73745836/137928953-f577266f-efce-4f72-9775-8de4bdc4f7ff.jpeg)

## 3. Big-Oh Notation

- Given functions f(n) and g(n), we say that f(n) is O(g(n)) if there are positive constants c and n_0 such that
  - f(n) <= cg(n) for n >= n_0

## 4. Exception Handling

```cpp
#include <iostream>
using namespace std;

int main()
{
    try
    {
        int age;
        cout << "Enter your age: ";
        cin >> age;
        if (age >= 18)
        {
            cout << "Access granted - you are old enough.";
        }
        else
        {
            throw(age);
        }
    }
    catch (int myNum)
    {
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Age is: " << myNum << endl;
    }
}
```
