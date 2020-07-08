#ifndef PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP
#define PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP


#include <gtest/gtest.h>
#include "src/Employee/SalesReceipt.hpp"
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
    HourlyEmployeeCorrectnessTester(double hRate, TimeCard tc) :
        HourlyEmployeeCorrectnessTester(hRate)
    { timeCard = std::make_optional<TimeCard>(tc); }
private:
    void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck);
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;

    double hRate;
    std::optional<TimeCard> timeCard;
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
    CommissionedEmployeeCorrectnessTester(double cSalary, double cRate, SalesReceipt sr) :
        CommissionedEmployeeCorrectnessTester(cSalary, cRate)
    { salesReceipt = std::make_optional<SalesReceipt>(sr); }
private:
    void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck);
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;
    double cSalary, cRate;
    std::optional<SalesReceipt> salesReceipt;
};

#endif //PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP
