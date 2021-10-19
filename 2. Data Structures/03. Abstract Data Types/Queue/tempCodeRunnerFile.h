#include <string>
#include "queue.h"
#include "CircularlyLinkedList.h"
using std::string;

// Code Fragment 5.18: The class LinkedQueue, an implementation of a queue based on a circularly linked list.
typedef string Elem; // queue element type
class LinkedQueue
{ // queue as doubly linked list
public:
    LinkedQueue();                               // constructor
    int size() const;                            // number of items in the queue
    bool empty() const;                          // is the queue empty?
    const Elem &front() const throw(QueueEmpty); // the front element
    void enqueue(const Elem &e);                 // enqueue element at rear
    void dequeue() throw(QueueEmpty);            // dequeue element at front
private:                                         // member data
    CircleList C;                                // circular list of elements
    int n;                                       // number of elements
};

// Code Fragment 5.19: Constructor and accessor functions for the LinkedQueue class
LinkedQueue::LinkedQueue() // constructor
    : C(), n(0)
{
}
int LinkedQueue::size() const // number of items in the queue
{
    return n;
}
bool LinkedQueue::empty() const // is the queue empty?
{
    return n == 0;
}
// get the front element
const Elem &LinkedQueue::front() const throw(QueueEmpty)
{
    if (empty())
        throw QueueEmpty("front of empty queue");
    return C.front(); // list front is queue front
}

// Code Fragment 5.20: The enqueue and dequeue functions for LinkedQueue.
// enqueue element at rear
void LinkedQueue::enqueue(const Elem &e)
{
    C.add(e);    // insert after cursor
    C.advance(); // . . .and advance
    n++;
}
// dequeue element at front
void LinkedQueue::dequeue() throw(QueueEmpty)
{
    if (empty())
        throw QueueEmpty("dequeue of empty queue");
    C.remove(); // remove from list front
    n--;
}
