#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include <string>
#include "CommissionEmployee.h"

using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee(const string &, const string &, const string &,
                               double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    void print() const;
    double earnings() const;
};

#endif