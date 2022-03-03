#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

class Vector
{
    friend ostream &operator<<(ostream &, const Vector &);
    friend istream &operator>>(istream &, Vector &);

private:
    int size;
    int *ptr;

public:
    Vector(int = 10);
    ~Vector();

    Vector operator+(Vector &);
    Vector operator-(Vector &);
    Vector operator*(Vector &);
    bool operator==(const Vector &) const;
    bool operator!=(const Vector &right) const;
};

#endif