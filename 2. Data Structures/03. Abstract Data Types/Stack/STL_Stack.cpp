#include <iostream>
#include <stack>
using std::cout;
using std::stack;
stack<int> myStack;

int main()
{
    // 스택 생성
    stack<int> s;

    // push
    s.push(3);
    s.push(2);
    s.push(1);

    // top
    cout << "top element: " << s.top() << '\n';

    // pop
    s.pop(); // 1이 삭제
    s.pop(); // 2가 삭제

    // size
    cout << "stack size: " << s.size() << '\n';

    // empty
    cout << "Is it empty?: " << (s.empty() ? "Yes" : "No") << '\n';

    return 0;
}