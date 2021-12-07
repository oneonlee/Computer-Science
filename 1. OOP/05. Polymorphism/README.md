# Polymorphism

## Contents
1. Introduction
2. Polymorphism 사례
3. 핸들의 자료형에 의한 멤버 함수 호출 (without Polymorphism)
4. Polymorphism 구현 (가상 함수에 의한 동적 바인딩)
5. Abstract Classes and Pure Virtual Functions
6. Case Study: Payroll System Using Polymorphism



## 1. Introduction
### 함수 오버로딩 vs. 함수 오버라이딩
#### 함수 오버로딩 (Overloading)
오버로딩은 같은 함수라도 매개변수만 다르면 얼마든지 정의하고 사용할 수 있다.
- 함수 이름이 같아야 한다.
- 매개변수의 자료형이 다르거나 개수가 달라야 한다.
- 반환형의 차이는 오버로딩의 조건을 만족시키지 않는다.

#### 함수 오버라이딩 (Overriding)
상속 관계에 있는 클래스 간의 같은 이름의 함수를 정의하는 것으로서, 기본 클래스에서 선언된 함수와 같은 이름의 함수가 파생 클래스에서 재정의되어 사용되는 경우 오버라이드 되었다고 한다.
- 오버라이드 하고자 하는 함수가 기본 클래스에 존재해야 한다.
- 함수 이름이 같아야 한다.
- 매개변수의 개수 및 자료형, 반환형이 동일해야 한다.

### 상속 계층 구조에서의 다형성 (polymorphism)
- 클래스 계층 구조에서의 다양한 객체들에 대해서, 마치 객체들이 기반 클래스의 객체인 것처럼 처리
- 이 때, 각 객체는 자신에게 적합한 작업을 수행
  - 즉, 서로 다른 형의 객체는 서로 다른 작업을 수행
- 기존의 코드를 수정하지 않고 새로운 클래스를 추가할 수 있는 효율적인 방법임

> 동적 바인딩  Dynamic binding =Late binding =Runtime binding

#### new 연산자는 동적으로 배열을 할당할 수 있다.
- 10개의 정수 원소를 갖는 배열을 할당
`int* gradesArray = new int[10];`
- 동적 할당 배열의 크기
  - 프로그램 내에서 정수 변수나 정수 변수의 수식 표현을 통해 나타낼 수 있음
  - `int* gradesArray = new int[count1+count2];`

## 2. Polymorphism 사례
### 사례: Animal 클래스 계층에서 다형성 동작
- Animal 기본 클래스와 모든 파생 클래스 (Fish, Frog, Bird)는 move 함수를 갖는다.
- 서로 다른 파생 클래스 객체 포인터들은 Animal* 형의 핸들에 저장
- 프로그램은 같은 메시지를 (예: move) 각 Animal 객체에 전달한다. 즉, 핸들로 move 함수 호출
- 이 때, 각 객체는 자신에게 적당한 함수를 호출한다.
  - Fish 는 수영하며 move를 수행
  - Frog 는 점프하며 move를 수행
  - Bird 는 날아가며 move를 수행

#### 핸들이란?
- 핸들은 구체적인 어떤 대상을 접근하기 위한 용도로 쓰이는 매개체이다.
- 핸들로서 레퍼런스 변수와 포인터 변수, 반복자가 여기에 해당한다.

### Polymorphism 동작 메커니즘
1. Derived class 객체를 base class의 포인터/참조형 핸들로 받음
2. Base class에서 가상(virtual) 함수로 선언된 함수를 실행시킬 때 동작
  - c++는 객체를 실제로 생성한 클래스 (즉, derived class)의 함수를 실행시키게 됨
  - 핸들(handle)의 자료형(즉, base class)의 함수가 아님

- -> virtual function을 이용하여 동작 메커니즘을 구현 가능

## 3. 핸들의 자료형에 의한 멤버 함수 호출 (without Polymorphism)
### Virtual 함수를 사용하지 않을 때 (without using polymorphism)
- Base class의 포인터 핸들이 base class의 객체를 가리키면
  - 핸들의 자료형과 실제 객체의 자료형이 같음
  - 핸들 자료형의 함수를 호출 -> base class 함수 호출
- Derived class의 포인터 핸들이 derived class의 객체를 가리키면
  - 핸들의 자료형과 실제 객체의 자료형이 같음
  - 핸들 자료형의 함수를 호출 -> derived class 함수 호출
- Base class의 포인터 핸들이 derived class의 객체를 가리키면
  - 핸들은 base class의 포인터, 실제 객체는 파생 클래스의 객체임
  - 핸들 자료형의 함수를 호출 -> base class 함수 호출

### 가상 함수 (virtual function)의 기능
- virtual 함수를 사용하지 않을 때 (w/o using polymorphism)
  - 함수의 호출은 객체의 핸들(handle)의 자료형에 의해서 결정됨
  - 생성된 객체의 실제 자료형이 아님
- virtual 함수를 이용할 때 (using polymorphism)
  - (핸들의 자료형이 아닌) 실제 객체의 자료형이 호출할 가상함수를 결정하게 된다.
  - c++에서 객체지향 설계의 다형성(polymorphism) 구현의 방법임

### 핸들의 자료형에 의한 함수 호출 예제 (w/o polymorphism)
#### CommissionEmployee.h
```cpp
#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>
using namespace std;

class CommissionEmployee
{
public:
    CommissionEmployee(const string &, const string &, const string &,
                       double = 0.0, double = 0.0);

    void setFirstName(const string &);
    string getFirstName() const;

    void setLastName(const string &);
    string getLastName() const;

    void setSocialSecurityNumber(const string &);
    string getSocialSecurityNumber() const;

    void setGrossSales(double);
    double getGrossSales() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    double earnings() const;
    void print() const;

private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

#endif
```

#### CommissionEmployee.cpp
```cpp
#include "CommissionEmployee.h"
#include <iostream>
#include <string>

using namespace std;

CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate)
{
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

double CommissionEmployee::earnings() const
{
    return commissionRate * grossSales;
}

double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

string CommissionEmployee::getFirstName() const
{
    return firstName;
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

string CommissionEmployee::getLastName() const
{
    return lastName;
}

string CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void CommissionEmployee::print() const
{
    cout << "commission employee: "
         << getFirstName() << ' ' << getLastName() << endl
         << "social security number: " << getSocialSecurityNumber() << endl
         << "gross sales: " << getGrossSales() << endl
         << "commission rate: " << getCommissionRate() << endl;
}

void CommissionEmployee::setCommissionRate(double rate)
{
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0;
}

void CommissionEmployee::setFirstName(const string &first)
{
    firstName = first;
}

void CommissionEmployee::setGrossSales(double sales)
{
    grossSales = sales < 0.0 ? 0 : sales;
}

void CommissionEmployee::setLastName(const string &last)
{
    lastName = last;
}

void CommissionEmployee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}
```

#### BasePlusCommissionEmployee.h
```cpp
#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee(const string &, const string &, const string &,
                               double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    void print() const;
    double earnings() const;
};

#endif
```

#### BasePlusCommissionEmployee.cpp
```cpp
#include "BasePlusCommissionEmployee.h"
#include <iostream>
#include <string>
#include "CommissionEmployee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "base salary: " << baseSalary << endl;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary = salary < 0.0 ? 0 : salary;
}
```

#### main.cpp
<img width="1264" alt="스크린샷 2021-12-07 오후 10 36 17" src="https://user-images.githubusercontent.com/73745836/145038869-7a6a9487-9e5d-43f8-bcd5-90fefa249940.png">
> print() 함수를 virtual로 선언했을 때와 아닐 때의 차이점(위에서 * 부분)을 확인할 것

### 파생 클래스의 포인터가 기본 클래스의 객체를 가리킬 때
- C++ 컴파일러에서 에러 생성
  - CommissionEmployee (기본 클래스 객체) is not a BasePlusCommissionEmployee (파생 클래스 객체)
- 만약 이것이 허용된다면, 프로그래머는 존재하지 않는 파생 클래스의 멤버에 접근할 것이다.
  - 전혀 엉뚱한 데이터에 사용되는 메모리 내용을 변경하는 오류가 발생 가능

#### 예제 (파생 클래스의 포인터가 기본 클래스의 객체를 가리킬 때)
##### main.cpp
```cpp
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

int main()
{
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "222-22-2222", 10000, .06);
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

    // aim derived-class pointer at base-class object
    // Error: a CommissionEmployee is not a BasePlusCommissionEmployee
    basePlusCommissionEmployeePtr = &commissionEmployee;

    return 0;
}
```

##### Error Message
<img width="731" alt="스크린샷 2021-12-07 오후 10 44 04" src="https://user-images.githubusercontent.com/73745836/145040122-62e2ab58-4b92-4552-9b90-409e43c0ea55.png">

### 기본 클래스의 포인터가 파생클래스 객체를 가리킬 때
- 기본 클래스에 존재하는 함수를 호출하면 기본 클래스의 기능이 수행
- 파생 클래스에만 존재하는 함수를 호출하면 컴파일 에러 발생
  - 기본적으로 파생 클래스의 멤버는 기본 클래스의 객체 포인터로부터 접근할 수 없다.
  - 억지로 downcasting을 이용하면 가능

## 4. Polymorphism 구현 (가상 함수에 의한 동적 바인딩)
### 가상 함수 (Virtual Function) 사용에 의한 동적 바인딩
- 일반적인 경우 (w/o virtual function)
  - 핸들(handle)이 어떠한 클래스 함수를 호출할지 결정한다.
- 가상 함수 사용의 경우
  - 핸들의 자료형이 아닌, 가리키고 있는 객체의 실제 자료형이 가상 함수의 어떤 구현을 사용할지 결정하게 된다.
  - 프로그램이 동적으로 (컴파일 시간이 아닌 실행시간에) 어떤 클래스의 함수를 사용할지 결정한다.
    - 동적 바인딩 (dynamic binding) 이라고 함

### 가상 함수 (Virtual Function) 선언
- 기본 클래스 선언에서 virtual 키워드를 함수 원형 앞에 붙임으로써 가상함수를 선언
  - 예) virtual void print()
- 파생 클래스는 기본 클래스의 가상 함수를 override 한다.
- 기본 클래스의 가상 함수는, 모든 계층의 파생 클래스에서 역시 virtual 함수이다

### 정적 바인딩과 동적 바인딩
#### 정적 바인딩 (static binding)
특정 객체가 dot operator를 사용하여 멤버 함수를 호출하면, virtual 여부에 관계없이 호출된 함수는 (핸들에 의해) 컴파일 시간에 결정된다.
#### 동적 바인딩 (dynamic binding)
가상함수의 동적 바인딩은 포인터 또는 참조형의 핸들에서만 이루어진다.

### 동적 바인딩 예제 
#### CommissionEmployee.h
```cpp
#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>

using namespace std;

class CommissionEmployee
{
public:
    CommissionEmployee(const string &, const string &, const string &,
                       double = 0.0, double = 0.0);

    void setFirstName(const string &);
    string getFirstName() const;

    void setLastName(const string &);
    string getLastName() const;

    void setSocialSecurityNumber(const string &);
    string getSocialSecurityNumber() const;

    void setGrossSales(double);
    double getGrossSales() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    virtual double earnings() const;
    virtual void print() const;

private:
    // protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

#endif
```

#### CommissionEmployee.h
```cpp
#include <iostream>
using std::cout;

#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate)
{
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

void CommissionEmployee::setFirstName(const string &first)
{
    firstName = first;
}

string CommissionEmployee::getFirstName() const
{
    return firstName;
}

void CommissionEmployee::setLastName(const string &last)
{
    lastName = last;
}

string CommissionEmployee::getLastName() const
{
    return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales)
{
    grossSales = (sales < 0.0) ? 0.0 : sales;
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate)
{
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
}

double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

double CommissionEmployee::earnings() const
{
    return commissionRate * grossSales;
}

void CommissionEmployee::print() const
{
    cout << "commission employee: " << firstName << ' ' << lastName
         << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate;
}
```

#### BasePlusCommissionEmployee.h
```cpp
#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &, const string &,
                               double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    virtual double earnings() const;
    virtual void print() const;

private:
    double baseSalary;
};

#endif
```

#### BasePlusCommissionEmployee.cpp
```cpp
#include <iostream>
using std::cout;

#include "BasePlusCommissionEmployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
    // double tempCommissionRate = getCommissionRate();
    // double tempGrossSales = getGrossSales();
    // return baseSalary + (tempCommissionRate * tempGrossSales);
    return baseSalary + (getCommissionRate() * getGrossSales());
}

void BasePlusCommissionEmployee::print() const
{

    cout << "base-salaried commission emplyee: " << getFirstName() << ' '
         << getLastName() << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate()
         << "\nbase salary: " << baseSalary;
}
```

#### driver
```cpp
#include <iostream>
#include <iomanip>

#include "BasePlusCommissionEmployee.h"
#include "CommissionEmployee.h"

using namespace std;

int main()
{
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "222-22-2222", 10000, 0.6);

    CommissionEmployee *commissionEmployeePtr = 0;

    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);

    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

    cout << fixed << setprecision(2);

    cout << "Invoking print function on base-class and derived-class "
         << "\nobjects with static binding\n\n";
    commissionEmployee.print();
    cout << "\n\n";
    basePlusCommissionEmployee.print();

    cout << "\n\n\nInvoking print function on base-class and "
         << "derived-class \nobjects with dynamic binding:";

    commissionEmployeePtr = &commissionEmployee;
    cout << "\n\nCalling virtual function print with base-class pointer"
         << "\n to base-class object invokes base-class "
         << "print function:\n\n";
    commissionEmployeePtr->print();

    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "\n\nCalling virtual function print with derived-class "
         << "pointer\nto derived-class object invokes derived-class "
         << "print function:\n\n";
    basePlusCommissionEmployeePtr->print();

    commissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "\n\nCalling virtual function print with base-class pointer "
         << "\nto derived-class object invokes derived-class "
         << "print function:\n\n";

    commissionEmployeePtr->print();
    cout << endl;
    return 0;
}
```

#### 실행 결과
<img width="1229" alt="스크린샷 2021-12-07 오후 10 51 54" src="https://user-images.githubusercontent.com/73745836/145041284-1bef4987-9ca7-4a1e-992a-b5e08ffd30d0.png">

## 5. Abstract Classes and Pure Virtual Functions
### 추상 클래스 (Abstract Class)
- Client가 실제로 객체를 생성하지 않는 (불완전한) 클래스
  - 파생 클래스들의 공통적이고 추상적인 특징만 정의함
    - -> 파생 클래스가 “빠진 부분＂을 정의해야 한다.
  - 실제 객체를 정의 하기에 너무 포괄적이다.
- 일반적으로 기본 클래스로 사용되며, 추상 기본 클래스 (abstract base class)라고 불린다.
  - 다른 클래스, 즉 구체적인 파생 클래스 (concrete class)에 상속될 수 있는 적합한 기본 클래스를 제공하기 위해 존재

### 순수 virtual 함수 (Pure Virtual Function)
- Pure virtual function을 사용하면 그 클래스는 추상 클래스가 됨
  - `Virtual void draw() const =0;`
- 함수 구현을 제공하지 않는다. (위 예제와 같은 원형만 존재)
  - 모든 구체 파생 클래스는 기본 클래스의 모든 pure virtual function을 재정의(override)하고 구체적 구현을 제공해야 함
    - -> 그렇지 않으면 파생 클래스 또한 추상 클래스가 된다.
- 기본 클래스에서 멤버 함수를 구현하는 것이 무의미할 때 사용됨
  - 실제 구현은 구체화된 파생 클래스에서 이루어 짐

### 추상 기본 클래스의 다형성에의 이용
- 포인터 또는 참조형 객체를 선언하여 (즉, 객체 생성 어이 핸들만 생성) 추상 기본 클래스를 사용할 수 있다.
  - 파생된 어떠한 구체 클래스의 객체라도 가리킬 수 있음
  - 프로그램은 일반적으로 이러한 포인터나 참조형을 이용하여 파생 클래스 객체의 다형성을 이용할 수 있다.
- 다형성은 계층화된 소프트웨어 시스템의 구현에 특히 효율적
  - 예) 여러 다른 장치(device)에서 데이터를 읽거나 쓸 때
    - 추상 클래스는 공통적인 인터페이스를 pure virtual function으로 제공하고, 실제 입출력은 파생 클래스에서 재정의한 함수가 담당

### 기존 Employee 클래스 계층 구조를 추상 클래스를 이용하여 개선
- 추상 클래스 Employee는 일반적인 ‘종업원’의 특징을 표현
  - 계층 구조의 “interface”를 선언
  - 각 종업원의 공통 속성 선언
    - -> first name, last name, social security number
- 수입(earnings)의 계산 방법 및 객체 정보의 출력 방법은 구체 파생 클래스 마다 모두 다름

### 기존 Employee 클래스 계층 구조를 추상 클래스를 이용하여 개선
<img width="882" alt="스크린샷 2021-12-07 오후 10 56 17" src="https://user-images.githubusercontent.com/73745836/145042061-aaa607cd-d787-4909-8ee6-014679a4e9c3.png">


## 6. Case Study: Payroll System Using Polymorphism
