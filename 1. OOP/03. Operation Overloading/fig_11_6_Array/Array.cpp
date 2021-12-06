#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>;
using std::exit;

#include "Array.h"

Array::Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[size];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }
}

Array::Array(const Array &arrayToCopy)
    : size(arrayToCopy.size)
{
    ptr = new int[size];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

Array::~Array()
{
    delete[] ptr;
}

int Array::getSize() const
{
    return size;
}

const Array &Array::operator=(const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            ptr[i] = right.ptr[i];
        }
    }

    return *this;
}

bool Array::operator==(const Array &right) const
{
    if (size != right.size)
    {
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

int &Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript
             << "out of range" << endl;
        exit(1);
    }

    return ptr[subscript];
}

int Array::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript
             << " out of range" << endl;
        exit(1);
    }

    return ptr[subscript];
}

istream &operator>>(istream &input, Array &a)
{
    for (int i = 0; i < a.size; i++)
    {
        input >> a.ptr[i];
    }

    return input;
}

ostream &operator<<(ostream &output, const Array &a)
{
    int i;

    for (i = 0; i < a.size; i++)
    {
        output << setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0)
        {
            output << endl;
        }
    }

    if (i % 4 != 0)
    {
        output << endl;
    }

    return output;
}