#ifndef PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP
#define PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP

#include <string>
#include <memory>
#include "Transaction.hpp"
#include "Employee.hpp"

class AddEmployeeTransaction : public Transaction
{
public:
                 AddEmployeeTransaction(int id, std::string name, std::string address);
    virtual      ~AddEmployeeTransaction() = default;

    virtual void execute() override;
    virtual std::shared_ptr<Employee::PaymentClassification> getPaymentClassification() const = 0;

private:
    int id;
    std::string name, address;
};

class AddHourlyEmployee : public AddEmployeeTransaction
{
public:
    AddHourlyEmployee(int id, std::string name, std::string address, double hourlyRate);
    virtual ~AddHourlyEmployee() = default;
    virtual std::shared_ptr<Employee::PaymentClassification> getPaymentClassification() const override
    {
        return std::make_shared<Employee::HourlyClassification>(hourlyRate);
    }

private:
    double hourlyRate;
};

class AddSalariedEmployee : public AddEmployeeTransaction
{
public:
    AddSalariedEmployee(int id, std::string name, std::string address, double salary);
    virtual ~AddSalariedEmployee() = default;
    virtual std::shared_ptr<Employee::PaymentClassification> getPaymentClassification() const override
    {
        return std::make_shared<Employee::SalariedClassification>(salary);
    }

private:
    double salary;
};

class AddCommissionedEmployee : public AddEmployeeTransaction
{
public:
    AddCommissionedEmployee(int id, std::string name, std::string address, double salary, double commissionRate);
    virtual ~AddCommissionedEmployee() = default;
    virtual std::shared_ptr<Employee::PaymentClassification> getPaymentClassification() const override
    {
        return std::make_shared<Employee::CommissionedClassification>(salary, comissionRate);
    }

private:
    double salary;
    double comissionRate;
};



#endif //PAYROLL_SYSTEM_ADDEMPLOYEETRANSACTION_HPP
