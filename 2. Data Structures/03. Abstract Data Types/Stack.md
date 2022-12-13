- [1. Stack](./Stack.md)
- [2. Queue](./Queue.md)
- [3. Deque](./Deque.md)

## 1. Stack

- The Stack ADT stores arbitrary objects.
- Insertions and deletions follow the last-in first-out(LIFO) scheme.
- Main stack operations:
  - `push(object)`: inserts an element
  - object `pop()`: removes the last inserted element
- Auxiliary stack operations:
  - object `top()`: returns the last inserted element without removing it
  - integer `size()`: returns the number of element sstored
  - boolean `empty()`: indicates whether no elements are stored

### STL Stack

스택 객체를 선언하기 위해서는 "stack"이라고 불리는 정의 파일을 먼저 포함해야 한다. STL 벡터 클래스와 마찬가지로 스택 클래스도 std 네임스페이스에 포함되기 때문에 `std::stack`으로 사용하던지 `using`문을 사용해야 한다. 예를 들어, 다음 프로그램은 정수의 스택을 선언한다.

```cpp
#include <stack>
using std::stack    // stack을 접근할 수 있게 한다.
stack<int> myStack; // 정수의 스택
```

- STL 스택 클래스의 주요 멤버 함수
  - `size()`: 스택 내의 객체의 개수를 반환한다.
  - `empty()`: 스택이 비어 있으면 참을, 그렇지 않으면 거짓을 반환한다.
  - `push(e)`: 객체 e를 스택의 최상위에 삽입한다.
  - `pop()`: 스택의 최상위에 있는 객체를 스택에서 제거한다.
  - `top()`: 스택의 최상위 원소의 레퍼런스를 반환한다.

스택 연산의 우리 정의와 STL 구현의 중요한 차이가 있다. STL 구현에는 중요한 차이가 있자. STL 구현에는 빈 스택에 대한 `top` 또는 `pop` 연산의 결과가 정의되어 있지 않다.
즉, 오류(exception)가 발생되지 않는다. 오류가 발생되지 않더라도, 당신의 프로그램이 중단될 가능성이 높다. 따라서 프로그래머가 그러한 불법적인 접근을 하지 않는 것이 필요하다.

### Stack Interface in C++

- C++ interface corresponding to our StackADT
- Uses an exception class `StackEmpty`
- Different from the built-in C++ STL class stack

```cpp
// An informal Stack interface(not a complete C++ class)

template <typename E>
class Stack
{
public:
    int size() const;
    bool empty() const;
    const E &top() const throw(StackEmpty);
    void push(const E &e);
    void pop() throw(StackEmpty);
}
```

### Array-based Stack in C++

```cpp
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
```

### Stack with a Singly-linked List

SinglyLinkedList.h

```cpp
#include <string>
using std::string;

// Code Fragment 3.18: A node in a generic singly linked list.
template <typename E>
class SNode
{ // singly linked list node
private:
    E elem;                      // linked list element value
    SNode<E> *next;              // next item in the list
    friend class SLinkedList<E>; // provide SLinkedList access
};

// Code Fragment 3.19: A class definition for a generic singly linked list.
template <typename E>
class SLinkedList
{ // a singly linked list
public:
    SLinkedList();             // empty list constructor
    ~SLinkedList();            // destructor
    bool empty() const;        // is list empty?
    const E &front() const;    // return front element
    void addFront(const E &e); // add to front of list
    void removeFront();        // remove front item list
private:
    SNode<E> *head; // head of the list
};

// Code Fragment 3.20: Other member functions for a generic singly linked list.
template <typename E>
SLinkedList<E>::SLinkedList() // constructor
    : head(NULL)
{
}
template <typename E>
bool SLinkedList<E>::empty() const // is list empty?
{
    return head == NULL;
}
template <typename E>
const E &SLinkedList<E>::front() const // return front element
{
    return head->elem;
}
template <typename E>
SLinkedList<E>::~SLinkedList() // destructor
{
    while (!empty())
        removeFront();
}
template <typename E>
void SLinkedList<E>::addFront(const E &e)
{                               // add to front of list
    SNode<E> *v = new SNode<E>; // create new node
    v->elem = e;                // store data
    v->next = head;             // head now follows v
    head = v;                   // v is now the head
}
template <typename E>
void SLinkedList<E>::removeFront()
{                         // remove front item
    SNode<E> *old = head; // save current head
    head = old->next;     // skip over old head
    delete old;           // delete the old head
}
```

Stack_with_a_Singly-linked_List.cpp

```cpp
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

```

### Applications of Stacks

#### Parentheses Matching Algorithm

괄호검사
스택을 사용하여 수식의 괄호 사용이 올바른지 확인할 수 있다. 괄호에는 세 종류가 있다 '()', '{}', '[]' 여는 괄호를 왼쪽, 닫는 괄호를 오른쪽이라 표현하겠다.

- 올바른 괄호의 사용은 다음과 같은 조건을 가진다:

  - 조건 1: 왼쪽과 오른쪽의 개수가 같아야한다
  - 조건 2: 같은 괄호일 때 왼쪽이 오른쪽보다 먼저 나와야 한다
  - 조건 3: 서로 다른 괄호쌍이 서로를 교차하면 안된다.

- 알고리즘:

  - 문자열을 차례대로 조사하다가 왼쪽 발견시 스택에 push.
  - 오른쪽 발견시 pop으로 top에 있는 괄호 제거
  - 스택 비어있을 시 false 반환 (조건 2)
  - 왼쪽과 짝이 맞지 않을 시 false 반환 (조건 3
  - 문자열 조사가 끝났음에도 스택에 괄호가 있을시 false 반환 (조건 1)

- 다음은 위 알고리즘의 구현이다:

```cpp
bool ParenMatch(char X[])
{
	int i = 0; prev;
    char ch;

    while(X[i] != '\0')
    {
    	ch = X[i++];;
        if(ch == '[' || ch =='{' || ch == '(') push(ch);
        else if (ch == ']' || ch == '}' || ch ++ ')')
        {
        	if(empty()) return false;
            prev = top();
            pop();
            if((ch == ']' && prev != '[')
            || (ch == '}' && prev != '{')
            || (ch == ')' && prev != '('))
            	return false;
        }
    }
    if (empty()) return false;

    return true;
}
```
