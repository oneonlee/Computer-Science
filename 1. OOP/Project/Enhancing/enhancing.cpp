#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

#include "enhancing.h"

// Time constructor initializes each data member to zero.
// Ensure all Time objects start in a consistent state.
Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec); // validate and set time
}

void Time::setTime(int h, int m, int s)
{
    setHour(h);   // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private field second
}

void Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0; // validate hour
}

void Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0; // validate minute
}

void Time::setSecond(int s)
{
    second = (s >= 0 && s < 60) ? s : 0; // validate second
}
int Time::getHour() { return hour; }
int Time::getMinute() { return minute; }
int Time::getSecond() { return second; }

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":" << setw(2) << second << endl;
}

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
         << setfill('0') << setw(2) << minute << ":" << setw(2)
         << second << (hour < 12 ? " AM" : " PM") << endl;
}

bool Time::tick()
{
    second += 1;
    if (second % 60 == 0)
    {
        second = 0;
        minute += 1;
        if (minute % 60 == 0)
        {
            minute = 0;
            hour += 1;
            setTime(hour, minute, second);
            return (hour % 12 == 0);
        }
    }

    setTime(hour, minute, second);
    return false;
}