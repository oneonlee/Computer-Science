#include <string>
using std::string;

// Code Fragment 5.16: Exception thrown by functions front or dequeue when called on an empty queue. This class is derived from RuntimeException from Section 2.4
class QueueEmpty : public RuntimeException
{
public:
    QueueEmpty(const string &err) : RuntimeException(err) {}
};

// Code Fragment 5.15: An informal Queue interface (not a complete C++ class).
template <typename E>
class Queue
{ // an interface for a queue
public:
    int size() const;                         // number of items in queue
    bool empty() const;                       // is the queue empty?
    const E &front() const throw(QueueEmpty); // the front element
    void enqueue(const E &e);                 // enqueue element at rear
    void dequeue() throw(QueueEmpty);         // dequeue element at front
};