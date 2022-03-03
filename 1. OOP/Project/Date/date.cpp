#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int m, int d, int y) // 세 데이터 멤버를 초기화하기 위해 세 매개 변수를 사용하는 생성자 제공
{
    setMonth(m);
    setDay(d);
    setYear(y);
};

void Date::setMonth(int m)
{
    if (m < 1 || m > 12) // 월 값이 1-12 사이의 범위에 있는지 확인
    {
        month = 1;
    }
    else
    {
        month = m;
    }
}

int Date::getMonth()
{
    return month;
}

void Date::setDay(int d) // 제공되는 '일' 값이 정확하다고 가정
{
    day = d;
}

int Date::getDay()
{
    return day;
}

void Date::setYear(int y) // 제공되는 '연도' 값이 정확하다고 가정
{
    year = y;
}

int Date::getYear()
{
    return year;
}

void Date::displayDate() // 월,일,년을 슬래시로 구분하여 출력하는 멤버함수
{
    cout << month << "/" << day << "/" << year << endl;
}