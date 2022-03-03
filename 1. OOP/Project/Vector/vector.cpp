#include <iostream>
#include <iomanip>
#include "vector.h"

using namespace std;

Vector::Vector(int vecSize) // Initiallizer
{
    size = vecSize > 0 ? vecSize : 3; // exception handling
    ptr = new int[size];
    for (int i = 0; i < size; i += 1)
    {
        ptr[i] = 0;
    }
}

Vector::~Vector() // Destructor
{
    delete[] ptr;
}

Vector Vector::operator+(Vector &v) // + Operator Overloading
{
    Vector tmp(size); // made temporaily Vector named 'tmp'

    for (int i = 0; i < size; i++)
    {
        tmp.ptr[i] = ptr[i];
        tmp.ptr[i] = tmp.ptr[i] + v.ptr[i];
    }
    return tmp;
}

Vector Vector::operator-(Vector &v) // - Operator Overloading
{
    Vector tmp(size); // made temporaily Vector named 'tmp'
    for (int i = 0; i < size; i++)
    {
        tmp.ptr[i] = ptr[i];
        tmp.ptr[i] = tmp.ptr[i] - v.ptr[i];
    }
    return tmp;
}

Vector Vector::operator*(Vector &v) // * Operator Overloading
{
    Vector tmp(size); // made temporaily Vector named 'tmp'
    for (int i = 0; i < size; i++)
    {
        tmp.ptr[i] = ptr[i];
        tmp.ptr[i] = tmp.ptr[i] * v.ptr[i];
    }
    return tmp;
}

bool Vector::operator==(const Vector &right) const // == Operator Overloading
{
    if (size != right.size)
    {
        // cout << "different size!";
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] != right.ptr[i])
        {
            return false;
        }
    }
    return true;
}

bool Vector::operator!=(const Vector &right) const // \!= Operator Overloading
{
    if (size != right.size)
    {
        // cout << "different size!";
        return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] != right.ptr[i])
        {
            return true;
        }
    }
    return false;
}

istream &operator>>(istream &input, Vector &a) // >> Operator Overloading
{
    for (int i = 0; i < a.size; i++)
    {
        input >> a.ptr[i];
    }
    return input;
}

ostream &operator<<(ostream &output, const Vector &a) // << Operator Overloading
{
    // Seperate the output by step
    output << setw(3) << "⎡" << setw(5) << a.ptr[0] << setw(3) << "⎤" << endl;
    if (a.size > 2)
    {
        for (int i = 1; i < (a.size - 1); i++)
        {
            output << setw(3) << "⎟" << setw(5) << a.ptr[i] << setw(3) << "⎟" << endl;
        }
    }
    output << setw(3) << "⎣" << setw(5) << a.ptr[a.size - 1] << setw(3) << "⎦" << endl;
    return output;
}