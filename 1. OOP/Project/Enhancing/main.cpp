#include <iostream>
using std::cout;
using std::endl;

#include "enhancing.h"

int main()
{
    Time t(23, 58); // hour and minutes specified; second defaulted

    int year = 2021;
    int month = 10;
    int day = 17;

    for (int i = 0; i < 200; i++)
    {
        if (t.tick() == true)
        {
            day += 1;
        }
        cout << year << "-" << month << "-" << day << " ";
        t.printStandard(); // 12:25:42 PM
    }
}