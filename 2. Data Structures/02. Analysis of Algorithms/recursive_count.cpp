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