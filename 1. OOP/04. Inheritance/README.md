# Inheritance

1. Introduction
2. Base Classes and Derived Classes
3. Protected Members
4. CommissionEmployee Class
5. BasePlusCommissionEmployeeClass WITHOUT Using Inheritance
6. Creating an Inheritance Hierarchy
7. Inheritance Hierarchy Using protected Data
8. Inheritance Hierarchy Using private Data
9. 상속 구조에서 생성자, 소멸자의 실행 순서
10. public, protected and private Inheritance

## 1. Introduction

### 객체지향 설계 (object-oriented design)

- 이미 만들어진 클래스를 파생시켜 새로운 클래스를 만드는 상속(inheritance)
  <img width="753" alt="스크린샷 2021-12-06 오후 5 08 19" src="https://user-images.githubusercontent.com/73745836/144810100-d5b3729b-8fc5-4653-a427-119a3861bd65.png">

### Inheritance (상속)

- 소프트웨어 재사용을 위한 효과적인 방법
- 기존 클래스로부터 새로운 클래스 생성
  - 기존 클래스의 속성과 행동 방식을 흡수
  - 새로운 속성과 행동 방식을 추가하여 보다 구체화함
- 기본 클래스로부터 상속받아 파생 클래스가 생성된다.
  - 객체들의 더 특화된(specialized) 그룹
  - 기본 클래스 (base class)로부터 행동 방식을 상속 받음
    - 자신만의 행동 방식으로 특화(customize) 가능
  - 추가적인 행동 방식도 포함

## 2. Base Classes and Derived Classes

### 클래스 계층 (class hierarchy)

- 직접 기본 클래스 (direct base class)
  - 직접 상속 받은 바로 위 단계 기본 클래스
- 간접 기본 클래스 (indirect base class)
  - 두 단계 이상 상위의 기본 클래스
- 단일 상속 (single inheritance)
  - 하나의 기본 클래스로부터 상속
- 다중 상속 (multiple inheritance)
  - 두 개 이상의 기본 클래스로부터 상속
    <img width="461" alt="스크린샷 2021-12-06 오후 5 10 18" src="https://user-images.githubusercontent.com/73745836/144810370-f65d620d-e575-42d8-96e4-8f7c38a6f15d.png">

### 상속의 세 종류

- public

  - 파생 클래스의 객체는 기본 클래스의 객체이기도 하다.
    - 기본 클래스의 객체는 파생 클래스의 객체가 될 수 없다.
    - e.g., 모든 자동차는 탈 것이다, 그러나 모든 탈 것은 차가 아니다.
  - 기본 클래스의 non-private 멤버에 접근 가능하다.
    - 기본 클래스의 private 멤버에 접근하기 위해서는
      - 파생 클래스는 반드시 상속받은 non-private 멤버 함수를 사용해야 한다.

- private, protected 잘 사용하지 않으므로 본 강의에서는 public 상속에 초점

### 상속 관계의 의미

- 추상화(abstraction)
  - 시스템의 모든 객체들의 공통성에 주목
- “is-a” 관계 vs. “has-a” 관계
  - “is-a” 관계 – 상속
    - 파생 클래스의 객체는 기본 클래스의 객체처럼 다뤄진다.
    - e.g., 차는 탈 것이다. (Car **is a** vehicle)
  - “has-a” 관계 – 복합 (composition) 관계
    - 객체가 다른 클래스의 객체를 멤버로 포함하는 것
    - e.g., 차에는 운전대가 있다. (Car **has a** steering wheel)

### Software Engineering Observation

> Member functions of a derived class cannot directly access private members of the base class.

### 기본 클래스는 파생 클래스보다 더 넓은 범위의 객체를 표현

- e.g.,
  - 기본 클래스 : Vehicle
    - 차(car), 트럭, 보트, 자전거 등을 포함
  - 파생 클래스 : Car
    - 작고 보다 특화된 탈 것(vehicle)의 종류

| Base class | Derived classes                            |
| ---------- | ------------------------------------------ |
| Student    | GraduateStudent, UndergraduateStudent      |
| Shape      | Circle, Triangle, Rectangle, Sphere, Cube  |
| Loan       | CarLoan, HomeImprovementLoan, MortgageLoad |
| Employee   | Faculty, Staff                             |
| Account    | CheckingAccount, SavingAccount             |

### 상속 계층 구조 (Inheritance hierarachy)

- 상속 관계는 트리(tree) 형태의 계층 구조를 형성한다.
- 각 클래스는 다음과 같다.
  - 기본 클래스 (base class)
    - : 파생 클래스에 속성 / 행동 방식을 공급한다.
  - 파생 클래스 (derived class)
    - : 기본 클래스로부터 속성 / 행동 방식을 상속받는다

## 3. Protected Members

### Public 상속

- e.g,
  - `Class TwoDimensionalShape : public Shape`
  - : TwoDimensionalShape 클래스는 Shape 클래스로부터 상속 받음
- 기본 클래스 private 멤버
  - 직접적으로 접근할 수 없지만 상속된다. - 상속된 public 멤버 함수를 통해 접근할 수 있다.
    <img width="702" alt="스크린샷 2021-12-06 오후 5 26 58" src="https://user-images.githubusercontent.com/73745836/144812539-a27b8b5f-9dfa-42ed-a3a8-e89f3ffe8995.png">

### 접근 지정자 protected

- protected 접근
  - public 과 private의 중간 보호 단계
  - protected 멤버는 다음을 통해 접근 가능하다.
    - 기본 클래스의 멤버와 파생 클래스의 멤버
- 파생 클래스 멤버
  - 기본 멤버의 public 과 protected 멤버에 직접 접근 가능
    - 간단히 멤버 이름을 사용
  - 파생 클래스에서 재정의된 기본 클래스 멤버는 기본 클래스 이름과 이항 스코프 식별 연산자(`::`) 를 이용하여 접근할 수 있다.
    - e.g., `shape::area`

### Protected로 선언된 변수가 허용하는 접근의 범위

![IMG_FF955B32D458-1](https://user-images.githubusercontent.com/73745836/145048534-2b0560b1-8fbc-4731-8cb8-a0014cdaabf5.jpeg)

## 4. CommissionEmployee Class

### 기본 클래스와 파생 클래스 예제 개요

- CommissionEmployee – BasePlusCommissionEmployee 상속 계층
  - CommissionEmployee
    - First name, last name, SSN, commission rate, gross sale amount
  - BasePlusCommissionEmployee
    - First name, last name, SSN, commission rate, gross sale amount
    - 기본 봉급
  - ㈜ Commission Employee: 판매 금액의 일부를 수당으로 가져가는 영업 사원 (기본 월급이 있을 수도, 없을 수도 있음)

### CommissionEmployee 클래스 구성

- CommissionEmployee 헤더 파일 (다음 예제)
  - public services
    - 생성자
    - get 과 set 함수
    - 멤버 함수 earnings, print
- CommissionEmployee 소스 코드 파일 (다음 예제)

### CommissionEmployee 클래스 예제

#### CommissionEmployee.h

```cpp
#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>
using std::string;

class CommissionEmployee
{
public:
    CommissionEmployee(const string &, const string &, const string &, double = 0.0, double = 0.0);

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

#### main.cpp

```cpp
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "CommissionEmployee.h"

int main()
{
    CommissionEmployee employee(
        "Sue", "Jones", "222-22-2222", 10000, .06);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get functions: \n"
         << "\nFirst name is " << employee.getFirstName()
         << "\nLast name is " << employee.getLastName()
         << "\nSocial security number is " << employee.getSocialSecurityNumber()
         << "\nGross sales is " << employee.getGrossSales()
         << "\nCommission rate is " << employee.getCommissionRate() << endl;

    employee.setGrossSales(8000);
    employee.setCommissionRate(.1);

    cout << "\nUpdate employee information output: " << endl;
    employee.print();

    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;

    return 0;
}
```

## 5. BasePlusCommissionEmployeeClass WITHOUT Using Inheritance

### 상속을 이용하여 구현한 BasePlusCommissionEmployee 클래스

- CommissionEmployee 클래스로부터 상속받아 파생
  - is-a CommissionEmployee
  - 모든 public 멤버 상
- 생성자는 상속되지 않는다.
  - 기본 클래스의 데이터 멤버 초기화를 위해 기본 클래스 초기화 구문을 사용
- 데이터 멤버 baseSalary를 갖는다.

#### BasePlusCommissionEmployee.h

```cpp
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
using std::string;

#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &, const string &,
                               double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    void print() const;

private:
    double baseSalary;
};

#endif
```

### BasePlusCommissionEmployee.cpp

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
    return baseSalary + (commissionRate * grossSales);
}

void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried commission emplyee: " << firstName << ' '
         << lastName << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate
         << "\nbase salary: " << baseSalary;
}
```

> 상속은 잘 되었으나, Base class의 Private 멤버에 접근하는 방식에서 컴파일 오류 발생

## 6. Creating an Inheritance Hierarchy

- 기본 클래스 헤더 파일을 include 한다.
  - 기본 클래스의 헤더 파일은 다음 세가지로 이유로 반드시 파생 클래스 헤더 파일에 include 되어야 한다.
    - 기본 클래스의 존재를 알기 위해
    - 상속된 데이터 멤버의 크기를 알기 위해
    - 상속된 클래스의 멤버가 올바르게 사용되는지 알기 위해

## 7. Inheritance Hierarchy Using protected Data

### Protected 데이터 사용

- BasePlusCommissionEmployee 클래스 (파생 클래스)가 기본 클래스
  - (CommissionEmployee) 데이터 멤버에 직접 접근하기 위해서 protected 데이터를 사용해야 한다.
- 기본 클래스의 protected 멤버는 기본 클래스의 모든 파생 클래스에 상속되며 파생
  클래스의 멤버 함수에서 접근할 수 있다.

### Protected 멤버를 이용한 CommissionEmployee 클래스 개선

#### CommissionEmployee.h

```cpp
#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>
using std::string;

class CommissionEmployee
{
public:
    CommissionEmployee(const string &, const string &, const string &, double = 0.0, double = 0.0);

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

protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

#endif
```

#### BasePlusCommissionEmployee.h

```cpp
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
using std::string;

#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &, const string &,
                               double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    void print() const;

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
    // explicitly call base-class constructor
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
    // can access protected data of base class
    return baseSalary + (commissionRate * grossSales);
}

void BasePlusCommissionEmployee::print() const
{
    // can access protected data of base class
    cout << "base-salaried commission emplyee: " << fFirstName << ' '
         << lastName << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate
         << "\nbase salary: " << baseSalary;
}
```

### Protected 접근 지정자 사용의 장단점

- 장점

  - 파생 클래스가 기본 클래스의 데이터 멤버를 바로 조절 가능
    - set | get 호출하는데 소모되는 오버헤드를 피할 수 있다.
    - 즉, 수행 속도가 조금 향상된다.

- 단점
  - 유효체크 불가 – set | get 함수를 사용하지 않으므로 파생 클래스에 비정상적인 값이 할당될 수 있다.
  - 실행 의존적
    - 파생 클래스 함수는 기본 클래스 구현에 더 의존적이 됨.
    - 기본 클래스를 수정하면 파생 클래스 또한 조절 되어야 한다.
      - 부서지기 쉬운(fragile) 소프트웨어

## 8. Inheritance Hierarchy Using private Data

### 계층 구조의 개선

- 소프트웨어 공학 기법의 권고를 따름

  - 데이터 멤버는 private로 선언
  - public get 과 set 멤버 함수 제공
  - 기본 클래스에서 상속된 get 멤버 함수를 사용하여 파생 클래스에서 기본 클래스의 private 데이터 멤버의 값을 얻도록 함

- 파생 클래스에서 재정의된(override된) 멤버 함수의 호출 방식
- 파생 클래스 함수 내부에서는 그 함수 이름만으로는 재정의된 파생 클래스의 멤버 함수를 호출함
- 따라서, 같은 이름의 기본 클래스의 멤버 함수를 호출하기 위해서는 `기본 클래스이름::함수 이름`과 같이 호출해야 함

### CommissionEmployee 클래스 개선 (최종버전)

#### CommissionEmployee.h

```cpp
#include <iostream>
using std::cout;

#include "CommissionEmployee.h"

// constructor
CommissionEmployee::CommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn)
{
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
    return getCommissionRate() * getGrossSales();
}

void CommissionEmployee::print() const
{
    cout << "commission employee: " << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate();
}
```

#### BasePlusCommissionEmployee.cpp

```cpp
#include <iostream>
using std::cout;

#include "BasePlusCommissionEmployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary)
    // explicitly call base-class constructor
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
    // can access protected data of base class
    return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const
{
    // can access protected data of base class
    cout << "base-salaried ";

    // invoke CommissionEmployee's print function
    CommissionEmployee::print();

    cout << "\nbase salary: " << getBaseSalary();
}
```

#### 설계된 클래스 활용 (driver)

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

#include "BasePlusCommissionEmployee.h"

int main()
{
    // instantiate BasePlusCommissionEmployee object
    BasePlusCommissionEmployee
        employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get function: \n"
         << "\nFirst name is " << employee.getFirstName()
         << "\nLast name is " << employee.getLastName()
         << "\nsocial security number is " << employee.getSocialSecurityNumber()
         << "\nGross sales is " << employee.getGrossSales()
         << "\ncommission rate is " << employee.getCommissionRate()
         << "\nBase salary is " << employee.getBaseSalary() << endl;

    employee.setGrossSales(1000);

    // employee.setGrossSales(8000);
    // employee.setCommissionRate(.1);

    cout << "\nUpdated employee information ouput bt print function: \n"
         << endl;
    employee.print();

    cout << "\n\nEmployee's earning: $" << employee.earnings() << endl;

    return 0;
}
```

#### 설계된 클래스 활용 (실행 결과)

<img width="697" alt="스크린샷 2021-12-06 오후 8 31 03" src="https://user-images.githubusercontent.com/73745836/144838717-beb0c773-880f-4bb1-bc21-73004ed203f6.png">

## 9. 상속 구조에서 생성자, 소멸자의 실행 순서

### 파생 클래스 객체의 생성 과정

- 기본 클래스의 생성자와 소멸자는 파생클래스에 상속되지 않는다.
- 파생 클래스 객체의 생성 과정
  - 연쇄적인 생성자 호출/실행/리턴 매커니즘
    - 파생클래스 생성자는 기본 클래스 생성자를 호출한다.
      - 명시적(explicitly) 혹은 암시적(implicitly)
    - 최상위 단계의 기본 클래스
      - 마지막으로 생성자가 호출됨
      - 처음으로 생성자 실행을 마치고 리턴
    - CommissionEmployee/BasePlusCommissionEmployee 계층
      - CommissionEmployee: 마지막에 생성자 호출하고 처음으로 생성자 실행을 마침
    - 데이터 멤버 초기화
      - 각 기본 클래스의 생성자는 파생 클래스의 member initializer에서 호출되어 자신의 데이터 멤버를 초기화한다.

### 파생 클래스 객체의 소멸 과정

- 연쇄적 소멸자 호출
  - 연쇄적 생성자 구조의 반대 (함수의 body의 실행순서)
  - 파생 클래스의 소멸자가 처음 호출 및 실행
  - 그 다음 상위 기본 클래스 소멸자 호출 및 실행
    - 최종 기본 클래스에 도착할 때까지 계속
    - 리턴 순서는 기본 클래스 -> 파생 클래스의 순서
      - 가장 하위의 파생 클래스 소멸자가 최종적으로 리턴하면 메모리에서 객체가 제거된다.

<img width="275" alt="스크린샷 2021-12-06 오후 8 36 49" src="https://user-images.githubusercontent.com/73745836/144839451-ad345dbd-36a4-4ed6-8063-b8f80261924a.png">

### 생성자 및 소멸자 호출 순서 예제

#### CommissionEmployee.cpp

```cpp
#include <iostream>
using std::cout;

#include "CommissionEmployee.h"

// constructor
CommissionEmployee::CommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);

    cout << "CommissionEmployee constuctor: " << endl;
    print();
    cout << "\n\n";
}

// destructor
CommissionEmployee::~CommissionEmployee()
{
    cout << "CommissionEmployee desturctor: " << endl;
    print();
    cout << "\n\n";
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
    return getCommissionRate() * getGrossSales();
}

void CommissionEmployee::print() const
{
    cout << "commission employee: " << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate();
}
```

#### BasePlusCommissionEmployee.cpp

```cpp
#include <iostream>
using std::cout;

#include "BasePlusCommissionEmployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary)
    // explicitly call base-class constructor
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);

    cout << "BasePlusCommissionEmployee constructor: " << endl;
    print();
    cout << "\n\n";
}

// destructor
BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{
    cout << "BasePlusCommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
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
    // can access protected data of base class
    return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const
{
    // can access protected data of base class
    cout << "base-salaried ";

    // invoke CommissionEmployee's print function
    CommissionEmployee::print();

    cout << "\nbase salary: " << getBaseSalary();
}
```

#### driver

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

#include "BasePlusCommissionEmployee.h"

int main()
{
    cout << fixed << setprecision(2);

    { // begin new scope
        CommissionEmployee employee1("Bob", "Lewis", "111-11-1111", 1000, .01);

    } // end scope

    cout << endl;
    BasePlusCommissionEmployee employee2("Peter", "Lee", "221-12-2222", 2000, .02, 222);

    cout << endl;
    BasePlusCommissionEmployee employee3("JJang-gu", "Shin", "331-13-3113", 3000, .03, 333);

    cout << endl;
    return 0;
}
```

#### 실행결과

```
CommissionEmployee constuctor:
commission employee: Bob Lewis
social security number: 111-11-1111
gross sales: 1000.00
commission rate: 0.01

CommissionEmployee desturctor:
commission employee: Bob Lewis
social security number: 111-11-1111
gross sales: 1000.00
commission rate: 0.01


CommissionEmployee constuctor:
commission employee: Peter Lee
social security number: 221-12-2222
gross sales: 2000.00
commission rate: 0.02

BasePlusCommissionEmployee constructor:
base-salaried commission employee: Peter Lee
social security number: 221-12-2222
gross sales: 2000.00
commission rate: 0.02
base salary: 222.00


CommissionEmployee constuctor:
commission employee: JJang-gu Shin
social security number: 331-13-3113
gross sales: 3000.00
commission rate: 0.03

BasePlusCommissionEmployee constructor:
base-salaried commission employee: JJang-gu Shin
social security number: 331-13-3113
gross sales: 3000.00
commission rate: 0.03
base salary: 333.00


BasePlusCommissionEmployee destructor:
base-salaried commission employee: JJang-gu Shin
social security number: 331-13-3113
gross sales: 3000.00
commission rate: 0.03
base salary: 333.00

CommissionEmployee desturctor:
commission employee: JJang-gu Shin
social security number: 331-13-3113
gross sales: 3000.00
commission rate: 0.03

BasePlusCommissionEmployee destructor:
base-salaried commission employee: Peter Lee
social security number: 221-12-2222
gross sales: 2000.00
commission rate: 0.02
base salary: 222.00

CommissionEmployee desturctor:
commission employee: Peter Lee
social security number: 221-12-2222
gross sales: 2000.00
commission rate: 0.02
```

<img width="953" alt="스크린샷 2021-12-06 오후 8 56 00" src="https://user-images.githubusercontent.com/73745836/144841889-827e03f8-1d8d-400d-8816-db0d35fee494.png">
<img width="953" alt="스크린샷 2021-12-06 오후 8 56 26" src="https://user-images.githubusercontent.com/73745836/144841909-2965d541-c79d-4cb9-ad55-68614dd749de.png">

## 10. Public, protected and private Inheritance

### Public 상속, Protected 상속 및 private 상속

#### Public 상속

- 기본 클래스 public 멤버
  - 파생 클래스 public 멤버
- 기본 클래스 protected 멤버
  - 파생 클래스 protected 멤버
- 기본 클래스 private 멤버는 직접 접근 불가능
  - 기본 클래스의 public 멤버 함수를 통해 접근 가능

#### protected 상속

- 기본 클래스 public 과 protected 멤버
  - 파생 클래스 protected 멤버

#### private 상속

- 기본 클래스 public 과 protected 멤버
  - 파생 클래스 private 멤버

<img width="953" alt="스크린샷 2021-12-06 오후 8 58 20" src="https://user-images.githubusercontent.com/73745836/144842147-5bbb7adc-1cb8-4677-ab74-d2a9b4f6c83b.png">
<img width="953" alt="스크린샷 2021-12-06 오후 8 58 35" src="https://user-images.githubusercontent.com/73745836/144842178-61966ef7-ffdc-4c2a-910b-dfc68160c4ae.png">

### 파생 클래스에서의 기본 클래스 데이터 멤버 접근성

<img width="718" alt="스크린샷 2021-12-06 오후 8 59 02" src="https://user-images.githubusercontent.com/73745836/144842239-4e3fe79a-f23c-46f3-8b46-64e95911fd46.png">
