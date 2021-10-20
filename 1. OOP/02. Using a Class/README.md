# 02. Using a Class
- Contents
  - Preprocessor Wrappers 
  - Member 함수의 scope
  - Class Scope and Accessing Class Members
  - Constructors with Default Arguments
  - Destructors
  - 생성자와 소멸자의 호출시기
  - Default Memberwise Assignment
  - Copy Constructor

## Preprocessor Wrappers 
- 코드가 두번 이상 포함(include)되는 것을 방지
  - `#ifndef` XXX – “if XXX is not defined yet”
    - : 만약 XXX가 이미 포함되어 있다면 이 코드를 건너 뛴다,
  - `#define` XXX
    - : 이 코드가 나중에 다시 포함되지 않도록 라벨(label) XXX을 정의 (define)
  - `#endif` : #ifndef 와 pair로 구성됨
- 만약 헤더가 이전에 포함되었다면
  - 라벨 XXX은 이미 정의 되었고, 따라서 헤더파일은 더 이상 포함되지 않는다.
- 다중 정의 (multiple definition) 에러를 방지

```cpp
// prevent multiple inclusions of header file
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time
{
public:
Time(); // constructor
void setTime(int, int, int); // set hour, minute and second
void printuniversal(); // print time in universal-time format
void printStandard(); // print time in standard-time format
private:
int hour; // 0-23 (24-hour clock format)
int minute; // 0 - 59 
int second; // 0 - 59
};

#endif // !TIME_H
```

## Member 함수의 scope
- 클래스 정의 내에서 선언된(declared) 멤버 함수를 클래스 외부에서 정의(define)했다고 하더라도 멤버 함수는 여전히 class scope에 존재한다.
- 다음의 연산자들을 통해서 접근하지 않는 이상 클래스의 멤버는 클래스 내부에서만 알려지게 된다.
  - 클래스 객체
  - 클래스 객체의 참조 또는 클래스 객체의 포인터
  - 이항 스코프 식별 연산자 (binary scope resolution operator)
    - 이것을 이용하여 클래스 외부에서 다음과 같이 멤버 함수를 정의함
    - ```void Time::setTime(...)```

## Class Scope and Accessing Class Members
### 클래스 스코프 (class scope)와 클래스 멤버로의 접근
- 클래스 스코프
  - 데이터 멤버
    - 클래스 정의 내에 선언된 변수 (member variables)
  - 멤버 함수
    - 클래스 정의 내에 선언된 함수 (member functions)
- 클래스 멤버가 아닌 함수들은 파일 스코프 (file scope)에 정의 되어야 한다.

### 클래스 스코프 (class scope)와 클래스 멤버로의 접근
- 클래스 스코프 내부에서
  - 클래스 멤버는 모든 멤버 함수에 의해 접근 가능하다.
- 클래스 스코프 외부에서
  - public 클래스 멤버는 다음 핸들(handle)을 이용하여 접근 가능하다
    - 객체 이름 (object name)
    - 객체 참조 (reference to an object)
    - 객체 포인터 (pointer to an object)

- 멤버 함수 내부에서 정의된 변수
  - Block scope를 가짐 -> 함수 내부에서만 살아있는 지역 변수 (local variable)
- 멤버 변수와 같은 이름의 지역 변수가 멤버 함수에 정의된다면?
  - 클래스의 멤버 변수는 `::` 접근자를 통해서 접근해야 함
    - 예) `Time::hour`
    - 그렇지 않으면, 그 변수는 지역 변수를 의미함

- 점 (dot) 멤버 선택 연산자 (`.`)
  - 객체의 멤버에 접근 가능하다.
  - 객체의 이름(name) 이나 객체의 참조(reference)에 사용
    - 예) `sunset.printUniversal( );`

- 화살 (arrow) 멤버 선택 연산자 (`->`)
  - 객체의 멤버에 접근 가능하다.
  - 객체의 포인터에 사용한다.
    - 예) `timePtr->printUniversal( )`

## Constructors with Default Arguments
### 생성자의 디폴트 인자 (default arguments)
- 데이터 멤버를 일관성 있게 초기화 한다.
  - 심지어 생성자의 인자가 주어지지 않은 경우 포함
  - `Time(int=0, int=0, int=0); // default constructor`
- 모든 인자에 디폴트 인자가 지정된 생성자는 역시 디폴트 생성자(default constructor)이다.
  - 어떠한 인자도 없이 호출 할 수 있다.
  - 클래스당 최대 한 개의 디폴트 생성자를 가진다.

```cpp
#pragma once
class Time {
public:
    Time();

    void setTime(int, int, int);
    void printUniversal();
    void printStandard();
private:
    int hour;
    int minute;
    int second;
};
```

## Destructors
### 클래스 소멸자 (class destructors)
- 특별한 용도의 멤버 함수
- 소멸자의 이름: `~`에 클래스의 이름을 붙임
  - 예) `~Time` 
- 객체가 소멸 될 때 무조건 호출된다.
  - 예) 자동변수로 선언된 객체가 소멸될 때
  - 종료 정리 작업 (termination housekeeping)을 수행
  - 소멸자 실행 후, 시스템이 객체의 메모리를 회수
    - 따라서 메모리는 재사용 될 수 있게 된다.

### 소멸자 (destructors)
- 매개변수를 받지도 않고 값을 반환하지도 않는다.
  - 생성자는 매개변수를 받았고, 오버로딩도 가능함.
  - 반환형이 없다. 
    — void 형도 아님
- 클래스는 단 한 개의 소멸자를 가질 수 있다.
  - 소멸자 오버로딩(overloading)은 허락되지 않는다.
    - 애초에 오버로딩 할 일이 없다.
- 만약 프로그래머가 명시적으로 소멸자를 지정하지 않았다면, 컴파일러는 “빈(empty)” 소멸자를 만든다.
  - 아무 일도 하지 않음

## 생성자와 소멸자의 호출시기
### 생성자와 소멸자의 호출 메커니즘
- 객체 생성과 소멸시 내부적으로 (implicitly) 자동 호출됨
- 생성자와 소멸자의 호출 시기와 순서는 어느 scope에서 객체가 생성되느냐에 따라 다름
  - 예제 참조
- 일반적으로 생성자의 호출 순서의 역순으로 소멸자가 호출됨

### 생성자와 소멸자의 호출 시기
#### 객체가 global scope에서 정의될 때 (즉, 전역 변수일 때)
- 전역 변수는 프로그램 수행 내내 살아있음
- main 함수가 시작되기 전에 객체가 생성되어 생성자 호출
- main 함수가 종료되면 객체가 소멸되어 소멸자 호출

#### 객체가 자동 지역 변수 (local automatic variable) 일 때 (: 보통 main 함수 안에 있는 것)
- 객체가 정의될 때 객체가 생성되어 생성자 호출
- 객체가 포함된 scope를 벗어날 때 소멸되어 소멸자 호출

#### 객체가 정적 지역 변수 (static local variable) 일 때
- Static 변수는 단 한번 생성되어 프로그램 수행 내내 살아있는 변수이다
- 따라서 생성자는 객체가 처음 생성될 때 단 한번 호출
- main 함수가 종료되면 객체가 소멸되어 소멸자 호출

<img width="389" alt="스크린샷 2021-10-21 오전 2 29 22" src="https://user-images.githubusercontent.com/73745836/138142187-2adfb943-04f3-45a2-9674-138ab3ff327d.png">
> global과 static은 위치가 같아 특성이 "비슷"

#### 생성자와 소멸자의 호출 시기 예제 
##### CreatAndDestroy.h
```cpp
#pragma once
#include <string>
using std::string;

class CreateAndDestory {
public:
    CreateAndDestory(int, string);
    ~CreateAndDestory();

private:
    int objectID;
    string message;
};
```
##### CreatAndDestroy.cpp
```cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Create.h"

void create(void); // prototype

CreateAndDestory Temp(2, "Temp");
CreateAndDestory first(1, "(global before main)"); // global object
int main()
{
    cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestory second(2, "(local automatic in main)");
    static CreateAndDestory third(3, "(local static in main)");

    create(); // call function to create objects
    cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
    CreateAndDestory fourth(4, "(local automatic in main)");
    cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
    return 0;
}

void create(void)
{
    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestory fifth(5, "(local automatic in create)");
    static CreateAndDestory sixth(6, "(local static in create)");
    CreateAndDestory seventh(7, "(local automatic in create)");
    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}
```
##### driver
```cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Create.h"

CreateAndDestory::CreateAndDestory(int ID, string msg)
{
    objectID = ID;
    message = msg;

    cout << "Object " << objectID << "    constructor runs    " << message << endl;
}
CreateAndDestory::~CreateAndDestory()
{
    // output newline for certain objects; helps readability
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");

    cout << "Object " << objectID << "    destructor runs    "
         << message << endl;
}
```

##### OUTPUT
```
1   constructor runs    (global before main)

MAIN FUNCTION: EXECUTION BEGINS
2   constructor runs    (local automatic in main)
3   constructor runs    (local static in main)

CREATE FUNCTION: EXECUTION BEGINS
5   constructor runs    (local automatic in create)
6   constructor runs    (local static in create)
7   constructor runs    (local automatic in create)

CREATE FUNCTION: EXECUTION ENDS
7   destructor runs    (local automatic in create)
5   destructor runs    (local automatic in create)

MAIN FUNCTION: EXECUTION BEGINS
4   constructor runs    (local automatic in main)

MAIN FUNCTION: EXECUTION ENDS
4   destructor runs    (local automatic in create)
2   destructor runs    (local automatic in create)
6   destructor runs    (local static in create)
3   destructor runs    (local static in main)
1   destructor runs    (global before main)
```

## Default Memberwise Assignment
### 디폴트 멤버별 (memberwise) 대입
- 대입 연산자 (=)
  - 해당 객체를 동일한 다른 객체에 대입할 때 사용
    - 대입 연산자의 오른편에 있는 각 데이터 멤버는 개별적으로 대입 연산자 왼편에 있는 데이터 멤버에 1:1 대입 된다.
  - 멤버별 대입은 동적으로 할당된 포인터를 포함하는 데이터 멤버에 대해서는 심각한 문제를 유발 할 수 있으므로 주의
    - 같은 메모리를 나중에 두 번 해제할 수 있음

## Copy Constructor
### 복사 생성자 (copy constructor)
- 객체 생성시 기존 객체의 값에 의한 전달
  - 이미 존재하는 객체의 값을 그대로 이용하여 새로운 객체를 생성한다.
- 컴파일러는 디폴트 복사 생성자를 제공한다.
  - 원래 객체의 각 데이터 멤버를 새로운 객체의 대응되는 데이터 멤버로 복사한다. (즉, 멤버별 대입을 수행)
- 동적 할당된 포인터를 포함한 데이터 멤버에 대해서는 역시 심각한 문제를 유발 할 수 있다.
