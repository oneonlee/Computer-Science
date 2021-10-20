#include <iostream>
using std::cout;
using std::endl;

#include "GradeBook.h"

GradeBook::GradeBook(string name) {//사용자 정의 생성자
    setCourseName(name); //왜 set함수를 통해 데이터 변수를 초기화?
}

void GradeBook::setCourseName(string name) {
    courseName = name;
}

string GradeBook::getCourseName() {
    return courseName;
}

void GradeBook::displayMessage() {
    cout << "Welcome to the grade book for\n" << getCourseName()
        << "!" << endl;
}