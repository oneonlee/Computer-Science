# List and Iterator ADTs

- [1. Vectors (Array Lists)](#1-vectors-array-lists)
- [2. List](#2-list)
- [3. Sequences](#3-sequences)

## 1. Vectors (Array Lists)

- The Vector or Array List ADT extends the notion of array by storing a sequence of objects
- An element can be accessed, inserted or removed by specifying its index (numberof elements preceding it)
- An exception is thrown if an incorrect index is given (e.g.,a negative index)

- Main methods:
  - `at(integer i)`: returns the element at index i without removing it
  - `set(integer i, object o)`: replace the element at index i with o
  - `insert(integer i, object o)`: insert a new element o to have index i
  - `erase(integer i)`: removes element at index i
- Additional methods:
  - `size()`
  - `empty()`

### Array-based Implementation

index : `(f-1+N)%N`

- Performance
  <img width="30%" src="https://user-images.githubusercontent.com/73745836/137971802-f178bccc-3c60-4456-b6fd-ec14977b26bd.jpeg">

### Growable Array-based Vector

How large should the new array be?

- Incremental strategy: increase the size by a constant c
- Doubling strategy: double the size

#### Comaparison of the Strategies

Amortized time

- Incremental Strategy Analysis
  - k=n/c
  - T(n) is O(n+k^2)=O(n^2)
  - The Amortized time is O(n^2)/n=O(n)
- Doubly Strategy Analysis
  - k=log_2 n
  - T(n) is O(n)
  - The Amortized time is O(n)/n=O(1)

### Doubling Strategy Analysis

```cpp
#include <iostream>
#include <algorithm>
using std::max;

// Code Fragment 6.2: A vector implementation using an extendable array.
typedef int Elem; // base element type
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
    if (i < 0 | | i >= n)
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

// Code Fragment 6.5: The member functions reserve and insert for class ArrayVector.
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
```

## 2. List

### Position ADT

The Position ADT models the notion of place within a data structure where a single object is stored

### Containers and Iterators

- An iterator abstracts the process of scanning through a collection of elements
- A container is an abstract data structure that supports element access through iterators
- `begin()`: returns an iterator to the first element
- `end()`: return an iterator to an imaginary position just after the last element
- An iterator behaves like a pointer to a nelement
- `*p`: returns the element referenced by this iterator
- `++p`: advances to the next element

### Containers

- Data structures that support iterators are called containers
- Examples include Stack, Queue, Vector, List
- Various notions of iterator:
  - (standard) iterator: allows read-write access to elements
  - constiterator: provides read-only access to elements
  - bidirectional iterator: supports both ++p and --p
  - random-access iterator: supports both p+i and p-i

### Iterating through a Container

- Let C be a container and p be an iterator for C

```cpp
for (p = C.begin(); p != C.end(); ++p)
  loop_body
```

- Example: (with an STL vector)

```cpp
typedef vector<int>::iterator Iterator;
int sum = 0;
for (Iterator p = V.begin(); p != V.end(); ++p)
  sum += *p;
return sum;
```

### List ADT

- The Node List ADT models a sequence of positions storing arbitrary objects
- Genericmethods:
  - `size()`, `empty()`
- Iterators:
  - `begin()`: returns an iterator referring to the first element of the list; same as `end()` if the list is empty
  - `end()`: returns an iterator referring to an imaginary element just after the last element of the list
- Update functions
  - `insertFront(e)`: inserts a new element e into the list as the first element
  - `insertBack(e)`: insert a new element e into the list as the last element
  - `eraseFront()`: removes the first element of the list
  - `eraseBack()`: removes the last element of the list
- Iterator-based update:
  - `insert(p,e)`: inserts a new element e into the list before position p in the list
  - `erase(p)`: removes from the list the element at position p; invalidates p as a position
- An error condition occurs if an invalid position is passed as an argument to one of the list operations

## 3. Sequences

벡터와 리스트는 Sequences ADT의 일종이다. (더 General 하다.)

- Generic functions:
  - `size()`, `empty()`
- Vector-based functions:
  - `at(i)`, `set(i,o)`, `insert(i,o)`, `erase(i)`
- List-based functions:
  - `begin()`, `end()`
  - `insertFront(o)`, `insertBack(o)`
  - `eraseFront()`, `eraseBack()`
  - `insert(p,o)`, `erase(p)`
- Bridge functions:
  - `atIndex(i)`: returns the position of the element at index i
  - `indexOf(p)`: returns the index of the element at position p

### Comparing Sequence Implementations

![](https://user-images.githubusercontent.com/73745836/137982254-d82fe765-1c19-4aed-bee0-4de074c382d1.jpeg)
