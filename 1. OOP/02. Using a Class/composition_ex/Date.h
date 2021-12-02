#pragma once

class Date {
public:
    Date(int = 1, int = 1, int = 1900);
    Date(int, int);
    void print()const;
    ~Date();

private:
    int month;
    int day;
    int year;

    int checkDay(int)const;
};


