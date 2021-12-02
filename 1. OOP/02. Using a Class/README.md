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
  - const Objects and const Member Functions
  - Composition: Objects as Members of Classes
  - friend Functions and friend Classes
  - Using this Pointer
  - Dynamic Memory Management with Operators new and delete
  - static Class Members 

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

### Shallow Copy vs. Deep Copy
- 얕은 복사(Shallow Copy)의 경우 객체를 복사했을 때 변수가 따로 메모리에 잡히는 것이 아니라 복사한 객체의 변수 주소를 가리키게 된다.
- 만일 동적할당으로 선언된 변수가 있을 때 얕은 복사를 한다면 에러가 발생하게 된다.

## const Objects and const Member Functions
### 상수 (const)
- 최소 특권 원리 (Principle of least privilege)
  - 각 소프트웨어 모듈(객체, 함수, …)에는 그들에게 필요한 최소한의 권한만을 부여한다.
  - 소프트웨어 설계의 기본적인 원칙 중 하나
  - 객체지향 설계에도 적용됨
- const 키워드를 이용
  - 수정을 시도하면 컴파일 오류 발생
```cpp
const a=10;
a=20;         // error!
```

### 상수 객체 (constant objects)
- 최소 특권 원리 (Principle of least privilege)
 - 각 소프트웨어 모듈(객체, 함수, …)에는 그들에게 필요한 최소한의 권한만을 부여한다.
 - 소프트웨어 설계의 기본적인 원칙 중 하나
 - 객체지향 설계에도 적용됨
- 상수 객체 (constant objects)
  - `const` 키워드를 이용
  - 객체를 수정 (즉 데이터 멤버를 수정) 할 수 없음을 의미
    - 수정을 시도하면 컴파일 오류 발생

### const 멤버 함수
- 상수 객체는 const 멤버 함수만을 호출할 수 있음
- `const`로 선언된 멤버 함수는 데이터 멤버를 수정할 수 없음
- 멤버 함수 선언과 정의에 모두 `const` 형으로 지정해야 함
- 생성자와 소멸자는 `const` 형으로 지정할 수 없음

#### **Const 위치에 따른 멤버 함수의 의미**
1. 함수명 뒤의 'const'가 가지는 의미
해당 함수에서 멤버변수를 읽기전용(RDONLY)으로 사용하겠다는 표시입니다.<br>
즉, '읽기'만 할뿐 '쓰기'는 하지않겠다는 의미입니다.

2. 위의 함수 매개변수에서 'const'가 가지는 의미
매개변수에서의 'const' 사용은 다들 익숙하시리라 생각됩니다. <br>
'call by reference'로 복사 오버헤드없이 참조하는 변수를 마찬가지로 읽기전용(RDONLY)으로 사용하겠다는 표시입니다.
 
3. 함수 반환타입 앞의 'const'가 가지는 의미
함수의 반환값을 읽기전용(RDONLY)으로 사용하겠다는 표시입니다.<br>
함수가 반환하는 값은 right-hand-side(이하 rhs)에 해당합니다. 여기서 이 값을 '&&'(r-value 참조)로 받아버리면 수정할 여지가 생깁니다. 이러한 가능성을 제거하고 '해당 함수가 반환하는 값은 대입연산자를 통해 복사해서 사용하라'는 의미라 생각됩니다.

#### **Const 위치에 따른 포인터 변수의 의미**
1. 포인터가 가리키는 대상의 값을 변경 못하게 하려면 다음과 같이 선언한다.

`const char* c_ptr;`

```cpp
char s1[] = "hello";
char s2[] = "bonjour";

const char* c_ptr = s1;
c_ptr = s2;       // 주소 변경 가능
c_ptr[0] = 'a';   // 값 변경 불가
```

- 포인터가 가리키는 대상의 값을 변경할 수 없다. 
- 하지만 포인터가 가리키는 대상(주소값)을 변경할 수 있다.


2. 포인터가 가리키는 대상(주소)을 변경 못하게 하려면 다음과 같이 선언한다.

`char* const ptr;`

```cpp
char s1[] = "hello";
char s2[] = "bonjour";

char* const c_ptr = s1;
c_ptr = s2;     // 주소 변경 불가
c_ptr[0] = 'a'; // 값 변경 가능
```

- 포인터가 가리키는 대상(주소)을 변경할 수 없다. 
- 하지만 포인터가 가리키는 대상의 값을 변경할 수 있다.


3. 대상과 대상의 값을 모두 변경하지 못하게 하려면 다음과 같이 선언한다.

`const char* const c_ptr;`

```cpp
char s1[] = "hello";
char s2[] = "bonjour";

const char* const c_ptr = s1;
c_ptr = s2;     // 주소 변경 불가
c_ptr[0] = 'a'; // 값 변경 불가
```

- 포인터가 가리키는 대상과 그 값을 모두 변경할 수 없다.

### Member Initializer
- 멤버 초기화기 (Member initializer)
  - 모든 데이터 멤버는 member initializer를 이용하여 초기화 가능
  - const 형 또는 참조형 데이터 멤버는 반드시 member initializer를 이용하여 초기화 해야 함
- 멤버 초기화기 목록 (Member initializer list)
  - 클래스 생성자의 인자 리스트와 함수 시작의 { 사이에 위치
  - 복수의 데이터 멤버를 초기화 할 수 있음
  - 클래스 생성자가 수행되기 직전에 수행
  - 구체적인 서식은 다음 예제 참조

- 이니셜라이저의 실행을 포함한 객체 생성의 과정
  - 1단계 : 메모리 공간의 할당
  - 2단계 : 이니셜라이저를 이용한 멤버변수(객체)의 초기화
  - 3단계 : 생성자의 몸체부분 실행

- 이니셜라이저를 사용하면 멤버변수가 **선언과 동시에 초기화**.
  - const로 선언된 멤버변수도 초기화가 가능.
    - 선언과 동시에 초기화 되는 형태이므로...


## Composition: Objects as Members of Classes
### 복합 (Composition)
- has-a 관계라고 표현하기도 함
- 클래스는 다른 클래스의 객체를 멤버로 가질 수 있다.
- 예시
  - AlarmClock 객체는 Time의 객체를 멤버로 가진다.

### 복합 관계에서 멤버 객체 초기화
- 멤버 초기화기(member initializers)에서 객체 생성자의 인자를 통해 멤버 객체의 생성자에게 인수를 전달
- 멤버 객체는 클래스 정의에 선언된 순서대로 생성됨
- 만약 멤버 초기화기가 제공되지 않는다면
  - 멤버 객체의 디폴트 생성자가 내부적으로 호출된다.

### Composition 예제
#### Date.h
```cpp
#pragma once

class Date {
public:
    Date(int = 1, int = 1, int = 1900);
    Date(int, int);
    void print()const;
    ~Date();

private:
    int month;
    int day;
    int year;

    int checkDay(int)const;
};
```

#### Date.cpp
```cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

Date::Date(int mn, int dy, int yr) {
    if (mn > 0 && mn <= 12) {
        month = mn;
    }
    else {
        month=1;
        cout << "Invalid month (" << mn << ") set to 1.\n";
    }

    year = yr;
    day = checkDay(dy);

    cout << "Date object constructor fordate ";
    print();
    cout << endl;
}
void Date::print() const {
    cout << month << '/' << day << '/' << year;
}

Date::~Date() {
    cout << "Date object destructor for date ";
    print();
    cout << endl;
}

int Date::checkDay(int testDay) const {
    static const int daysPerMonth[13] = {
        0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 &&
        year % 100 != 0)))
        return testDay;

    cout << "Invalid day(" << testDay << ") set to 1.\n";
    return 1;
}
```

#### Employee.h
```cpp
#pragma once
#include "Date.h"
class Employee {
public:
    Employee(const char* const, const char* const,
        const Date&, const Date&);
    void print() const;
    ~Employee();

private:
    char firstName[25];
    char lastName[25];
    const Date birthDate;
    const Date hireDate;
};
```

#### Employee.cpp
```cpp
#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strlen;
using std::strncpy;

#include "Employee.h"
#include "Date.h"

Employee::Employee(const char *const first, const char *const last,
                   const Date &dateOfBirth, const Date &dateOfHire) : birthDate(dateOfBirth),
                                                                      hireDate(dateOfHire)
{
    int length = strlen(first);
    length = (length < 25 ? length : 24);
    strncpy(firstName, first, length);
    firstName[length] = '\0';
    length = strlen(last);
    length = (length < 25 ? length : 24);
    strncpy(lastName, last, length);
    lastName[length] = '\0';

    cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}

void Employee::print() const
{
    cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();
    cout << endl;
}

Employee::~Employee()
{
    cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}
```

#### driver
```cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Employee.h"

int main() {
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Date birth2();

    Employee manager("Bob", "Blue", birth, hire);

    cout << endl;
    manager.print();

    cout << "\n Test Date constructor with invalid values:\n";
    Date lastDayoff(14, 35, 1994);
    cout << endl;
    return 0;
}
```

#### 실행 결과
![image](https://user-images.githubusercontent.com/73745836/144233936-3392fe0f-b61f-4b55-8812-c7e0cdf1e027.png)

## friend Functions and friend Classes
### 클래스의 friend function / friend class
- Class scope의 외부에 정의됨
- Class의 멤버 함수 아님
  - 그러나 클래스의 멤버에 접근할 수 있음
- public 멤버가 아닌 private 멤버에도 접근 가능
  - 독립적인 함수나 다른 클래스가 어떤 클래스의 friend로 선언될 수 있음
  - Friend 클래스 간의 직접적인 데이터 멤버 접근이 가능하므로 수행 속도 향상
  - 멤버 함수만으로는 수행하기 힘든 동작을 구현할 때 사용
- 클래스의 friend 함수 선언
  - 클래스 정의에 friend로 시작되는 함수 원형 선언
- 클래스의 friend 클래스 선언
  - ClassTwo 클래스를 ClassOne 클래스의 friend 선언
    - friend class ClassTwo; 를 ClassOne 클래스 정의에 추가
    - ClassTwo 클래스의 모든 멤버 함수는 ClassOne 클래스의 friend가 됨

### Friendship 관계의 특성
- 친구 관계 (Friendship relation) 는 허용되는 것 (취득하는 것이 아님)
  - Class B 가 Class A의 friend가 되기 위해서, class A는 class B를 friend로 명시적으로 선언해야 함 (A가 B를 허용)
- Friendship relation은 일방적이고, 또한 전이되지 않음
  - Class A가 class B의 friend여도, class B가 class A의 friend가 되지 않음
    - 즉, 짝사랑 관계
  - Class A가 class B의 friend이고, class B가 class C의 friend여, class A가 class C의 friend가 되지 않음
    - 즉, 친구의 친구는 저절로 친구가 아님
  
## Using this Pointer
### This 포인터란 무엇인가?
- This 포인터
  - 객체 내부에서 자기 자신을 가리키는 포인터 (self-reference)
- 멤버 함수는 this pointer를 통해 자신이 속한 객체를 안다.
  - 모든 객체는 C++의 키워드인 this 포인터를 통해 자신의 주소에 접근할 수 있다.
  - 객체의 this 포인터는 객체 자신의 일부는 아님


  
## Dynamic Memory Management with Operators new and delete
  
## static Class Members 
