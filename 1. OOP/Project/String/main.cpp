#include <iostream>
#include <iomanip>
#include "myString.h"
using namespace std;

int main()
{
    myString mystr1(50);
    myString mystr2(50);
    myString mystr3(50);

    cout << "================== >> operator overloading.... ==================" << endl;
    cin >> mystr1;
    cin >> mystr2;

    cout << "================== << operator overloading.... ==================" << endl;
    cout << mystr1;
    cout << mystr2;
    cout << endl;

    cout << "================== Check each str's informations ==================" << endl;
    mystr1.printString();
    mystr2.printString();
    cout << endl;

    cout << "================== Concatenate mystr2 to mystr1 ==================" << endl;
    myString concatenatedStr = mystr1 + mystr2;
    cout << concatenatedStr;
    cout << endl;

    cout << "================== Assign concatenatedStr to myStr3 ==================" << endl;
    mystr3 = concatenatedStr;
    mystr3.printString();
    cout << endl;

    cout << "================== Compare concatenatedStr and myStr3 ==================" << endl;
    cout << (mystr3 == concatenatedStr) << endl;
    cout << endl;

    cout << "================== Compare myStr3 and myStr1 ==================" << endl;
    cout << (mystr3 == mystr1) << endl;
    cout << endl;

    cout << "================== Use [] to get a char element (index = 5, 20) ==================" << endl;
    cout << mystr3[5] << endl;
    cout << mystr3[20] << endl;

    return 0;
}