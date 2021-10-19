# Array Stack

### 1. 강의자료의 `ArrayStack`을 아래와 같은 예외클래스를 갖도록 수정하고 동작함을 보여라.

```cpp
class RuntimeException {
private:
    std::string message;

public:
    explicit RuntimeException(const std::string& message)
    : message(message) {}

    std::string get_message() const {
        return this->message;
    }
};
```

```cpp
// `ArrayStack`를 수정하여 `RuntimeException`을 추가하고 이를 상속받는 `StackFullException`과 `StackEmptyExcpetion`을 구현하라

int main() {
    // 스택이 full인 상태에서 push를 하면 `StackFullException`이 발생함을 보일 것
    // 스택이 empty인 상태에서 pop을 하면 `StackEmptyException`이 발생함을 보일 것
    return 0;
}
```

See [Sol](./ArrayStack/problem/)
