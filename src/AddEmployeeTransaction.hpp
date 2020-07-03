#ifndef PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP
#define PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP

#include <string>
#include "Transaction.hpp"

class AddEmployeeTransaction : public Transaction
{
public:
                 AddEmployeeTransaction(int id, std::string name, std::string address);
    virtual      ~AddEmployeeTransaction() = default;

    virtual void execute() override;


private:
    int id;
    std::string name, address;
};

class AddHourlyEmployee : public AddEmployeeTransaction
{
public:
    AddHourlyEmployee(int id, std::string name, std::string address, double salary);
    virtual ~AddHourlyEmployee() = default;

private:
    double hourlyRate;
};

class AddSalariedEmployee : public AddEmployeeTransaction
{
public:
    AddSalariedEmployee(int id, std::string name, std::string address, double salary);
    virtual ~AddSalariedEmployee() = default;

private:
    double salary;
};

class AddComissionedEmployee : public AddEmployeeTransaction
{
public:
    AddComissionedEmployee(int id, std::string name, std::string address, double salary, double comissionRate);
    virtual ~AddComissionedEmployee() = default;

private:
    double salary;
    double comissionRate;
};



#endif //PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP
