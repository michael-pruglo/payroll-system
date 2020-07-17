#ifndef PAYROLL_SYSTEM_EMPLOYEEFACTORY_HPP
#define PAYROLL_SYSTEM_EMPLOYEEFACTORY_HPP

#include <string>
#include <src/utility/Date.hpp>

struct EmployeeFactory
{
    EmployeeFactory(int seed);
    int id;
    std::string name;
    std::string address;
    double hRate;
    double sSalary;
    double cSalary;
    double cRate;
    Date date;
    double amount;
    double hours;

    bool operator==(const EmployeeFactory&) const = default;
};


#endif //PAYROLL_SYSTEM_EMPLOYEEFACTORY_HPP
