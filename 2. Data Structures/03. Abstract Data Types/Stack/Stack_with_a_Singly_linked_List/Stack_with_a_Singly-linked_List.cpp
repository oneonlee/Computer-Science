#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
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
