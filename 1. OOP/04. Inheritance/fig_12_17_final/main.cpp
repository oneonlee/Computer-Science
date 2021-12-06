#include <iostream>
#include <iomanip>

using namespace std;

#include "BasePlusCommissionEmployee.h"

int main()
{
    // instantiate BasePlusCommissionEmployee object
    BasePlusCommissionEmployee
        employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get function: \n"
         << "\nFirst name is " << employee.getFirstName()
         << "\nLast name is " << employee.getLastName()
         << "\nsocial security number is " << employee.getSocialSecurityNumber()
         << "\nGross sales is " << employee.getGrossSales()
         << "\ncommission rate is " << employee.getCommissionRate()
         << "\nBase salary is " << employee.getBaseSalary() << endl;

    employee.setGrossSales(1000);

    // employee.setGrossSales(8000);
    // employee.setCommissionRate(.1);

    cout << "\nUpdated employee information ouput bt print function: \n"
         << endl;
    employee.print();

    cout << "\n\nEmployee's earning: $" << employee.earnings() << endl;

    return 0;
}