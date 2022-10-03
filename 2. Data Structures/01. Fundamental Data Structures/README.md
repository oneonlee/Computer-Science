# 01. Fundamental Data Structures
Arrays and Linked Lists

## Arrays

배열은 확실하게 정해진 순서로 무언가를 저장할 때는 유용하고, 간단하게 적용될 수 있지만. 약간의 단점이 존재한다. 
배열은 변화에 취약하다. 예를 들어 배열은 미이 크기 n을 정해야 하며 배열의 크기를 다시 정하는 것이 어렵다(STL 벡터에서 이 단점은 해결된다).
그리고 원소 추가를 위해 추가될 공간을 만들거나, 원소 제거 후에 빈 공간을 채우는 등, 원소들의 이동이 요구되기 때문에, 배열에서의 삽입과 제거에 어려움이 있다.

## Linked List
### Singly Linked List

<img width="30%" src="https://user-images.githubusercontent.com/73745836/137891671-51b87fd4-7676-49ee-a153-afbdfa54df7c.jpeg">

링크드 리스트(linked list)의 노드 내부의 next 포인터는 다른 노드에 대란 link 또는 pointer로 볼 수 있다. next 참조를 통해 한 노드에서 다른 노드로 이동하는 것은 link hopping 또는 pointer hopping 이라고 한다.
링크드 리스트의 제일 처음과 마지막 노드를 각각 그 리스트의 head와 tail이라 각각 부른다. 그래서 리스트를 head에서 시작해서 tail까지 방문할 수 있다. null을 참조하는 next 값을 가진 node로 tail을 확인할 수 있다.
각 노드가 단일 연결을 저장하므로 이러한 구조를 Singly Linked List라고 부른다. 

배열에서와 마찬가지로 Singly Linked List도 특정 순서대로 원소들을 저장하며, 이 순서는 next 링크의 연결로써 결정된다. 다만 배열과는 다르게, Singly Linked List는 미리 선언되어 고정된 크기를 갖는다. 노드를 추가하거나 삭제함으로써 사이즈를 재조정 할 수 있다.

#### Inserting at the Head
![IMG_B9767E3CC7BB-1](https://user-images.githubusercontent.com/73745836/137899259-4d4775ed-dd96-4933-ad22-493f033e4e6a.jpeg)
1. Allocate a new node and insert new element
2. Have new node print to old head
3. Update head to point to new node

Time Complexity : O(1)

#### Inserting at the tail
![IMG_2D2B47330F77-1](https://user-images.githubusercontent.com/73745836/137899352-5efe766b-9080-4a89-bf16-9896ed6c46ff.jpeg)
1. Allocate a new node and insert new element
2. Have new node point to new node
3. Have old last node point to new node
4. Update tail to point to new node

Time Complexity : O(n)

#### Removing at the Head
![IMG_7BDC1F68FD37-1](https://user-images.githubusercontent.com/73745836/137899547-edf3965d-cfad-469e-8817-1c673671cad2.jpeg)
1. Update head to point to next node in the list
2. Allow garbage collector to reclaim the former first node

Time Complexity : O(1)

#### Removing at the Tail
![IMG_7F3ADAA7E9D7-1](https://user-images.githubusercontent.com/73745836/137899671-5aa37140-0340-4eb4-8074-29ffe0eb3b99.jpeg)

- Removing at the tail of a singly linked list is not efficient!
- There is no constant-time way to update the tail to point to the previous node

Time Complexity : O(2n-1) = O(n)

```cpp
#include <string>
using std::string;

// Code Fragment 3.13: A node in a singly linked list of strings.
class StringNode
{ // a node in a list of strings
private:
    string elem;                   // element value
    StringNode *next;              // next item in the list
    friend class StringLinkedList; // provide StringLinkedList access
};

// Code Fragment 3.14: A class definition for a singly linked list of strings.
class StringLinkedList
{ // a linked list of strings
public:
    StringLinkedList();             // empty list constructor
    ~StringLinkedList();            // destructor
    bool empty() const;             // is list empty?
    const string &front() const;    // get front element
    void addFront(const string &e); // add to front of list
    void removeFront();             // remove front item list
private:
    StringNode *head; // pointer to the head of list
};

// Code Fragment 3.15: Some simple member functions of class StringLinkedList.
StringLinkedList::StringLinkedList() // constructor
    : head(NULL)
{
}
StringLinkedList::~StringLinkedList() // destructor
{
    while (!empty())
        removeFront();
}
bool StringLinkedList::empty() const // is list empty?
{
    return head == NULL;
}
const string &StringLinkedList::front() const // get front element
{
    return head->elem;
}

// Code Fragment 3.16: Insertion to the front of a singly linked list.
void StringLinkedList::addFront(const string &e)
{                                   // add to front of list
    StringNode *v = new StringNode; // create new node
    v->elem = e;                    // store data
    v->next = head;                 // head now follows v
    head = v;                       // v is now the head
}

// Code Fragment 3.17: Removal from the front of a singly linked list.
void StringLinkedList::removeFront()
{                           // remove front item
    StringNode *old = head; // save current head
    head = old->next;       // skip over old head
    delete old;             // delete the old head
}
```

### Doubly Linked List

<img width="30%" src="https://user-images.githubusercontent.com/73745836/137899953-1b5a8b1a-1a6b-454c-b57e-74868e7267a9.jpeg">

Singly Linked List의 tail에서 원소를 지우는 것은 쉽지 않다. 사실, Singly Linked List에서 지우려는 노드의 바로 이전 노드로 바로 접근하기 위한 빠른 방법이 없기 때문에 head에서 멀리 있는 노드를 지우는 것은 시간이 많이 소모된다.
Linked List에서 앞 방향과 반대 방향 등 양 방향으로 탐색을 가능케 해주는 Linked List의 종류가 있다. Doubly Linked List는 원소 멤버 이외에, 리스트의 다음 노드와 이전 노드를 각각 가리키는 next 링크와 prev 링크를 가진다. 이러한 리스트글은 어느 위치에서든 효율적인 삽입 및 제거를 포함한 다양한 빠른 업데이트 연산을 제공한다.

#### Insertion
![IMG_0AC93EA9E87B-1](https://user-images.githubusercontent.com/73745836/137902602-8d395ec4-efab-4f0d-a0f8-f18b602ce51b.jpeg)

Time Complexity : O(n+1) = O(n)

### Circularly Linked List
- Rather than having a head or tail, the nodes of a circularly linked list are linked into a cycle
- Cursor:Aplacetostartfromifweeverneedtotraverseacircularlylinkedlist
- Back: The element that is referenced by the cursor
- Front: The element immediately following this in the circular order

#### Queue with a Circularly-Linked List
- `back()`: Return the element referenced by the cursor; error if empty
- `front()`: Return the element immediately after the cursor; error if empty
- `advance()`: Advance the cursor to the next node in the list
- `add(e)`: Insert a new node with element e immediately after the cursor; if the list is empty, then this node becomes the cursor and its next pointer points to itself
- `remove()`: Remove the node immediately after the cursor (so the front); if the list has only one node, the node at cursor is removed; if the list becomes empty, the cursor is set to null

```cpp
#include <string>
using std::string;

// Code Fragment 3.28 : A node of a circularly linked list.
typedef string Elem; // element type
class CNode
{ // circularly linked list node
private:
    Elem elem;               // linked list element value
    CNode *next;             // next item in the list
    friend class CircleList; // provide CircleList access
};

// Code Fragment 3.29: Implementation of a circularly linked list class.
class CircleList
{ // a circularly linked list
public:
    CircleList();              // constructor
    ~CircleList();             // destructor
    bool empty() const;        // is list empty?
    const Elem &front() const; // element at cursor
    const Elem &back() const;  // element following cursor
    void advance();            // advance cursor
    void add(const Elem &e);   // add after cursor
    void remove();             // remove node after cursor
private:
    CNode *cursor; // the cursor
};

// Code Fragment 3.30: The constructor and destructor.
CircleList::CircleList() // constructor
    : cursor(NULL)
{
}
CircleList::~CircleList() // destructor
{
    while (!empty())
        remove();
}

// Code Fragment 3.31: Simple member functions.
bool CircleList::empty() const // is list empty?
{
    return cursor == NULL;
}
const Elem &CircleList::back() const // element at cursor
{
    return cursor->elem;
}
const Elem &CircleList::front() const // element following cursor
{
    return cursor->next->elem;
}
void CircleList::advance() // advance cursor
{
    cursor = cursor->next;
}

// Code Fragment 3.32: Inserting a node just after the cursor of a circularly linked list.
void CircleList::add(const Elem &e)
{                         // add after cursor
    CNode *v = new CNode; // create a new node
    v->elem = e;
    if (cursor == NULL)
    {                // list is empty?
        v->next = v; // v points to itself
        cursor = v;  // cursor points to v
    }
    else
    {                           // list is nonempty?
        v->next = cursor->next; // link in v after cursor
        cursor->next = v;
    }
}

// Code Fragment 3.33: Removing the node following the cursor
void CircleList::remove()
{                              // remove node after cursor
    CNode *old = cursor->next; // the node being removed
    if (old == cursor)         // removing the only node?
        cursor = NULL;         // list is now empty
    else
        cursor->next = old->next; // link out the old node
    delete old;                   // delete the old node
}
```
