# 01. Defining a Class

## Object-Oriented Programming

### 객체지향 설계 (object-oriented design)

#### 클래스-객체-인스턴스의 차이

1. **Class란?**

- 개념
  - **Object를 만들어 내기 위한 설계도 혹은 틀**
  - 연관되어 있는 Variable과 Method의 집합

2. **Object란?**

- 개념
  - 소프트웨어 세계에 구현할 대상
  - **Class에 선언 된 모양 그대로 생성된 실체**
- 특징
  - 'Class의 Instance'라고도 부른다.
  - Object는 모든 Instance를 대표하는 포괄적인 의미를 갖는다.
  - OOP의 관점에서 **Class의 타입으로 선언되었을 때 'Object'**라고 부른다.

3. **Instance란?**

- 개념
  - 설계도를 바탕으로 **소프트웨어 세계에 구현된 구체적인 실체**
  - 즉, 객체를 소프트웨어에 실체화 하면 그것을 'Instance'라고 부른다.
  - 실체화된 Instance는 메모리에 할당된다.
- 특징
  - Instance는 Object에 포함된다고 볼 수 있다.
  - OOP의 관점에서 **Object가 메모리에 할당되어 실제 사용될 때 'instance'**라고 부른다.
  - 추상적인 개념(또는 명세)과 구체적인 Object 사이의 관계에 초점을 맞출 경우에 사용한다.
  - '~의 instance'의 형태로 사용된다.
  - Object는 Class의 Instance이다.
  - Object 간의 링크는 Class 간의 연관 관계의 Instance이다.
  - 실행 프로세스는 프로그램의 Instance이다.
  - 즉, Instance라는 용어는 반드시 Class와 Object 사이의 관계로 한정지어 사용할 필요는 없다.
  - 인스턴스는 어떤 원본(추상적인 개념)으로부터 '생성된 복제본'을 의미한다.

## Reusability in OOP

- 새로운 클래스 작성 또는 프로그램 작성시 기존 클래스의 재사용은 시간과 노력을 줄여준다.
- 재사용은 또한 프로그래머가 더 신뢰성 있고 효율적인 시스템을 구축할 수 있도록 돕는다.

## Defining a Class

### 클래스 정의 (class definition)

- 컴파일러에게 클래스에 속한 멤버함수와 데이터 멤버를 알려준다.
- 클래스의 이름은 class 키워드와 함께 사용하여 시작한다.
- 클래스의 본문(body)은 대괄호 안에 작성되어야 한다. `{ }`
  - 데이터 멤버(멤버 변수)와 멤버 함수의 명기
  - 접근 지정자 (access-specifier). `public :`

```cpp
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class GradeBook {
public:
    //function overloading
    void displayMessage() {
        cout << "Welcome to the GradeBook" << endl;
    }
    void displayMessage(string str) {
        cout << str<< endl;
    }
};


int main() {
    GradeBook myGradeBook;
    myGradeBook.displayMessage();
    myGradeBook.displayMessage("Welcome");
    myGradeBook.displayMessage("to");
    myGradeBook.displayMessage("the");
    myGradeBook.displayMessage("GradeBook");
    return 0;
}
```

### 멤버 함수 (member function) 정의

- 함수의 반환형 (return type)
  - 함수가 종료되었을 때 반환할 값의 자료형 (일반적인 함수와 같은 의미)
  - `void`는 함수가 아무런 값도 반환하지 않는다는 것을 의미
- 함수 본문은 함수가 어떤 일을 수행하는지 기술함
  - 중괄호 `{}`에 의해 제한된다.

### 클래스 사용

- 클래스는 사용자 정의 자료형 (user-defined type)
  - C++ 객체생성시 사용
    - 클래스 형의 변수
- dot operator ( . )
  - 객체의 멤버 함수 및 데이터 멤버의 접근에 사용된다.

## Defining a Member Function with a Parameter

### 매개변수와 인수

#### 함수 매개변수 (parameter)

: 함수가 업무를 실행하는데 필요한 정보

#### 함수 인수 (argument)

: 함수의 매개 변수를 위해 함수 호출시 공급된 값

- 인수 값은 함수 매개변수로 복사된다.

### 매개변수 리스트 (parameter lists)

- 함수 이름 뒤의 ()안에 위치하여 함수가 실행되는데 필요한 정보를 넘겨받음
- 여러개의 매개변수는 `,`으로 구분되며 임의의 개수가 가능
- 함수 인자의 개수와 순서, 자료형은 함수 매개변수의 개수, 순서, 자료형과 일치해야 함

<br>

> Defining a function parameter again as a local variable in the function is a compilation error.

## Data Members

### 지역변수와 멤버변수

#### 지역 변수 (local variables)

- 함수 안에서 선언된 변수
  - 함수 밖에서 사용할 수 없다.
- 함수가 소멸될 때 같이 소멸된다.

#### 멤버 변수 (member variables)

- 객체가 살아있는 동안만 존재
- 데이터 멤버로 표현
  - 클래스 정의에 선언된 변수

### 접근 지정자

#### 접근 지정자 private

- 데이터 멤버나 멤버 함수에 오직 같은 클래스의 멤버 함수로만 접근이 가능하게 한다.
- `private`은 클래스 멤버의 기본 (default) 접근 지정자
- 자료 은닉 (자료의 캡슐화)
- default 속성은 private이다.

#### 기타 접근 지정자

- `public`, `protected`

## set Functions and get Functions

### 소프트웨어공학과 set, get 함수

- public 멤버함수로 선언
- private 데이터 멤버의 값을 설정(set) 또는 읽을(get) 수 있도록 정의된 인터페이스 역할
  - 클래스의 설계자는 `private` 데이터에 접근할 수 있는 방법을 제시해야 함
- 클래스의 모든 private 멤버는 set, get 함수를 통해 접근해야 함

## Initializing Objects with Constructors

### 클래스 생성자 (constructor)

- 객체가 만들어질 때 객체의 데이터를 초기화 하기 위해 사용되는 함수

  - 객체가 생성될 때 암묵적으로 (implicitly) 호출
  - 반드시 클래스와 같은 이름으로 정의 되어야 한다.
  - 값을 반환하지 않음
    - 반환형 없음 (void 형도 아님)

- 기본 생성자 (default constructor)는 매개변수를 가지지 않는다.
  - 클래스가 생성자를 프로그래머가 선언하지 않았다면, 컴파일러가 자동으로 기본 생성자를 제공
    - 오직 객체 클래스의 데이터 멤버의 생성자만 호출하는 역할

## UML diagram

### 작성방법

- 함수의 반환형은 함수 이름과 `()` 뒤에 `:`을 붙이고 반환형을 명시
- `-` 기호는 `private` 멤버를, `+` 기호는 `public` 멤버를 의미
  <img width="400" alt="스크린샷 2021-10-20 오후 11 15 42" src="https://user-images.githubusercontent.com/73745836/138110511-71a69bc8-0bc2-4a77-9739-adecc28fd500.png">

### UML에서 클래스 생성자 표기

- 세번째 섹션에 등장하며 `<<constructor>>` 라고 명기하여 일반 멤버함수와 구분
- 일반적으로 멤버함수보다 앞에 위치함
  <img width="400" alt="스크린샷 2021-10-20 오후 11 27 31" src="https://user-images.githubusercontent.com/73745836/138112696-cc58daed-2ecb-4f5c-bf87-5857e22fd01a.png">

## Separating `.h` and `.cpp` Files

### 용도에 따른 파일의 분리

#### `.cpp`는 소스코드 파일로 알려져 있다.

#### 헤더 파일 (header files)

- 클래스 선언부가 위치하며, 소스 파일과 보통 분리됨
  - 클래스가 어디에서 사용되더라도 컴파일러가 클래스를 인식할 수 있도록 해준다.
- 일반적으로 `.h` 확장자를 가진다.

#### 드라이버 파일 (driver files)

- 작성한 클래스나 함수를 운용하기 위해 사용되는 프로그램
- 실행 될 수 있게 하기 위해 하나의 `main` 함수를 포함

##### 드라이버 cpp 파일 예제

```cpp
#include <iostream>
using std::cout;
using std::endl;

#include "GradeBook.h"

int main()
{
    GradeBook gradeBook1("CS101 introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structures in C++");

    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << endl;
    return 0;
}
```

### `#include` 전처리기 지시자

- 헤더 파일을 포함(include)하기 위해 사용됨
  - C++ 전처리기는 이 지시자를 헤더파일로 바꿔치기 함
- 사용자가 생성한 헤더파일을 포함할 때는 `“ “`를 이용
  - 예: `#include“myclass.h”`
- C++ 표준 라이브러리를 포함할 때는 `<>`를 이용
  - 예: `#include <iostream>`

### 컴파일 과정에서 헤더 파일의 역할

- 컴파일러는 객체의 크기를 알아야 한다.
- C++ 객체는 일반적으로 데이터 멤버만 포함한다.
- 컴파일러는 오직 하나의 클래스 멤버 함수의 복사본을 생성 (공유)
  - 이 복사본은 모든 클래스 객체에서 공유
- 예) 4개의 정수형 데이터 멤버와 2개의 멤버 함수를 가진 클래스 객체
  - 16바이트 (데이터 멤버)의 크기를 가짐
- 컴파일러는 헤더 파일을 통해 객체의 크기를 알아내고 메모리를 할당함.

## Separating Interface from Implementation

### 인터페이스 (interface)

- 사용자가 어떤 (which) 서비스를 사용할 수 있으며, 어떻게 (how) 그 서비스를 요청하는지 정의된 약속
  - 그러나 클래스가 어떻게 (how) 서비스를 수행하는지에 관한 구체적인 정보는 없음
  - 멤버 함수 이름, 반환형과 매개변수형만으로 정의됨
    - 함수 원형 (function prototype)
- 클래스의 인터페이스는 클래스의 `public` 멤버 함수로 정의된다.

### 구현(implementation)과 인터페이스의 분리

- 클래스의 헤더 파일 (`.h`)
  - 멤버 함수의 원형은 클래스의 public 인터페이스를 기술함
  - 구체적인 구현 내용은 숨겨진다.
    - 클라이언트 코드는 구현 정보를 필요로 하지않고, 입출력만 필요로함.
- 클래스의 소스코드 파일 (`.cpp`)
  - 별도의 소스코드 파일에서 클래스 멤버함수를 구현한다.
    - Binary scope resolution operator (`::`)를 이용하여 클래스 이름과 멤버 함수의 정의를 연결
    - 예: `voidGradeBook::displayMessage()`

### 컴파일

- 소스코드 파일은 컴파일 되어 클래스 목적 코드(object code, `*.obj`)를 생성한다.
  - 클래스를 구현하는 프로그래머는 헤더파일(`*.h`)과 목적 코드 (`*.obj`)를 클라이언트에 제공해 주면 됨 (목적코드는 기계어)
- 클라이언트는 자신의 코드에 반드시 `#include` “헤더파일” 을 선언했어야 한다.
  - 그렇지 않으면 컴파일러는 클래스의 존재를 모름
  - 함수의 원형이 선언된 헤더 파일을 include하는 원리와 같음

## Validating Data with set Functions

### private 멤버에 대한 set 함수의 용도

- set 함수는 데이터를 검증(validation) 할 수 있다.
  - 유효성 검사(validity checking)로 알려져 있다.
  - 객체를 안정적인 상태로 유지
    - 데이터 멤버는 유효한 값만을 가짐
  - 유효하지 않은 값으로 설정할 경우,오류에 해당되는 코드를 리턴할 수 있음
