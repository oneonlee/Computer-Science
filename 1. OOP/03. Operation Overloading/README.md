# Operator Overloading

## Contents
1. Introduction
2. Operator Overloading 기본사항
3. Operator Overloading 제한조건
4. Operator Functions as Class Members vs. Global Functions
5. Overloading Stream Insertion and Stream Extraction Operators
6. Overloading Unary Operators
7. Overloading Binary Operators

## 1. Introduction
### 연산자 오버로딩이란?
- 클래스 객체에 기본형 및 사용자 정의형 연산자를 이용
  - 예) Time 클래스 객체끼리 덧셈 연산?
  - 연산자 오버로딩 (operator overloading) 이라고도 함
  - 특정 클래스의 멤버 함수 호출보다 명확
  - 문맥(context)에 따라 적응적으로 동작
- 예시
  - <<:스트림 삽입(stream-insertion), 비트단위 왼쪽 시프트 (bitwise left-shift)
  - + : 다양한 아이템(integers, floats, etc.) 들 간의 덧셈 연산을 수행

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
  - 대입 연산자(=)
    - 클래스에 속한 데이터 멤버들을 멤버 별로 복사한다.
  - 주소 연산자(&)
    - 객체의 주소 값을 반환한다.			

### 오버로딩은 객체간 연산의 간결한 표현을 제공
- Overloading 하지 않았을 때
  - `object2	=	object2.add(object1);`
- Overloading 했을 때
  - `object2	=	object2	+	object1;`

### 3. Operator Overloading 제한조건
### 연산자 오버로딩으로도 변경 불가능한 것은?
- 연산자의 우선순위 (중간 계산 순서)
  - e.g., A * B + C
  - 연산자의 순서를 바꾸기 위해서 괄호를 사용한다.
- 연산자의 결합 순서 (left-to-right 또는 right-to-left)
- 피연산자(operand)의 개수
  - e.g., &은 단항(unary) 연산자이므로, 단 하나의 피연산자만을 취함
- 내장 타입의 객체에 적용되는 연산 방법
  (i.e., 정수 덧셈에 사용되는 + 연산자의 의미를 바꿀 수 없다.)

- 새로운 연산자를 만드는 것은 불가능
- 연산자는 명확하게 오버로딩 되어야 한다.
  - = 와 + 연산자가 오버로딩 되었다고 해서 += 연산자가 오버로딩 된 것은 아니다.
- 연산자 ?: 는 오버로딩 될 수 없다.

### 연산자 오버로딩할 수 없는 연산자
<img width="675" alt="스크린샷 2021-12-02 오후 9 18 08" src="https://user-images.githubusercontent.com/73745836/144420521-87cdc77b-1f2c-4dac-9756-fa7e32a81fcb.png">



## 4. Operator Functions as Class Members vs. Global Functions
### 멤버 함수로서의 연산자 함수
- (피연산자1 연산자 피연산자2) 일 때, 피연산자1이 연산자가 정의된 클래스의 객체가 되어야 한다.
- 이항 연산자 (binary operator) 의 왼쪽 피연산자의 인자를 얻기 위해 암시적으로 키워드를 사용한다.
- 연산자 (), [], -> 또는 대입 연산자(=)는 클래스 멤버 함수로 오버로드 되어야 한다.
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

#### driver
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

