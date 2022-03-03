#include <iostream>
#include "myString.h"
using namespace std;

// default constructor for class myString (default size 40)
myString::myString(int stringLength)
{
    length = (stringLength > 0 ? stringLength : 40); // validate stringLength
    str = new char[length];
    //cout << "!!디폴트 생성자" << this->str << endl;
} // end myString default constructor

// copy structor for class myString
// must receive a reference to prevent infinite recursion
myString::myString(const myString &stringToCopy)
{
    setString(stringToCopy.length, stringToCopy.str);

    // cout << "!!!!복사생성자" << this->str << endl;
} // end myString copy structor

// destructor for class myString
myString::~myString()
{
    //out << "Im gonna delete" << endl;
    delete[] str;
    //cout << *this;
} // end destructor

//set function (이미 생성된 객체의 string을 수정하여 대입하는 함수)
void myString::setString(int length, char *ptr)
{

    this->length = length;

    this->str = new char[length];

    for (int i = 0; i < length; i++)
    {
        this->str[i] = ptr[i];
    }

    // cout << "setting length to " << length << endl;
    // cout << "str is " << this->str << endl;
}

//concatenate
myString myString::operator+(myString &operand)
{
    int tmpLen = this->length + operand.length - 1;
    // cout << "TMPLEN" << tmpLen;
    myString tmp(tmpLen);

    for (int i = 0; i < this->length - 1; i++)
    {
        tmp.str[i] = this->str[i];
    }
    for (int j = 0; j < operand.length; j++)
    {
        tmp.str[j + this->length - 1] = operand.str[j];
    }

    return tmp;
}

void myString::operator=(myString &operand)
{
    this->length = operand.length;
    this->str = new char[this->length];
    this->setString(this->length, operand.str);
}

bool myString::operator==(myString &operand)
{
    for (int i = 0; i < min(length, operand.length); i++)
    {
        if (str[i] != operand.str[i])
            return false;
    }

    if (length == operand.length)
        return true;

    return false;
}
bool myString::operator!=(myString &operand)
{
    for (int i = 0; i < min(length, operand.length); i++)
    {
        if (str[i] != operand.str[i])
            return true;
    }

    if (length == operand.length)
        return false;

    return true;
}

char myString::operator[](int idx)
{
    if (idx > this->length)
    {
        cerr << "Error index ; " << idx << " out of range";
        // exit(1);
        return 0; // exit
    }

    else
        return this->str[idx];
}

void myString::printString()
{
    cout << "This string's length : " << this->length << endl;
    cout << "This string is : " << this->str << endl;
}

// overloaded subscript operator for class myString
ostream &operator<<(ostream &output, const myString &s)
{
    output << "myString : ";

    for (int i = 0; i < s.length; i++)
    {
        output << s.str[i];
    }

    output << "\n";
    return output;
}

istream &operator>>(istream &input, myString &s)
{
    char *tmp = new char[s.length];
    input >> tmp;

    // calculating length of tmp
    int cnt = 0;
    while (tmp[cnt] != '\0')
    {
        ++cnt;
    }

    s.length = cnt + 1; // redefine length
    s.str = new char[s.length];
    s.setString(s.length, tmp); // copy

    return input;
}
