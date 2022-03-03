#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex num1(1, 7); // Set Complex number as 1+7i
    Complex num2(9, 2); // Set Complex number as 9+2i

    num1.printStandard();
    cout << " + ";
    num2.printStandard();
    cout << " = ";
    num1.add(num2); // Add num1 and num2
    num1.printResultStandard();

    Complex num3(10);    // Set Complex number as 10+1i
    Complex num4(11, 5); // Set Complex number as 11+5i

    num3.printSimple();
    cout << " - ";
    num4.printSimple();
    cout << " = ";
    num3.sub(num4); // Subtract num3 and num4
    num3.printResultSimple();

    return 0;
}