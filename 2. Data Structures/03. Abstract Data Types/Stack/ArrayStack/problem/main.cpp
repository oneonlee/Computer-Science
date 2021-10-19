#include <iostream>
#include "array_stack.h"

int main() {
    // Case 1: when stack is full
    try {
        std::cout << "Case 1" << std::endl;

        int capacity = 5;
        ArrayStack<int> stack(capacity); // 저장공간이 5인 스택을 선언

        std::cout << "capacity=" << capacity << std::endl; // 스택의 저장공간을 출력

        // 스택에 6개의 값을 넣으면서 스택의 크기와 맨 위 값이 어떻게 변하는지 관찰
        stack.push(1);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.push(2);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.push(3);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.push(4);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.push(5);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        // 저장공간의 크기가 5이므로 6번째 `push`에서 예외를 발생시키고 `catch`문으로 넘어감
        stack.push(6); // throw exception
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;
    } catch (const StackEmptyException& e) {
        std::cout << "StackEmptyException is occurred: " << e << std::endl;
    } catch (const StackFullException& e) {
        std::cout << "StackFullException is occurred: " << e << std::endl; // 오류 메세지 출력
    }
    std::cout << std::endl;

    // Case 2: when stack is empty
    try {
        std::cout << "Case 2" << std::endl;

        int capacity = 5;
        ArrayStack<int> stack(capacity); // 저장공간이 5인 스택을 선언

        std::cout << "capacity=" << capacity << std::endl; // 스택의 저장공간을 출력

        // 스택에 2개의 값을 넣으면서 스택의 크기와 맨 위 값이 어떻게 변하는지 관찰
        stack.push(1);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.push(2);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        // 스택에 3개의 값을 제거하면서 스택의 크기가 어떻게 변하는지 관찰
        stack.pop();
        std::cout << "size=" << stack.size() << std::endl;

        stack.pop();
        std::cout << "size=" << stack.size() << std::endl;

        // 스택에서 더 이상 제거할 값이 없기 때문에 예외을 발생시키고 `catch`문으로 넘어감
        stack.pop(); // throw exception
        std::cout << "size=" << stack.size() << std::endl;
    } catch (const StackEmptyException& e) {
        std::cout << "StackEmptyException is occurred: " << e << std::endl; // 오류 메세지 출력
    } catch (const StackFullException& e) {
        std::cout << "StackFullException is occurred: " << e << std::endl;
    }
    std::cout << std::endl;

    // Case 3: no exception
    try {
        std::cout << "Case 3" << std::endl;

        int capacity = 5;
        ArrayStack<int> stack(capacity); // 저장공간이 5인 스택을 선언

        std::cout << "capacity=" << capacity << std::endl; // 스택의 저장공간을 출력

        // 스택에 3개의 값을 넣으면서 스택의 크기와 맨 위 값이 어떻게 변하는지 관찰
        stack.push(1);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.push(2);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.push(3);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        // 스택에 2개의 값을 제거하면서 스택의 크기가 어떻게 변하는지 관찰
        stack.pop();
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        stack.pop();
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        // 스택에 1개의 값을 넣으면서 스택의 크기와 맨 위 값이 어떻게 변하는지 관찰
        stack.push(4);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        // 스택에 1개의 값을 제거하면서 스택의 크기가 어떻게 변하는지 관찰
        stack.pop();
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        // 스택에 1개의 값을 넣으면서 스택의 크기와 맨 위 값이 어떻게 변하는지 관찰
        stack.push(5);
        std::cout << "size=" << stack.size() << std::endl
                  << "top=" << stack.top() << std::endl;

        // 예외가 발생하지 않았기 때문에 `catch`문은 실행되지 않음
    } catch (const StackEmptyException& e) {
        std::cout << "StackEmptyException is occurred: " << e << std::endl;
    } catch (const StackFullException& e) {
        std::cout << "StackFullException is occurred: " << e << std::endl;
    }
    return 0;
}
