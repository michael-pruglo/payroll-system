#ifndef PAYROLL_SYSTEM_PAYROLLDATABASE_HPP
#define PAYROLL_SYSTEM_PAYROLLDATABASE_HPP


#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "Employee.hpp"

class PayrollDatabase
{
public:
    virtual     ~PayrollDatabase() = default;

    void        addEmployee(int id, Employee* employee);
    Employee*   getEmployee(int id) const;
    void        updateEmployee(int id, Employee* newEmployee);
    void        deleteEmployee(int id);
    auto        size() const { return database.size(); }

public:
    class not_found : public std::exception {};
    class add_duplicate : public std::exception {};

private:
    std::unordered_map<int, Employee*> database;
};


#endif //PAYROLL_SYSTEM_PAYROLLDATABASE_HPP
