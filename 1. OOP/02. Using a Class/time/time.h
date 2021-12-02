#pragma once

#include <iostream>
class Time {
public:
    Time(int = 0, int = 0, int = 0);

    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const;
    void printStandard();
private:
    int hour;
    int minute;
    int second;
};