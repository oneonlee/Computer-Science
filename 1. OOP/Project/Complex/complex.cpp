#include <iostream>
#include "complex.h"

using namespace std;

void Complex::add(Complex anotherNum) // Add two numbers
{
    resultReal = realPart + anotherNum.realPart;
    resultImag = imagPart + anotherNum.imagPart;
}

void Complex::sub(Complex anotherNum) // Subtract two numbers
{
    resultReal = realPart - anotherNum.realPart;
    resultImag = imagPart - anotherNum.imagPart;
}

void Complex::printSimple() // Print the complex number as Simple. ex> (3,5)
{
    cout << "(" << realPart << ", " << imagPart << ")";
}

void Complex::printStandard() // Print the complex number as Standard. ex> 3+5i
{
    cout << "(" << realPart << " + " << imagPart << "i)";
}
void Complex::printResultSimple() // Print the result of operations between two complex numbers as Simple. ex> (3,5)
{
    cout << "(" << resultReal << ", " << resultImag << ")" << endl;
}

void Complex::printResultStandard() // Print the result of operations between two complex numbers as Standard. ex> 3+5i
{
    cout << "(" << resultReal << " + " << resultImag << "i)" << endl;
}