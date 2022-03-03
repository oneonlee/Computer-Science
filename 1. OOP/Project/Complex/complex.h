// #pragma once;

class Complex
{
private:
    double realPart;   // The real part of the number.
    double imagPart;   // The imaginary part of the number.
    double resultReal; // The real part of the result after operation.
    double resultImag; // The imaginary part of the result after operation.

public:
    Complex(double realPart = 1, double imagPart = 1) // Member initializer
        : realPart(realPart), imagPart(imagPart)      // Set default value as 1+1i.
    {
    }

    void add(Complex anotherNum); // Add two numbers
    void sub(Complex anotherNum); // Subtract two numbers
    void printSimple();           // Print the complex number as Simple. ex> (3,5)
    void printStandard();         // Print the complex number as Standard. ex> 3+5i
    void printResultSimple();     // Print the result of operations between two complex numbers as Simple. ex> (3,5)
    void printResultStandard();   // Print the result of operations between two complex numbers as Standard. ex> 3+5i
};