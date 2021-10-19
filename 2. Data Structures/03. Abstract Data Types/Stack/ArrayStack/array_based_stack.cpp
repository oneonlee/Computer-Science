#include <iostream>
#include <string>
using namespace std;

// Code Fragment 2.4: RuntimeException
class RuntimeException
{ // generic run-time exception
private:
    string errorMsg;

public:
    RuntimeException(const string &err) { errorMsg = err; }
    string getMessage() const { return errorMsg; }
};

// Code Fragment 5.2: Exception thrown by functions pop and top when called on an empty stack.
// Exception thrown on performing top or pop of an empty stack.
class StackEmpty : public RuntimeException
{
public:
    StackEmpty(const string &err) : RuntimeException(err) {}
};

class StackFull : public RuntimeException
{
public:
    StackFull(const string &err) : RuntimeException(err) {}
};

// Code Fragment 5.1: An informal Stack interface (not a complete C++ class).
template <typename E>
class Stack
{ // an interface for a stack
public:
    int size() const;                       // number of items in stack
    bool empty() const;                     // is the stack empty?
    const E &top() const throw(StackEmpty); // the top element
    void push(const E &e);                  // push x onto the stack
    void pop() throw(StackEmpty);           // remove the top element
};

// Code Fragment 5.4 : The class ArrayStack, which implements the Stack interface.
template <typename E>
class ArrayStack
{
    enum
    {
        DEF_CAPACITY = 100
    }; // default stack capacity
public:
    ArrayStack(int cap = DEF_CAPACITY);     // constructor from capacity
    int size() const;                       // number of items in the stack
    bool empty() const;                     // is the stack empty?
    const E &top() const throw(StackEmpty); // get the top element
    void push(const E &e) throw(StackFull); // push element onto stack
    void pop() throw(StackEmpty);           // pop the stack
    // . . .housekeeping functions omitted
private:          // member data
    E *S;         // array of stack elements
    int capacity; // stack capacity
    int t;        // index of the top of the stack
};

// Code Fragment 5.5: Implementations of the member functions of class ArrayStack (excluding housekeeping functions).
template <typename E>
ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1) {} // constructor from capacity
template <typename E>
int ArrayStack<E>::size() const
{
    return (t + 1);
} // number of items in the stack
template <typename E>
bool ArrayStack<E>::empty() const
{
    return (t < 0);
} // is the stack empty?
template <typename E> // return top of stack
const E &ArrayStack<E>::top() const throw(StackEmpty)
{
    if (empty())
        throw StackEmpty("Top of empty stack");
    return S[t];
}
template <typename E> // push element onto the stack
void ArrayStack<E>::push(const E &e) throw(StackFull)
{
    if (size() == capacity)
        throw StackFull("Push to full stack");
    S[++t] = e;
}
template <typename E> // pop the stack
void ArrayStack<E>::pop() throw(StackEmpty)
{
    if (empty())
        throw StackEmpty("Pop from empty stack");
    --t;
}

int main()
{
    // Code Fragment 5.6 : An example of the use of the ArrayStack class.
    // The contents of the stack are shown in the comment following the operation.
    // The top of the stack is indicated by an asterisk (“*”).
    ArrayStack<int> A; // A = [ ], size = 0
    A.push(7);         // A = [7*], size = 1
    A.push(13);        // A = [7, 13*], size = 2
    cout << A.top() << endl;
    A.pop();                 // A = [7*], outputs: 13
    A.push(9);               // A = [7, 9*], size = 2
    cout << A.top() << endl; // A = [7, 9*], outputs: 9
    cout << A.top() << endl;
    A.pop();                  // A = [7*], outputs: 9
    ArrayStack<string> B(10); // B = [ ], size = 0
    B.push("Bob");            // B = [Bob*], size = 1
    B.push("Alice");          // B = [Bob, Alice*], size = 2
    cout << B.top() << endl;
    B.pop();       // B = [Bob*], outputs: Alice
    B.push("Eve"); // B = [Bob, Eve*], size = 2
}