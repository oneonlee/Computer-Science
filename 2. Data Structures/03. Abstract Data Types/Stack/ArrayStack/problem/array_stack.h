// 기능 단위로 파일을 나누기 위해 스택에 관한 모든 클래스를 `array_stack.h`에 정의함
// 템플릿은 관습적으로 정의와 구현을 모두 헤더파일에서 하므로 `*.cpp` 파일은 불필요하다.

// 중복 삽입 방지를 위한 Define Guard
#ifndef ICE2004_WEEK09_HW01_ARRAY_STACK_H
#define ICE2004_WEEK09_HW01_ARRAY_STACK_H

// 사용할 헤더 정의
#include "runtime_exception.h"

/**
 * 빈 스택에서 값을 가져올 때 발생하는 예외
 * @extends RuntimeException
 */
class StackEmptyException : public RuntimeException {
public:
    /**
     * 주어진 예외 메세지로 빈 스택 예외를 생성합니다.
     * @param message 예외 메세지
     */
    explicit StackEmptyException(const std::string& message)
    : RuntimeException(message) {}
};

/**
 * 스택에 더이상 값을 담을 수 없을 때 발생하는 예외
 * @extends RuntimeException
 */
class StackFullException : public RuntimeException {
public:
    /**
     * 주어진 예외 메세지로 가득 찬 스택 예외를 생성합니다.
     * @param message 예외 메세지
     */
    explicit StackFullException(const std::string& message)
    : RuntimeException(message) {}
};

/**
 * 배열로 구현한 스택 클래스
 * @tparam T 스택 안에 들어가는 값의 타입
 */
template<typename T>
class ArrayStack {
private:
    /** 스택 안에 값을 담을 컨테이너 */
    T* container;

    /** 스택 저장공간의 크기 */
    int capacity;

    /** 현재 top 요소의 위치 */
    int idx;

public:
    /**
     * 주어진 저장공간을 가진 스택을 생성합니다.
     * 주의: 복사 생성자가 구현되어 있지 않습니다. 복사된 스택이 소멸되면 메모리 오류를 발생시킵니다.
     * @param capacity 스택 저장공간의 크기
     */
    explicit ArrayStack(int capacity = 100)
    // `container`에 배열을 동적 할당합니다.
    // 할당된 배열은 사용이 끝나면 메모리에서 해지되어야 합니다.
    : container(new T[capacity]), capacity(capacity), idx(-1) {}

    /**
     * 스택 클래스의 소멸자입니다.
     */
    ~ArrayStack() {
        // 사용이 끝난 `container`를 메모리에서 해지
        delete[] container;
    }

    /**
     * 스택이 비어있는지 확인합니다.
     * @return 비어있다면 `true`를 반환합니다.
     */
    bool empty() const {
        return idx < 0; // `idx`가 -1이하면 스택이 비어있음
    }

    /**
     * 스택의 맨 위 값을 제거합니다.
     * 스택이 비어있어 제거할 값이 없다면 `StackEmptyException`을 반환합니다.
     */
    void pop() throw(StackEmptyException) {
        if (empty()) { // 스택이 비어있는지 확인
            throw StackEmptyException("Pop from empty stack");
        }
        --idx; // `top` 요소의 위치를 한 칸 내리기
    }

    /**
     * 스택 맨 위에 값을 추가합니다.
     * 스택에 더이상 값을 추가할 수 없다면 `StackFullException`을 반환합니다.
     * @param value 스택에 추가할 값
     */
    void push(const T& value) throw(StackFullException) {
        if (size() == capacity) { // 스택의 크기와 저장공간이 같다면 더이상 값을 넣을 수 없음
            throw StackFullException("Push to full stack");
        }
        container[++idx] = value; // `top` 요소의 위치를 한 칸 올리고 배열에 값을 할당
    }

    /**
     * 현재 스택이 가지고 있는 값의 개수를 반환합니다.
     * @return 스택의 크기
     */
    int size() const {
        return idx + 1; // 위치는 0부터 시작하므로 1을 더해 반환
    }

    /**
     * 스택의 맨 위 값을 반환합니다.
     * 스택이 비어있어 반환할 값이 없다면 `StackEmptyException`을 반환합니다.
     * @return 스택의 맨 위 값
     */
    const T& top() const throw(StackEmptyException) {
        if (empty()) { // 스택이 비어있는지 확인
            throw StackEmptyException("Top of empty stack");
        }
        return container[idx];
    }
};

#endif // ICE2004_WEEK09_HW01_ARRAY_STACK_H
