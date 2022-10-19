# Operator Overloading

## Contents

1. Introduction
2. Operator Overloading 기본사항
3. Operator Overloading 제한조건
4. Operator Functions as Class Members vs. Global Functions
5. Overloading Stream Insertion and Stream Extraction Operators
6. Overloading Unary Operators
7. Overloading Binary Operators
8. Case Study: Array Class
9. Overloading ++ and –
10. Case Study: A Date Class

## 1. Introduction

### 연산자 오버로딩이란?

- 클래스 객체에 기본형 및 사용자 정의형 연산자를 이용
  - 예) Time 클래스 객체끼리 덧셈 연산?
  - 연산자 오버로딩 (operator overloading) 이라고도 함
  - 특정 클래스의 멤버 함수 호출보다 명확
  - 문맥(context)에 따라 적응적으로 동작
- 예시
  - <<:스트림 삽입(stream-insertion), 비트단위 왼쪽 시프트 (bitwise left-shift)
  - - : 다양한 아이템(integers, floats, etc.) 들 간의 덧셈 연산을 수행

## 2. Operator Overloading 기본사항

### 연산자 오버로딩 방법

- Operator overloading의 타입
  - 내장 (built-in) 데이터 타입 (int, char) 또는 사용자 정의 데이터 타입 (classes)
  - 기존 연산자를 사용자 정의 타입에 사용할 수 있도록 함
    - 새로운 연산자를 만들 수는 없다!
- 연산자의 오버로딩
  - 클래스의 멤버 함수 정의에 의해 생성
  - 연산자 멤버 함수의 이름
    - operator라는 키워드 뒤에 오버로드 될 연산자의 기호를 붙임
    - ex> `operator+` 는 덧셈 연산자를 +를 의미함

### Operator+ 라는 이름의 함수

```cpp
class Point
{
private:
    int x, y;

public:
    Point(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
    void print()
    {
        cout << "x : " << x << ", y : " << y << "\n";
    }
    Point operator+(Point &p)
    {
        x = x + p.x;
        y = y + p.y;
        return Point(x, y);
    }
};
int main(void)
{
    Point p1 = {1, 1};
    Point p2(2, 2);
    Point p3 = p1 + p2;
    p3.print();
    return 0;
}
```

### Good Programming Practice

> Overloaded operators should mimic the functionality of their built-in counterparts—for example, the + operator should be overloaded to perform addition, not subtraction. Avoid excessive or inconsistent use of operator overloading, as this can make a program cryptic and difficult to read.

### 연산자 오버로딩 방법

- 연산자를 클래스 객체에 적용하기 위해 연산자를 반드시 오버로딩 해야 한다.
- 예외
  - 모든 클래스에 대해 오버로딩 없이 사용할 수 있으나, 역시 프로그래머에 의해 다시 오버로딩 될 수 있는 연산자
  - 대입 연산자(`=`)
    - 클래스에 속한 데이터 멤버들을 멤버 별로 복사한다.
  - 주소 연산자(`&`)
    - 객체의 주소 값을 반환한다.

### 오버로딩은 객체간 연산의 간결한 표현을 제공

- Overloading 하지 않았을 때
  - `object2 = object2.add(object1);`
- Overloading 했을 때
  - `object2 = object2 + object1;`

### 3. Operator Overloading 제한조건

### 연산자 오버로딩으로도 변경 불가능한 것은?

- 연산자의 우선순위 (중간 계산 순서)
  - e.g., A \* B + C
  - 연산자의 순서를 바꾸기 위해서 괄호를 사용한다.
- 연산자의 결합 순서 (left-to-right 또는 right-to-left)
- 피연산자(operand)의 개수
  - e.g., &은 단항(unary) 연산자이므로, 단 하나의 피연산자만을 취함
- 내장 타입의 객체에 적용되는 연산 방법
  (i.e., 정수 덧셈에 사용되는 `+` 연산자의 의미를 바꿀 수 없다.)

- 새로운 연산자를 만드는 것은 불가능
- 연산자는 명확하게 오버로딩 되어야 한다.
  - `=` 와 `+` 연산자가 오버로딩 되었다고 해서 `+=` 연산자가 오버로딩 된 것은 아니다.
- 연산자 `?:` 는 오버로딩 될 수 없다.

### 연산자 오버로딩할 수 없는 연산자

<img width="675" alt="스크린샷 2021-12-02 오후 9 18 08" src="https://user-images.githubusercontent.com/73745836/144420521-87cdc77b-1f2c-4dac-9756-fa7e32a81fcb.png">

## 4. Operator Functions as Class Members vs. Global Functions

### 멤버 함수로서의 연산자 함수

- (피연산자1 연산자 피연산자2) 일 때, 피연산자1이 연산자가 정의된 클래스의 객체가 되어야 한다.
- 이항 연산자 (binary operator) 의 왼쪽 피연산자의 인자를 얻기 위해 암시적으로 키워드를 사용한다.
- 연산자 `()`, `[]`, `->` 또는 대입 연산자(`=`)는 클래스 멤버 함수로 오버로드 되어야 한다.
- 연산자 멤버 함수는 아래의 경우에 호출된다.
  - 이항 연산자의 왼쪽 피연산자가 그 클래스의 객체인 경우
  - 단항 연산자의 피연산자가 그 클래스의 객체인 경우

### 전역 함수로서의 연산자 함수

- 전역 함수로서의 연산자 함수
  - 함수 매개변수들(즉, 모든 피연산자)을 필요로 한다.
  - 연산자와 다른 클래스의 객체를 매개변수로 취할 수 있다.
- 오버로드 된 << 연산자
  - ostream& 형의 왼쪽 피연산자
    - 예시 – `cout<<classObject`에서의 객체 `cout`
  - 유사하게 >> 또한 istream& 형의 왼쪽 피연산자를 취한다.
  - 그러므로, << 와 >> 모두 전역 함수이다.
    - classObject 형을 인자로 취하는 연산자 오버로딩을 위해 C++ standard library를 바꿀 수 없기 때문

### 연산자 오버로딩과 연산의 교환 법칙

- 교환 법칙이 성립하는 연산자
  - 덧셈 연산자(+)는 교환 법칙이 성립하기를 원함
    - “operand1 + operand2” 와 “operand2 + operand1” 모두 가능하도록
  - 두 개의 다른 형의 객체가 피연산자일 때,
    - 클래스 객체가 왼쪽에 나타날 때 오버로드 된 연산자는 클래스의 멤버함수이어야 한다.
      - `HugeIntClass + long int`
    - 다른 경우일 때 전역 오버로딩 함수가 필요하다.
      - `long int + HugeIntClass`

## 5. Overloading Stream Insertion and Stream Extraction Operators

### 연산자 오버로딩과 stream 연산자

- << 와 >> 연산자
  - 내장 자료형을 처리하기 위해 이미 오버로드 되어 있음
  - 사용자 정의 클래스를 처리하기 위해 전역 friend 함수로서 오버로딩을 구현
- 예제 프로그램
  - `Class PhoneNumber`
  - cout에 의해 PhoneNumber객체의 내용을 알맞게 출력
    - 예) (123) 456-7890

### 연산자 오버로딩과 stream 연산자 예제

#### PhoneNumber.h

```cpp
#pragma once

#include <iostream>
using namespace std;

class PhoneNumber
{
    friend ostream &operator<<(ostream &, const PhoneNumber &);
    friend istream &operator>>(istream &, PhoneNumber &);

private:
    string areaCode;
    string exchange;
    string line;
};
```

#### PhoneNumber.cpp

```cpp
// #include <iostream>

#include <iomanip>
#include "PhoneNumber.h"

using namespace std;

ostream &operator<<(ostream &output, const PhoneNumber &number)
{
    output << "(" << number.areaCode << ") "
           << number.exchange << "-" << number.line;

    return output;
}

istream &operator>>(istream &input, PhoneNumber &number)
{
    input.ignore();
    input >> setw(3) >> number.areaCode;
    input.ignore(2);
    input >> setw(3) >> number.exchange;
    input.ignore();
    input >> setw(4) >> number.line;

    return input;
}

istream &operator>>(istream &input, PhoneNumber &number)
{
    input.ignore();
    input >> setw(3) >> number.areaCode;
    input.ignore(2);
    input >> setw(3) >> number.exchange;
    input.ignore();
    input >> setw(4) >> number.line;

    return input;
}
```

#### driver

```cpp
#include <iostream>
using namespace std;

#include "PhoneNumber.h"

int main()
{
    PhoneNumber phone;

    cout << "Enter phone number in the forms (123) 456-7890:" << endl;

    cin >> phone;

    cout << "The phone number entered was: ";

    cout << phone << endl;
    return 0;
}
```

## 6. Overloading Unary Operators

### 단항 연산자 (unary operator) 오버로딩

- static이 아닌 클래스 멤버함수로 오버로딩 가능
  - 이항 연산자 오버로딩과 달리 인수가 필요없음
- 또는 하나의 인수를 갖는 전역 함수로 오버로딩 가능
  - 인수는 클래스의 객체 또는 클래스의 객체의 참조
- static 멤버함수는 static 멤버 데이터에만 접근할 수 있음을 기억할 것

### 증가, 감소 연산자의 오버로딩

<img width="875" alt="스크린샷 2021-12-02 오후 9 31 41" src="https://user-images.githubusercontent.com/73745836/144422457-dd9f68ae-00f6-42ee-8027-96b53d50bfbb.png">

## 7. Overloading Binary Operators

### 이항 연산자 (binary operator) 오버로딩

- Non-static 멤버 함수로 구현했을 때, 하나의 인수
- 전역 함수로 구현했을 때, 두 개의 인수
  - 하나의 인수는 클래스의 객체이거나 객체의 참조여야 한다.

### 예제: += 오버로딩

#### Non-static 멤버 함수라면, 하나의 인수가 필요하다.

```cpp
class String
{
public:
  const String & operator+=( const String & );
  …
};
```

- y += z 는 y.operator+=( z )으로 작성된 것처럼 처리된다.

#### 전역 함수라면, 두 개의 인수가 필요하다.

- `const String &operator+=( String &, const String & );`
- y += 는 operator+=( y, z )으로 작성된 것처럼 처리된다.

## 8. Case Study: Array Class

### C++ 배열의 단점

- 배열의 범위를 체크하지 않는다. (no range checking)
- `==` 로 두 개의 배열을 비교할 수 없다.
- 대입 연산자로 다른 배열로 대입될 수 없다.
  - 배열의 이름은 const 포인터이므로
- 만약 배열이 함수 인자로 전달될 때는 배열의 크기도 인수로 전달되어야 한다.
  - 배열의 이름으로는 배열 크기를 알 수 없음

### C++ 배열의 개선

- 다음의 기능을 포함하는 새로운 배열을 구현하기 위한 클래스
  - 범위 체크(range checking)가 가능
  - 하나의 배열 객체를 다른 배열 객체에 대입할 수 있다.
  - 별도의 인수로 배열의 크기를 함수에 전해줄 필요가 없다.
  - 배열 전체를 << 과 >>를 통해 입출력 할 수 있다.
  - == 과 != 을 통한 배열 비교가 가능하다.
    (추가할 만한 유용한 기능이 또 무엇이 있을까?)

### Array 클래스의 복사 생성자(Copy Constructor)

- 객체의 복사가 필요할 때마다 사용:

  - 객체가 값으로 함수에 전달될 때 (함수에서 값으로 객체를 반환할 때)
  - 같은 클래스의 다른 객체를 복사하여 초기화 할 때 다음과 같이 사용
    - `Array newArray(oldArray) 또는 Array newArray = oldArray;`
      - => 수행 후 newArray는 oldArray의 복사본이 됨.

- 복사 생성자 선언
  - `Array(const Array&);`
  - 반드시 참조(&)를 가져와야 한다.
    - 그렇지 않으면, 인수는 값으로 전달되어지면서 매개변수 객체 생성
    - -> 매개변수 객체 생성을 위해 복사 생성자 다시 호출
    - -> 또 다시 매개변수 객체 생성을 위해 복사 생성자 호출
    - -> 무한 루프

### 연산자 오버로딩으로 개선된 Array 클래스 예제

#### Array.h

```cpp
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::istream;
using std::ostream;

class Array
{
    friend ostream &operator<<(ostream &, const Array &);
    friend istream &operator>>(istream &, Array &);

public:
    Array(int = 10);
    Array(const Array &);
    ~Array();
    int getSize() const;

    const Array &operator=(const Array &);
    bool operator==(const Array &) const;

    bool operator!=(const Array &right) const
    {
        return !(*this == right);
    }

    int &operator[](int);

    int operator[](int) const;

private:
    int size;
    int *ptr;
};

#endif
```

#### Array.cpp

```cpp
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>;
using std::exit;

#include "Array.h"

Array::Array(int arraySize)
{
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[size];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }
}

Array::Array(const Array &arrayToCopy)
    : size(arrayToCopy.size)
{
    ptr = new int[size];

    for (int i = 0; i < size; i++)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

Array::~Array()
{
    delete[] ptr;
}

int Array::getSize() const
{
    return size;
}

const Array &Array::operator=(const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            ptr[i] = right.ptr[i];
        }
    }

    return *this;
}

bool Array::operator==(const Array &right) const
{
    if (size != right.size)
    {
        return false;
    }

    for (int i = 0; i < size; i++)
    {
        if (ptr[i] != right.ptr[i])
        {
            return false;
        }
    }

    return true;
}

int &Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript
             << "out of range" << endl;
        exit(1);
    }

    return ptr[subscript];
}

int Array::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= size)
    {
        cerr << "\nError: Subscript " << subscript
             << " out of range" << endl;
        exit(1);
    }

    return ptr[subscript];
}

istream &operator>>(istream &input, Array &a)
{
    for (int i = 0; i < a.size; i++)
    {
        input >> a.ptr[i];
    }

    return input;
}

ostream &operator<<(ostream &output, const Array &a)
{
    int i;

    for (i = 0; i < a.size; i++)
    {
        output << setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0)
        {
            output << endl;
        }
    }

    if (i % 4 != 0)
    {
        output << endl;
    }

    return output;
}
```

#### main.cpp

```cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Array.h"

int main()
{
    Array integers1(7);
    Array integers2;

    cout << "Size of Array integers1 is "
         << integers1.getSize()
         << "\nArray after initialization:\n"
         << integers1;

    cout << "Size of Array integers2 is "
         << integers2.getSize()
         << "\nArray after initialization:\n"
         << integers2;

    cout << "\nEnter 17 integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contatin:\n"
         << "integers1:\n"
         << integers1
         << "integers2:\n"
         << integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
    {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    Array integers3(integers1);

    cout << "\nSize of Array integers3 is "
         << integers3.getSize()
         << "\nArray after initialization:\n"
         << integers3;

    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2;

    cout << "integers1:\n"
         << integers1
         << "integers2:\n"
         << integers2;

    cout << "\nEvaluating: integers1 == integers2" << endl;

    return 0;
}
```

## 9. Overloading ++ and –

### 증가/감소 연산자의 오버로딩

- Date 클래스 객체 d1에 1을 더하려고 함
- Prototype (member function을 이용한 오버로딩)
  - `Date &operator++();`
  - `++d1`은 `d1.operator++()`과 동일
- Prototype (Global function을 이용한 오버로딩)
  - `Date &operator++(Date& );`
  - `++d1`은 `d1.operator++(d1)`과 동일

### 접두(prefix), 접미(postfix) 증가의 구분

- 예) a++, ++a
- 접미 증가의 경우 공 매개변수(dummy parameter)를 이용
  - 정수 0
- Prototype (member function을 이용한 오버로딩)
  - `Date operator++();`
  - `d1++`은 `d1.operator++(0) // C++의 약속`
- Prototype (Global function을 이용한 오버로딩)
  - `Date operator++(Date&, int);`
  - `d1++`은 `d1.operator++(d1, 0)`과 동일

### 접두(prefix), 접미(postfix) 증가의 반환값

- 반환값

  - 접두 증가 (prefix increment)
    - 참조형 반환 (`Date &`)
    - C++은 반환값을 lvalue로 취급 -> assign 가능
  - 접미 증가 (post increment)
    - 값에 의한 반환 (Returns by value)
    - 이전 값을 가진 임시 객체 반환
    - C++은 반환값을 rvalue로 취급 -> assign 불가능

- 감소 연산자(--) 의 경우도 같은 방식으로 적용

## 10. Case Study: A Date Class

### Date 클래스 예제

#### 개요

- 증가 연산자 오버로드
  - 일, 월, 년을 변화
- 윤년 (leap years) 테스트를 위한 함수
- += 연산자 오버로드
- 일년 마지막 날임을 판단하는 함수

#### date.h

```cpp
#pragma once

#include <iostream>
using std::ostream;

class Date
{
    friend ostream &operator<<(ostream &, const Date &);

public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date &operator++();
    Date operator++(int);
    const Date &operator+=(int);
    bool leapYear(int) const;
    bool endOfMonth(int) const;

private:
    int month;
    int day;
    int year;

    static const int days[];
    void helpIncrement();
};
```

#### date.cpp

```cpp
#include <iostream>
#include "Date.h"

const int Date::days[] =
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

void Date::setDate(int mm, int dd, int yy)
{
    month = (mm >= 1 && mm <= 12) ? mm : 1;
    year = (yy >= 1900 && yy <= 2100) ? yy : 1900;

    if (month == 2 && leapYear(year))
        day = (dd >= 1 && dd <= 29) ? dd : 1;
    else
        day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}

Date &Date::operator++()
{
    helpIncrement();
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    helpIncrement();

    return temp;
}

const Date &Date::operator+=(int additionalDays)
{
    for (int i = 0; i < additionalDays; i++)
    {
        helpIncrement();
    }
    return *this;
}

bool Date::leapYear(int testYear) const
{
    if (testYear % 400 == 0 ||
        (testYear % 100 != 0 && testYear % 4 == 0))
        return true;
    else
        return false;
}

bool Date::endOfMonth(int testDay) const
{
    if (month == 2 && leapYear(year))
        return testDay == 29;
    else
        return testDay == days[month];
}

void Date::helpIncrement()
{
    if (!endOfMonth(day))
        day++;
    else
    {
        if (month < 12)
        {
            month++;
            day = 1;
        }
        else
        {
            year++;
            month = 1;
            day = 1;
        }
    }
}

ostream &operator<<(ostream &output, const Date &d)
{
    static char *monthName[13] = {"", "January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    output << monthName[d.month] << ' ' << d.day << ", " << d.year;
    return output;
}
```

#### main.cpp

```cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

int main()
{
    Date d1;
    Date d2(12, 27, 1992);
    Date d3(0, 99, 8045);

    cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3;
    cout << "\n\nd2 += 7 is " << (d2 += 7);

    d3.setDate(2, 28, 1992);
    cout << "\n\n d3 is " << d3;
    cout << "\n++d3 is " << ++d3 << " (leap year allows 29th)";

    Date d4(7, 13, 2002);

    cout << "\n\nTesting the prefix increment operator:\n"
         << " d4 is " << d4 << endl;
    cout << "++d4 is " << ++d4 << endl;
    cout << " d4 is " << d4;
    cout << "\n\nTesting the postfix increment operator:\n"
         << " d4 is " << d4 << endl;
    cout << "d4++ is " << d4++ << endl;
    cout << " d4 is " << d4 << endl;

    return 0;
}
```
