#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Array.h"

int main()
{
    Array integers1(7);
    Array integers2;

    cout << "Size of Array integers1 is "
         << integers1.getSize()
         << "\nArray after initialization:\n"
         << integers1;

    cout << "Size of Array integers2 is "
         << integers2.getSize()
         << "\nArray after initialization:\n"
         << integers2;

    cout << "\nEnter 17 integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contatin:\n"
         << "integers1:\n"
         << integers1
         << "integers2:\n"
         << integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
    {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    Array integers3(integers1);

    cout << "\nSize of Array integers3 is "
         << integers3.getSize()
         << "\nArray after initialization:\n"
         << integers3;

    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2;

    cout << "integers1:\n"
         << integers1
         << "integers2:\n"
         << integers2;

    cout << "\nEvaluating: integers1 == integers2" << endl;

    return 0;
}
