#include <iostream>
using std::cout;    //출력 담당
using std::cin;     //입력 담당
using std::endl;    //new line "\n"


//테스트
#include <string>
using std::string;
using std::getline;

class GradeBook {
public:
    void displayMessage(string courseName) {
        cout << "Welcome to the grade book for " << courseName << "!" << endl;
    }
};

int main() {
    string nameOfCourse;
    GradeBook myGradeBook;

    cout << "Please enter the course name : " << endl;
    getline(cin, nameOfCourse);
    cout << endl;

    myGradeBook.displayMessage(nameOfCourse);
    return 0;
}