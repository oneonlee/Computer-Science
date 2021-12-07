#include <iostream>
using std::cout;

#include "BasePlusCommissionEmployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
    // double tempCommissionRate = getCommissionRate();
    // double tempGrossSales = getGrossSales();
    // return baseSalary + (tempCommissionRate * tempGrossSales);
    return baseSalary + (getCommissionRate() * getGrossSales());
}

void BasePlusCommissionEmployee::print() const
{

    cout << "base-salaried commission emplyee: " << getFirstName() << ' '
         << getLastName() << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate()
         << "\nbase salary: " << baseSalary;
}