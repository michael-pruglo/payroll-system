#ifndef PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP
#define PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP

#include <string>
#include "Transaction.hpp"
#include "Employee.hpp"

class AddEmployeeTransaction : public Transaction
{
public:
                 AddEmployeeTransaction(int id, std::string name, std::string address);
    virtual      ~AddEmployeeTransaction() = default;

    virtual void execute() override;
    virtual Employee::PaymentClassification* getPaymentClassification() const = 0;

private:
    int id;
    std::string name, address;
};

class AddHourlyEmployee : public AddEmployeeTransaction
{
public:
    AddHourlyEmployee(int id, std::string name, std::string address, double hourlyRate);
    virtual ~AddHourlyEmployee() = default;
    virtual Employee::PaymentClassification* getPaymentClassification() const override
    {
        return new Employee::HourlyClassification(); //leaks
    }

private:
    double hourlyRate;
};

class AddSalariedEmployee : public AddEmployeeTransaction
{
public:
    AddSalariedEmployee(int id, std::string name, std::string address, double salary);
    virtual ~AddSalariedEmployee() = default;
    virtual Employee::PaymentClassification* getPaymentClassification() const override
    {
        return new Employee::SalariedClassification(); //leaks
    }

private:
    double salary;
};

class AddCommissionedEmployee : public AddEmployeeTransaction
{
public:
    AddCommissionedEmployee(int id, std::string name, std::string address, double salary, double commissionRate);
    virtual ~AddCommissionedEmployee() = default;
    virtual Employee::PaymentClassification* getPaymentClassification() const override
    {
        return new Employee::CommissionedClassification(); //leaks
    }

private:
    double salary;
    double comissionRate;
};



#endif //PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP
