#include <iostream>
#include <iomanip>

#include "BasePlusCommissionEmployee.h"
#include "CommissionEmployee.h"

using namespace std;

int main()
{
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "222-22-2222", 10000, 0.6);

    CommissionEmployee *commissionEmployeePtr = 0;

    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);

    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

    cout << fixed << setprecision(2);

    cout << "Invoking print function on base-class and derived-class "
         << "\nobjects with static binding\n\n";
    commissionEmployee.print();
    cout << "\n\n";
    basePlusCommissionEmployee.print();

    cout << "\n\n\nInvoking print function on base-class and "
         << "derived-class \nobjects with dynamic binding:";

    commissionEmployeePtr = &commissionEmployee;
    cout << "\n\nCalling virtual function print with base-class pointer"
         << "\n to base-class object invokes base-class "
         << "print function:\n\n";
    commissionEmployeePtr->print();

    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "\n\nCalling virtual function print with derived-class "
         << "pointer\nto derived-class object invokes derived-class "
         << "print function:\n\n";
    basePlusCommissionEmployeePtr->print();

    commissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "\n\nCalling virtual function print with base-class pointer "
         << "\nto derived-class object invokes derived-class "
         << "print function:\n\n";

    commissionEmployeePtr->print();
    cout << endl;
    return 0;
}