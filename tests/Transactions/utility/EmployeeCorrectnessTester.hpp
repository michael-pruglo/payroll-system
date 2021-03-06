#ifndef PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP
#define PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP


#include <gtest/gtest.h>
#include <src/Employee/ServiceCharge.hpp>
#include "src/Employee/SalesReceipt.hpp"
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Database/PayrollDatabase.hpp"

class EmployeeCorrectnessTester
{
public:
    EmployeeCorrectnessTester(Employee employee) : givenE(employee) {}
    virtual ~EmployeeCorrectnessTester() = default;
    void addServiceCharge(ServiceCharge serviceCharge);

    template <typename PaymentMethodType = HoldMethod, typename AffiliationType = NoAffiliation>
    void invoke(int idToCheck, std::string nameToCheck, std::string addressToCheck)
    {
        testName(givenE.getName(), nameToCheck);
        testAddress(givenE.getAddress(), addressToCheck);
        testClassification(givenE.getPaymentClassification());
        testIsCorrectDerivedType<PaymentMethodType>(givenE.getPaymentMethod());
        testIsCorrectDerivedType<AffiliationType>(givenE.getAffiliation());
        testScheduleType();
        testServiceChargeList(givenE.getAffiliation()->getServiceCharges());
    }

protected:
    virtual void testScheduleType() = 0;
    void testName(std::string givenName, std::string nameToCheck) const;
    void testAddress(std::string givenAddress, std::string addressToCheck) const;
    virtual void testClassification(std::shared_ptr<PaymentClassification> pc) const = 0;
    template<typename ExpectedT, typename ActualT>
    void testIsCorrectDerivedType(ActualT ptrToBase) const
    {
        auto ptrToDerived = std::dynamic_pointer_cast<ExpectedT>(ptrToBase);
        ASSERT_NE(ptrToDerived, decltype(ptrToDerived)());
    }

protected:
    Employee givenE;
private:
    std::vector<ServiceCharge> serviceCharges;
    void testServiceChargeList(std::vector<ServiceCharge> givenServiceCharges);
};

class HourlyEmployeeCorrectnessTester : public EmployeeCorrectnessTester
{
public:
    HourlyEmployeeCorrectnessTester(Employee e, double hRate) :
        EmployeeCorrectnessTester(e),
        hRate(hRate)
    {}
    HourlyEmployeeCorrectnessTester(Employee e, double hRate, TimeCard tc) :
        HourlyEmployeeCorrectnessTester(e, hRate)
    { timeCard = std::make_optional<TimeCard>(tc); }

private:
    void testScheduleType() override;
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;

    double hRate;
    std::optional<TimeCard> timeCard;
};

class SalariedEmployeeCorrectnessTester : public EmployeeCorrectnessTester
{
public:
    SalariedEmployeeCorrectnessTester(Employee e, double sSalary) :
        EmployeeCorrectnessTester(e),
        sSalary(sSalary)
    {}
private:
    void testScheduleType() override;
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;
    double sSalary;
};

class CommissionedEmployeeCorrectnessTester : public EmployeeCorrectnessTester
{
public:
    CommissionedEmployeeCorrectnessTester(Employee e, double cSalary, double cRate) :
        EmployeeCorrectnessTester(e),
        cSalary(cSalary),
        cRate(cRate)
    {}
    CommissionedEmployeeCorrectnessTester(Employee e, double cSalary, double cRate, SalesReceipt sr) :
        CommissionedEmployeeCorrectnessTester(e, cSalary, cRate)
    { salesReceipt = std::make_optional<SalesReceipt>(sr); }
private:
    void testScheduleType() override;
    void testClassification(std::shared_ptr<PaymentClassification> pc) const override;
    double cSalary, cRate;
    std::optional<SalesReceipt> salesReceipt;
};

#endif //PAYROLL_SYSTEM_EMPLOYEECORRECTNESSTESTER_HPP
