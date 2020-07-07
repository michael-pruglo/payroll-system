#ifndef PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP
#define PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP


#include <gtest/gtest.h>
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Database/PayrollDatabase.hpp"

class EmployeeCorrectnessTester
{
public:
    virtual ~EmployeeCorrectnessTester() = default;
    void invoke(int idToCheck, std::string nameToCheck);

protected:
    void testDatabaseContains(int id);
    virtual void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck) = 0;
    void testName(std::shared_ptr<Employee> givenE, std::string nameToCheck) const;
    virtual void testClassification(std::shared_ptr<PaymentClassification> pc) const = 0;
    template<typename ExpectedT, typename ActualT>
    void testIsCorrectDerivedType(ActualT ptrToBase) const;

private:
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

class HourlyEmployeeCorrectnessTester : public EmployeeCorrectnessTester
{
public:
    HourlyEmployeeCorrectnessTester(double hRate) : hRate(hRate) {}
private:
    void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck);
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;

    double hRate;
};

class SalariedEmployeeCorrectnessTester : public EmployeeCorrectnessTester
{
public:
    SalariedEmployeeCorrectnessTester(double sSalary) : sSalary(sSalary) {}
private:
    void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck);
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;
    double sSalary;
};

class CommissionedEmployeeCorrectnessTester : public EmployeeCorrectnessTester
{
public:
    CommissionedEmployeeCorrectnessTester(double cSalary, double cRate) :
        cSalary(cSalary),
        cRate(cRate)
    {}
private:
    void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck);
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;
    double cSalary, cRate;
};

#endif //PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP
