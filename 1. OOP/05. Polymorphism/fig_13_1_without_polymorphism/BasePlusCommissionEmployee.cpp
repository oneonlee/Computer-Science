#include "BasePlusCommissionEmployee.h"
#include <iostream>
#include <string>
#include "CommissionEmployee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "base salary: " << baseSalary << endl;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary = salary < 0.0 ? 0 : salary;
}