#include <algorithm>
#include "EmployeeCorrectnessTester.hpp"
#include "src/Employee/PaymentClassification.cpp"


void EmployeeCorrectnessTester::addServiceCharge(ServiceCharge serviceCharge)
{
    serviceCharges.push_back(serviceCharge);
}

void EmployeeCorrectnessTester::invoke(int idToCheck, std::string nameToCheck, std::string addressToCheck)
{
    testName(givenE.getName(), nameToCheck);
    testAddress(givenE.getAddress(), addressToCheck);
    testClassification(givenE.getPaymentClassification());
    testEmployeeType();
    testServiceChargeList(givenE.getAffiliation()->getServiceCharges());
}

void EmployeeCorrectnessTester::testName(std::string givenName, std::string nameToCheck) const
{
    ASSERT_EQ(givenName, nameToCheck);
}
void EmployeeCorrectnessTester::testAddress(std::string givenAddress, std::string addressToCheck) const
{
    ASSERT_EQ(givenAddress, addressToCheck);
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

void HourlyEmployeeCorrectnessTester::testEmployeeType()
{
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

void SalariedEmployeeCorrectnessTester::testEmployeeType()
{
    testIsCorrectDerivedType<MonthlySchedule>(givenE.getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE.getPaymentMethod());
}

void SalariedEmployeeCorrectnessTester::testClassification(std::shared_ptr<PaymentClassification> pc) const
{
    testIsCorrectDerivedType<SalariedClassification>(pc);
    auto classification = std::dynamic_pointer_cast<SalariedClassification>(pc);
    ASSERT_DOUBLE_EQ(classification->getSalary(), sSalary);
}

void CommissionedEmployeeCorrectnessTester::testEmployeeType()
{
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
