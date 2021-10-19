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