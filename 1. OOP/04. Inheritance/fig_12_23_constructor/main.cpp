#include <iostream>
#include <iomanip>

using namespace std;

#include "BasePlusCommissionEmployee.h"

int main()
{
    cout << fixed << setprecision(2);

    { // begin new scope
        CommissionEmployee employee1("Bob", "Lewis", "111-11-1111", 1000, .01);

    } // end scope

    cout << endl;
    BasePlusCommissionEmployee employee2("Peter", "Lee", "221-12-2222", 2000, .02, 222);

    cout << endl;
    BasePlusCommissionEmployee employee3("JJang-gu", "Shin", "331-13-3113", 3000, .03, 333);

    cout << endl;
    return 0;
}