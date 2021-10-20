#pragma once
class Time
{
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