## Deque
- The double-Ended Queue, or Deque, ADT stores arbitrary objects
- Main deque operations
  - `insertFront(object)`: Insert a new element at the beginning of the deque
  - `insertBack(object)`: Insert a new element at the end of the deque
  - `eraseFront()`: Remove the first element of the deque; an error occurs if the deque is empty
  - `eraseBack()`: Remove the last element of the deque; an error occurs if the deque is empty

- Auxiliary queue operations:
  - object `front()`: Return the first element of the deque; an error occurs if the deque is empty
  - object `back()`: Return the last element of the deque; an error occurs if the deque is empty
  - integer `size()`: Return the number of elements of the deque.
  - boolean `empty()`: Return true if the deque is empty and false otherwise
- Exceptions
  - Attempting the execution of erase, front, or back on an empty queue throws a `DequeEmpty`

### Deque with a Doubly Linked List
- DLinkedList.h
```cpp
#include <string>
using std::string;

// Code Fragment 3.22: C++ implementation of a doubly linked list node.
typedef string Elem; // list element type
class DNode
{ // doubly linked list node
private:
    Elem elem;                // node element value
    DNode *prev;              // previous node in list
    DNode *next;              // next node in list
    friend class DLinkedList; // allow DLinkedList access
};

// Code Fragment 3.23: Implementation of a doubly linked list class.
class DLinkedList
{ // doubly linked list
public:
    DLinkedList();                // constructor
    ~DLinkedList();               // destructor
    bool empty() const;           // is list empty?
    const Elem &front() const;    // get front element
    const Elem &back() const;     // get back element
    void addFront(const Elem &e); // add to front of list
    void addBack(const Elem &e);  // add to back of list
    void removeFront();           // remove from front
    void removeBack();            // remove from back
private:                          // local type definitions
    DNode *header;                // list sentinels
    DNode *trailer;

protected:                             // local utilities
    void add(DNode *v, const Elem &e); // insert new node before v
    void remove(DNode *v);             // remove node v
};

// Code Fragment 3.24: Class constructor and destructor
DLinkedList::DLinkedList()
{                       // constructor
    header = new DNode; // create sentinels
    trailer = new DNode;
    header->next = trailer; // have them point to each other
    trailer->prev = header;
}
DLinkedList::~DLinkedList()
{ // destructor
    while (!empty())
        removeFront(); // remove all but sentinels
    delete header;     // remove the sentinels
    delete trailer;
}

// Code Fragment 3.25: Accessor functions for the doubly linked list class.
bool DLinkedList::empty() const // is list empty?
{
    return (header->next == trailer);
}
const Elem &DLinkedList::front() const // get front element
{
    return header->next->elem;
}
const Elem &DLinkedList::back() const // get back element
{
    return trailer->prev->elem;
}

// Code Fragment 3.26: Inserting a new node into a doubly linked list.
// The protected utility function add inserts a node z before an arbitrary node v.
// The public member functions addFront and addBack both invoke this utility function.
void DLinkedList::add(DNode *v, const Elem &e) // insert new node before v
{
    DNode *u = new DNode;
    u->elem = e;       // create a new node for e
    u->next = v;       // link u in between v
    u->prev = v->prev; // . . .and v->prev
    v->prev->next = v->prev = u;
}
void DLinkedList::addFront(const Elem &e) // add to front of list
{
    add(header->next, e);
}
void DLinkedList::addBack(const Elem &e) // add to back of list
{
    add(trailer, e);
}

// Code Fragment 3.27: Removing a node from a doubly linked list.
// The local utility function remove removes the node v.
// The public member functions removeFront and removeBack invoke this utility function.
void DLinkedList::remove(DNode *v)
{                       // remove node v
    DNode *u = v->prev; // predecessor
    DNode *w = v->next; // successor
    u->next = w;        // unlink v from list
    w->prev = u;
    delete v;
}
void DLinkedList::removeFront() // remove from font
{
    remove(header->next);
}
void DLinkedList::removeBack() // remove from back
{
    remove(trailer->prev);
}
```

- Deque_exception.h
```cpp
#include <string>
using std::string;

// Code Fragment 2.4: RuntimeException
class RuntimeException
{ // generic run-time exception
private:
    string errorMsg;

public:
    RuntimeException(const string &err) { errorMsg = err; }
    string getMessage() const { return errorMsg; }
};

// Code Fragment 5.2: Exception thrown by functions pop and top when called on an empty Deque.
// Exception thrown on performing top or pop of an empty Deque.
class DequeEmpty : public RuntimeException
{
public:
    DequeEmpty(const string &err) : RuntimeException(err) {}
};
```

- Deque_with_a_Doubly_Linked_List.cpp
```cpp
#include <string>
#include "DLinkedList.h"
#include "Deque_exception.h"
using std::string;

// Code Fragment 5.21: The class structure for class LinkedDeque.
typedef string Elem; // deque element type
class LinkedDeque
{ // deque as doubly linked list
public:
    LinkedDeque();                               // constructor
    int size() const;                            // number of items in the deque
    bool empty() const;                          // is the deque empty?
    const Elem &front() const throw(DequeEmpty); // the first element
    const Elem &back() const throw(DequeEmpty);  // the last element
    void insertFront(const Elem &e);             // insert new first element
    void insertBack(const Elem &e);              // insert new last element
    void removeFront() throw(DequeEmpty);        // remove first element
    void removeBack() throw(DequeEmpty);         // remove last element
private:                                         // member data
    DLinkedList D;                               // linked list of elements
    int n;                                       // number of elements
};
```
