#pragma once

#include <iostream>
using namespace std;

class myString
{
    friend ostream &operator<<(ostream &output, const myString &);
    friend istream &operator>>(istream &input, myString &);

private:
    char *str;
    int length;

public:
    myString(int);              // default constructor
    myString(const myString &); // copy constructor
    ~myString();                // destructor

    // set function
    void setString(int, char *); // 이미 생성된 객체의 string을 수정하여 대입하는 함수

    // concatenate
    myString operator+(myString &);

    // copy
    void operator=(myString &);

    // comparison
    bool operator==(myString &);
    bool operator!=(myString &operand);

    // index-based approaching
    char operator[](int);
    void printString();
};
