#include <iostream>
using namespace std;

#define throw(IndexOutOfBounds)

// Code Fragment 2.4: RuntimeException
class RuntimeException
{ // generic run-time exception
private:
    string errorMsg;

public:
    RuntimeException(const string &err) { errorMsg = err; }
    string getMessage() const { return errorMsg; }
};

class IndexOutOfBounds : public RuntimeException
{
public:
    IndexOutOfBounds(const string &err) : RuntimeException(err) {}
};

// Code Fragment 6.2: A vector implementation using an extendable array.
typedef char Elem; // base element type
class ArrayVector
{
public:
    ArrayVector();                           // constructor
    int size() const;                        // number of elements
    bool empty() const;                      // is vector empty?
    Elem &operator[](int i);                 // element at index
    Elem &at(int i) throw(IndexOutOfBounds); // element at index
    void erase(int i);                       // remove element at index
    void insert(int i, const Elem &e);       // insert element at index
    void reserve(int N);                     // reserve at least N spots
    // . . . (housekeeping functions omitted)
private:
    int capacity; // current array size
    int n;        // number of elements in vector
    Elem *A;      // array storing the elements
};

// Code Fragment 6.3: The simple member functions for class ArrayVector.
ArrayVector::ArrayVector() // constructor
    : capacity(0), n(0), A(NULL)
{
}
int ArrayVector::size() const // number of elements
{
    return n;
}
bool ArrayVector::empty() const // is vector empty?
{
    return size() == 0;
}
Elem &ArrayVector::operator[](int i) // element at index
{
    return A[i];
}
// element at index (safe)
Elem &ArrayVector::at(int i) throw(IndexOutOfBounds)
{
    if (i < 0 || i >= n)
        throw IndexOutOfBounds("illegal index in function at()");
    return A[i];
}

// Code Fragment 6.4: The member function remove for class ArrayVector.
void ArrayVector::erase(int i)
{                                   // remove element at index
    for (int j = i + 1; j < n; j++) // shift elements down
        A[j - 1] = A[j];
    n--; // one fewer element
}

// Code Fragment 6.5: The member functions insertDoubling and insert for class ArrayVector.
void ArrayVector::reserve(int N)
{ // reserve at least N spots
    if (capacity >= N)
        return;                 // already big enough
    Elem *B = new Elem[N];      // allocate bigger array
    for (int j = 0; j < n; j++) // copy contents to new array
        B[j] = A[j];
    if (A != NULL)
        delete[] A; // discard old array
    A = B;          // make B the new array
    capacity = N;   // set new capacity
}

void ArrayVector::insert(int i, const Elem &e)
{
    if (n >= capacity)                 // overflow?
        reserve(max(1, 2 * capacity)); // double array size
    for (int j = n - 1; j >= i; j--)   // shift elements up
        A[j + 1] = A[j];
    A[i] = e; // put in empty slot
    n++;      // one more element
}
