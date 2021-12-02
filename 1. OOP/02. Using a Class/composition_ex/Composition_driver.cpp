#include <iostream>
using std::cout;
using std::endl;

#include "Employee.h"

int main() {
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Date birth2();

    Employee manager("Bob", "Blue", birth, hire);

    cout << endl;
    manager.print();

    cout << "\n Test Date constructor with invalid values:\n";
    Date lastDayoff(14, 35, 1994);
    cout << endl;
    return 0;
}