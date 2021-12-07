#include "CommissionEmployee.h"
#include <iostream>
#include <string>

using namespace std;

CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate)
{
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

double CommissionEmployee::earnings() const
{
    return commissionRate * grossSales;
}

double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

string CommissionEmployee::getFirstName() const
{
    return firstName;
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

string CommissionEmployee::getLastName() const
{
    return lastName;
}

string CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void CommissionEmployee::print() const
{
    cout << "commission employee: "
         << getFirstName() << ' ' << getLastName() << endl
         << "social security number: " << getSocialSecurityNumber() << endl
         << "gross sales: " << getGrossSales() << endl
         << "commission rate: " << getCommissionRate() << endl;
}

void CommissionEmployee::setCommissionRate(double rate)
{
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0;
}

void CommissionEmployee::setFirstName(const string &first)
{
    firstName = first;
}

void CommissionEmployee::setGrossSales(double sales)
{
    grossSales = sales < 0.0 ? 0 : sales;
}

void CommissionEmployee::setLastName(const string &last)
{
    lastName = last;
}

void CommissionEmployee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}