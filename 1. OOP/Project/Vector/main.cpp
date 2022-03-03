// The output statement was used in English to solve the Unicode error problem.
// 12181879 Lee Dong-geon

#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    int vecSize = 3;
    cout << "Enter the size of Vector : ";
    cin >> vecSize;

    Vector vec1(vecSize);
    Vector vec2(vecSize);

    cout << "Enter the values of the two vectors in size " << vecSize << "x1 below." << endl;
    cout << "First vector : ";
    cin >> vec1;
    cout << "Second vector : ";
    cin >> vec2;

    cout << "vec1" << endl;
    cout << vec1 << endl;

    cout << "vec2" << endl;
    cout << vec2 << endl;

    cout << "\n+ Operator Overloading Result" << endl;
    cout << vec1 + vec2 << endl;

    cout << "\n- Operator Overloading Result" << endl;
    cout << vec1 - vec2 << endl;

    cout << "\n* Operator Overloading Result" << endl;
    cout << vec1 * vec2 << endl;

    cout << "\n== Operator Overloading Result" << endl;
    if (vec1 == vec2)
    {
        cout << "vec1==vec2 : True" << endl;
    }
    else
    {
        cout << "vec1==vec2 : False" << endl;
    }

    cout << "\n!= Operator Overloading Result" << endl;
    if (vec1 != vec2)
    {
        cout << "vec1!=vec2 : True" << endl;
    }
    else
    {
        cout << "vec1!=vec2 : False" << endl;
    }

    return 0;
}