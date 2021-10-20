# 00. C++ Tutorial
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
