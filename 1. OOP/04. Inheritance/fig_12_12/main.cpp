#include <iostream>
#include <iomanip>

using namespace std;

#include "BasePlusCommissionEmployee.h"

int main()
{
    BasePlusCommissionEmployee employee("minseong", "kim", "12181991", 10000, .06, 100000);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get function: \n"
         << "\nFirst name is " << employee.getFirstName()
         << "\nLast name is " << employee.getLastName() << "\nsocial security number is " << employee.getSocialSecurityNumber()
         << "\nGross sales is " << employee.getGrossSales() << "\ncommission rate is " << employee.getCommissionRate()
         << "\nsalary is " << employee.getBaseSalary() << endl;

    employee.print();

    employee.setGrossSales(8000);
    employee.setCommissionRate(.1);

    cout << "\nUpdated employee information output" << endl;
    employee.print();

    cout << "\nemployee's earning: $" << employee.earnings() << endl;
}