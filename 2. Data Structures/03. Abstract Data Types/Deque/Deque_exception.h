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