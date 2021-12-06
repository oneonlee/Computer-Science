#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "CommissionEmployee.h"

int main()
{
    CommissionEmployee employee(
        "Sue", "Jones", "222-22-2222", 10000, .06);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get functions: \n"
         << "\nFirst name is " << employee.getFirstName()
         << "\nLast name is " << employee.getLastName()
         << "\nSocial security number is " << employee.getSocialSecurityNumber()
         << "\nGross sales is " << employee.getGrossSales()
         << "\nCommission rate is " << employee.getCommissionRate() << endl;

    employee.setGrossSales(8000);
    employee.setCommissionRate(.1);

    cout << "\nUpdate employee information output: " << endl;
    employee.print();

    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;

    return 0;
}