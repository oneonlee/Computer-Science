#include <iostream>
using std::cout;
using std::endl;

#include "GradeBook.h"

int main()
{
    GradeBook gradeBook1("CS101 introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structures in C++");

    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << endl;
    return 0;
}