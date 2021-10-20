#include <iostream>
using namespace std;

void SwapByValue(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
} // Call-by-value

void SwapByPtr(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
} // Call-by-pointer

void SwapByRef(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
} // Call-by-reference

int main(void)
{
    int val1 = 10;
    int val2 = 20;
    SwapByRef(val1, val2);
    cout << "val1: " << val1 << endl;
}