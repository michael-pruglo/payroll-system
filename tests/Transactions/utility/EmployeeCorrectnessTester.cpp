#include <algorithm>
#include "EmployeeCorrectnessTester.hpp"
#include "src/Employee/PaymentClassification.cpp"


void EmployeeCorrectnessTester::addServiceCharge(ServiceCharge serviceCharge)
{
    serviceCharges.push_back(serviceCharge);
}

void EmployeeCorrectnessTester::invoke(int idToCheck, std::string nameToCheck)
{
    testEmployee(nameToCheck);
    testServiceChargeList(givenE.getAffiliation()->getServiceCharges());
}

void EmployeeCorrectnessTester::testName(std::string givenName, std::string nameToCheck) const
{
    ASSERT_EQ(givenName, nameToCheck);
}

template<typename ExpectedT, typename ActualT>
void EmployeeCorrectnessTester::testIsCorrectDerivedType(ActualT ptrToBase) const
{
    auto ptrToDerived = std::dynamic_pointer_cast<ExpectedT>(ptrToBase);
    ASSERT_NE(ptrToDerived, decltype(ptrToDerived)());
}

void EmployeeCorrectnessTester::testServiceChargeList(std::vector<ServiceCharge> givenServiceCharges)
{
    std::sort(givenServiceCharges.begin(), givenServiceCharges.end());
    std::sort(this->serviceCharges.begin(), this->serviceCharges.end());
    ASSERT_TRUE(std::equal(givenServiceCharges.begin(), givenServiceCharges.end(), this->serviceCharges.begin()));
}

void HourlyEmployeeCorrectnessTester::testEmployee(std::string nameToCheck)
{
    testName(givenE.getName(), nameToCheck);
    testClassification(givenE.getPaymentClassification());
    testIsCorrectDerivedType<WeeklySchedule>(givenE.getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE.getPaymentMethod());
}

void HourlyEmployeeCorrectnessTester::testClassification(std::shared_ptr<PaymentClassification> pc) const
{
    testIsCorrectDerivedType<HourlyClassification>(pc);
    auto classification = std::dynamic_pointer_cast<HourlyClassification>(pc);
    ASSERT_DOUBLE_EQ(classification->getHourlyRate(), hRate);
    if (timeCard)
    {
        auto tc = classification->getTimeCard(timeCard->getDate());
        ASSERT_EQ(tc.getHours(), timeCard->getHours());
    }
}

void SalariedEmployeeCorrectnessTester::testEmployee(std::string nameToCheck)
{
    testName(givenE.getName(), nameToCheck);
    testClassification(givenE.getPaymentClassification());
    testIsCorrectDerivedType<MonthlySchedule>(givenE.getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE.getPaymentMethod());
}

void SalariedEmployeeCorrectnessTester::testClassification(std::shared_ptr<PaymentClassification> pc) const
{
    testIsCorrectDerivedType<SalariedClassification>(pc);
    auto classification = std::dynamic_pointer_cast<SalariedClassification>(pc);
    ASSERT_DOUBLE_EQ(classification->getSalary(), sSalary);
}

void CommissionedEmployeeCorrectnessTester::testEmployee(std::string nameToCheck)
{
    testName(givenE.getName(), nameToCheck);
    testClassification(givenE.getPaymentClassification());
    testIsCorrectDerivedType<BiweeklySchedule>(givenE.getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE.getPaymentMethod());
}

void CommissionedEmployeeCorrectnessTester::testClassification(std::shared_ptr<PaymentClassification> pc) const
{
    testIsCorrectDerivedType<CommissionedClassification>(pc);
    auto classification = std::dynamic_pointer_cast<CommissionedClassification>(pc);
    ASSERT_DOUBLE_EQ(classification->getSalary(), cSalary);
    ASSERT_DOUBLE_EQ(classification->getCommissionRate(), cRate);
    if (salesReceipt)
    {
        auto sr = classification->getSalesReceipt(salesReceipt->getDate());
        ASSERT_EQ(sr.getAmount(), salesReceipt->getAmount());
    }
}
