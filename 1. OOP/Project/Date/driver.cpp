#include <iostream>
#include "date.h"

using namespace std;

int main() // 클래스의 기능을 보여주는 테스트 프로그램
{
    int month, day, year;
    cout << "Month: ";
    cin >> month;
    cout << "Day: ";
    cin >> day;
    cout << "Year: ";
    cin >> year;

    Date originalDate(month, day, year);

    cout << "\nOriginal date:" << endl;
    originalDate.displayDate();

    originalDate.setMonth(12345);
    originalDate.setDay(1);
    originalDate.setYear(2005);

    cout << "\nNew date:" << endl;
    originalDate.displayDate();

    return 0;
}