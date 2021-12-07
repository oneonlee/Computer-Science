#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &, const string &,
                               double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    virtual double earnings() const;
    virtual void print() const;

private:
    double baseSalary;
};

#endif