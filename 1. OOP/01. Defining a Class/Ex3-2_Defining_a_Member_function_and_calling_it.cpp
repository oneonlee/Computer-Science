#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class GradeBook {
public:
    //function overloading
    void displayMessage() {
        cout << "Welcome to the GradeBook" << endl;
    }
    void displayMessage(string str) {
        cout << str<< endl;
    }
};


int main() {
    GradeBook myGradeBook;
    myGradeBook.displayMessage();
    myGradeBook.displayMessage("Welcome");
    myGradeBook.displayMessage("to");
    myGradeBook.displayMessage("the");
    myGradeBook.displayMessage("GradeBook");
    return 0;
}