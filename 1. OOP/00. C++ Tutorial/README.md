# 00. C++ Tutorial

- 참고하면 좋은 자료
  - [Google의 C++ 변수 이름 짓기 가이드](https://google.github.io/styleguide/cppguide.html#Variable_Names)

## Hello World

예제를 통해서 확인할 사실 몇 가지

1. 헤더파일의 선언 - `#include <iostream>`
2. 출력의 기본구성 - `std::cout<<"출력대상1"<<"출력대상2";`
3. 개행의 진행 - `std::endl`

```cpp
#include <iostream>

int main(void)
{
  int num=20;
  std::cout<<"Hello World!"<<std::endl;
  return 0;
}
```

## scanf를 대신하는 데이터의 입력

1. 입력의 기본구성 - `std::cin>>변수`
2. 변수의 선언위치 - 함수의 중간 부분에서도 변수의 선언이 가능하다.

```cpp
std::cin>>val1>>val2;
```

이렇듯 연이은 데이터의 입력을 명령할 수 있다. `std::cin`을 통해서 입력되는 데이터의 구분은 스페이스 바, 엔터, 탭과 같은 공백을 통해서 이뤄진다.

## 배열 기반의 문자열 입출력

```cpp
#include <iostream>

int main(void)
{
  char name[100];

  std::cout<<"What's your name?";
  std::cin>>name;

  std::cout<<"Your name is "<<name<<".\n";

  return 0;
}
```

문자열의 입력방식도 다른 데이터의 입력방식과 큰 차이가 나지 않는다.

## 함수 오버로딩

```cpp
int MyFunc(int num)
{
    num++;
    return num;
}

int MyFunc(int a, int b)
{
    return a + b;
}

int main(void)
{
    MyFunc(20);     // MyFunc(int num) 함수의 호출
    MyFunc(30, 40); // MyFunc(int a, int b) 함수의 호출
    return 0;
}
```

C++은 함수호출 시 ‘함수의 이름’과 ‘전달되는 인자의 정보’를 동시에 참조하여 호출할 함수를 결정한다. 따라서 이렇듯 매개변수의 선언이 다르다면 동일한 이름의 함수도 정의 가능하다. 그리고 이러한 형태의 함수 정의를 가리켜 ‘함수 오버로딩(Function Overloading)’이라 한다.

### 함수 오버로딩의 예

```cpp
int MyFunc(char c) {...}
int MyFunc(int n) {...}
```

-> 매개변수의 자료형이 다르므로 함수 오버로딩 성립<br>
<br>

```cpp
int MyFunc(int n) {...}
int MyFunc(int n1, int n2) {...}
```

-> 매개변수의 수가 다르므로 함수 오버로딩 성립<br>
<br>

```cpp
void MyFunc(int n) {...}
int MyFunc(int n) {...}
```

-> 반환형의 차이는 함수 오버로딩의 조건을 만족시키지 않는다.<br>

## 배개변수에 설정하는 '디폴트 값'의 의미

```cpp
int MyFuncOne(int num=7) { return num+1; }
```

-> 인자를 전달하지 않으면 7이 전달된 것으로 간주한다. 여기서의 디폴트 값은 `7` 따라서 이 함수를 대상으로 하는 다음 두 함 수의 호출은 그 결과가 같다.<br>
`MyFuncOne( ); MyFuncOne(7);`
<br>
<br>

```cpp
int MyFuncTwo(int num1=5; int num2=7) { return num1+num2; }
```

-> 인자를 전달하지 않으면 각각 5와 7이 전달된 것으로 간주한다. 따라서 이 함수를 대상으로 하는 다음 두 함수의 호출은 그 결과가 같다.<br>
`MyFuncTwo( ); MyFuncTwo(5, 7);`
<br>

## 부분적 디폴트 값 설정

```cpp
int YourFunc(int num1, int num2=5, int num3=7) { ... }

YourFunc(10);     // YourFunc(10,5,7)
YourFunc(10, 20); // YourFunc(10,20,7)
```

-> 매개변수의 일부에만 디폴트 값을 지정 하고, 채워지지 않은 매개변수에만 인자를 전달하는 것이 가능하다.<br><br>

```cpp
int YourFunc(int num1, int num2, int num3=30) {...}       // (O)
int YourFunc(int num1, int num2=20, int num3=30) {...}    // (O)
int YourFunc(int num1=10, int num2=20, int num3=30) {...} // (O)
```

-> 전달되는 인자가 왼쪽에서부터 채워지므로, 디폴트 값은 오른쪽에서부터 채워져야 한다.<br><br>

```cpp
int WrongFunc(int num1=10, int num2, int num3) { ... }    // (X)
int WrongFunc(int num1=10, int num2=20, int num3) { ... } // (X)
```

-> 전달되는 인자가 왼쪽에서부터 채워지므로, 오른쪽이 빈 상태로 왼쪽의 매개변수에만 일부 채워진 디폴트 값은 의미를 갖지 못한다. **따라서 컴파일 에러를 일으킨다.** <br>

## 이름공간의 기본원리

## 동일한 이름공간 내에서의 함수호출

## `using`을 이용한 이름공간의 명시

`using namrspace std;`
너무 빈번한 `using namrspace`의 선언은 이름의 충돌을 막기위한 이름공간의 선언을 의미 없게 만든다. 따라서 제한적으로 사용할 필요가 있다!

## 참조자(Reference)

```cpp
int num1 = 2010;  // 변수의 선언으로 인해서 num1이라는 이름으로 메모리 공간이 할당된다.
int &num2 = num1; // 참조자의 선언으로 인해서 num1의 메모리 공간에 num2라는 이름이 추가로 붙게 된다.
```

- 참조자는 기존에 선언된 변수에 붙이는 ‘별칭’이다. 그리고 이렇게 참조자가 만들어지면 이는 변수의 이름과 사실상 차이가 없다.
- 참조자의 수에는 제한이 없으며, 참조자를 대상으로 참조자를 선언하는 것도 가능하다.

### 불가능한 참조자의 선언의 예

```cpp
int &ref=20;    // (X) 상수 대상으로의 참조자 선언은 불가능하다.
int &ref;       // (X) 참조자는 생성과 동시에 누군가를 참조해야 한다.
int &ref=NULL;  // (X) 포인터처럼 NULL로 초기화하는 것도 불가능하다.
```

정리하면, 참조자는 선언과 동시에 누군가를 참조해야 하는데, 그 참조의 대상은 기본적으로 변수가 되어야 한다. 그리고 참조자는 참조의 대상을 변경할 수 없다.

```cpp
int arr[3] = {1, 3, 5};

int &ref1 = arr[0];
int &ref2 = arr[1];
int &ref3 = arr[2];

cout<<ref1<<ref2<<ref3; // 135
```

변수의 성향을 지니는 대상이라면 참조자의 선언이 가능하다. 배열의 요소 역시 변수의 성향을 지니기 때문에 참조자의 선언이 가능하다.

## Call-by-value & Call-by-reference

```cpp
void SwapByValue(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
} // Call-by-value

void SwapByPtr(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
} // Call-by-pointer

void SwapByRef(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
} // Call-by-reference
```

## C++의 표준 헤더

`c`를 더하고, `.h`를 빼라
`#include <math.h>` to `#include <cmath>`

## [이름공간(namespace)에 대한 이해](https://modoocode.com/136)

먼저 cout 앞에 붙어 있는 `std` 의 정체부터 알아보자. std 는 C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름 공간(namespace) 이다.

"표준 라이브러리" 나 "객체" 가 무엇인지 아직 몰라도 괜찮다. 그냥 쉽게 생각하자면 `stdio.h` 가 C 에서 제공하는 라이브러리듯이 `iostream` 도 C++ 에서 제공하는 출력을 위한 표준 라이브러리이다.<br>
그렇다면 이름 공간이란 것이 정확히 무엇일까? 이름 공간은 말그대로 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것과 동일하다.

코드의 크기가 늘어남에 따라, 혹은 다른 사람들이 쓴 코드를 가져다 쓰는 경우가 많아지면서 중복된 이름을 가진 함수들이 많아진다. 따라서 C++ 에서는 이를 구분하기 위해, 같은 이름이라도, 소속된 이름 공간이 다르면 다른 것으로 취급하게 되었다.

예를 들어서 같은 철수라고 해도, 서울 사는 철수와 부산 사는 철수와 다르듯이 말이다.

```C++
std::cout
```

위의 경우 `std` 라는 이름 공간에 정의되어 있는 `cout` 을 의미한다. 만약에 `std::` 없이 그냥 `cout` 이라고 한다면 컴파일러가 `cout` 을 찾지 못한다. 서울에 사는 철수인지 부산에 사는 철수 인지 알 길이 없기 때문이다.

이름 공간을 정의하는 방법은 아래와 같다. 예를 들어서 두 헤더파일 header1.h 와 header2.h 를 생각해보자.

```C++
// header1.h 의 내용
namespace header1 {
int foo();
void bar();
}
```

```C++
// header2.h 의 내용
namespace header2 {
int foo();
void bar();
}
```

위 코드에서 header1 에 있는 `foo`는 header1 라는 이름 공간에 살고 있는 `foo`가 되고, header2 에 있는 `foo` 의 경우 header2 라는 이름 공간에 살고 있는 `foo` 가 된다.

자기 자신이 포함되어 있는 이름 공간 안에서는 굳이 앞에 이름 공간을 명시하지 않고 자유롭게 부를 수 있다. 예를 들어서

```C++
#include "header1.h"

namespace header1 {
int func() {
  foo();  // 알아서 header1::foo() 가 실행된다.
}
}  // namespace header1
```

header1 이름 공간안에서 `foo` 를 부른다면 알아서 `header1::foo()` 를 호출하게 된다. 그렇다고 해서 header1 의 이름 공간 안에서 header2 의 `foo` 를 호출하지 못하는 것은 아니고, 간단하게 호출 할 수 있다.

```C++
#include "header1.h"
#include "header2.h"

namespace header1 {
int func() {
  foo();           // 알아서 header1::foo() 가 실행된다.
  header2::foo();  // header2::foo() 가 실행된다.
}
}  // namespace header1
```

반면에 어떠한 이름 공간에도 소속되지 않는 경우라면 아래와 같이 명시적으로 이름 공간을 지정해야 한다.

```C++
#include "header1.h"
#include "header2.h"

int func() {
  header1::foo();  // header1 이란 이름 공간에 있는 foo 를 호출
}
```

하지만 만일 위 같은 `foo` 을 여러번 반복적으로 호출하게 되는 경우 앞에 매번 `header1::` 을 붙이기가 상당히 귀찮을 것이다.

그래서 아래와 같이 '나는 앞으로 `header1` 이란 이름 공간에 들어있는 `foo` 만 쓸거다!' 라고 선언할 수 있다.

```C++
#include "header1.h"
#include "header2.h"

using header1::foo;
int main() {
  foo();  // header1 에 있는 함수를 호출
}
```

뿐만 아니라, 그냥 기본적으로 header1 이름 공간안에 정의된 모든 것들을 `header1::` 없이 사용하고 싶다면

```C++
#include "header1.h"
#include "header2.h"

using namespace header1;
int main() {
  foo();  // header1 에 있는 함수를 호출
  bar();  // header1 에 있는 함수를 호출
}
```

아예 위와 같이 using namespace header1 과 같이 명시하면 된다.

물론 이 경우 역시 header2 에 있는 함수를 못 사용하는 것은 아니고 다음과 같이 명시적으로 써주면 된다.

```C++
#include "header1.h"
#include "header2.h"
using namespace header1;

int main() {
  header2::foo();  // header2 에 있는 함수를 호출
  foo();           // header1 에 있는 함수를 호출
}
```

그렇다면 다시 원래 예제를 살펴보자.

```C++
int main() {
  std::cout << "Hello, World!!" << std::endl;
  return 0;
}
```

여기서 `cout` 과 `endl` 은 모두 `iostream` 헤더파일의 `std` 라는 이름 공간에 정의되어 있는 것들이다. `std`를 붙이기 귀찮은 사람의 경우에는 그냥

```C++
#include <iostream>
using namespace std;

int main() {
  cout << "Hello, World!!" << endl;
  return 0;
}
```

로 써도 된다.

### 주의 사항

참고로 `using namespace std;` 와 같이 어떠한 이름 공간을 사용하겠다라고 선언하는 것은 권장하지 않는다. 왜냐하면 `std` 에 이름이 겹치는 함수를 만들게 된다면, 오류가 발생하기 때문이다.

게다가 C++ 표준 라이브러리는 매우 매우 거대하므로, 정말 수 많은 함수들이 존재하고 있다. 자칫 잘못하다가 이름을 겹치게 사용한다면, 고치느라 시간을 많이 잡아먹을 것이다. 게다가 `std` 에는 매번 수 많은 함수들이 새롭게 추가되고 있기 때문에 C++ 버전이 바뀔 때 마다 기존에 잘 작동하던 코드가 이름 충돌로 인해 동작하지 않게되는 문제가 발생할 수 있다.

따라서 권장하는 방식은 `using namespace std;` 같은 것은 사용하지 않고, `std::` 를 직접 앞에 붙여서 "`std` 의 이름공간의 함수이다" 라고 명시해주는 것이 좋다. 또한, 본인이 작성하는 코드는 본인 만의 이름 공간에 넣어서 혹시 모를 이름 충돌로 부터 보호하는 것이 중요하다.

그렇다면 `cout` 은 무엇일까? 정확히 무엇인지 말하자면 `ostream` 클래스의 객체로 표준 출력(C 언어에서의 `stdout` 에 대응된다) 을 담당하고 있다.

정확히 무슨 의미인지는 몰라도, 그냥 다음과 같이 쓴다는 것만 알아두면 된다.

### 이름 없는 이름 공간

잠깐 짚고 넘어가자면, C++ 에서는 재미있게도 이름 공간에 굳이 이름을 설정하지 않아도 된다.

이 경우 해당 이름 공간에 정의된 것들은 해당 파일 안에서만 접근할 수 있게 된다. 이 경우 마치 static 키워드를 사용한 것과 같은 효과를 낸다.

```C++
#include <iostream>

namespace {
// 이 함수는 이 파일 안에서만 사용할 수 있다.
// 이는 마치 static int OnlyInThisFile() 과 동일하다.
int OnlyInThisFile() {}

// 이 변수 역시 static int x 와 동일하다.
int only_in_this_file = 0;
}  // namespace

int main() {
  OnlyInThisFile();
  only_in_this_file = 3;
}
```

예를 들어서 위 경우 `OnlyInThisFile` 함수나 `only_in_this_file` 변수는 해당 파일 안에서만 접근할 수 있다. 헤더파일을 통해서 위 파일을 받았다 하더라도 (물론 main 함수 부분은 무시하고), 저 익명의 namespace 안에 정의된 모든 것들은 사용할 수 없게 된다.
