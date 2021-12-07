// 예제 (파생 클래스의 포인터가 기본 클래스의 객체를 가리킬 때)
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

int main()
{
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "222-22-2222", 10000, .06);
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

    // aim derived-class pointer at base-class object
    // Error: a CommissionEmployee is not a BasePlusCommissionEmployee
    basePlusCommissionEmployeePtr = &commissionEmployee;

    return 0;
}