#include "EmployeeCorrectnessTester.hpp"


void EmployeeCorrectnessTester::invoke(int idToCheck, std::string nameToCheck)
{
    testDatabaseContains(idToCheck);
    testEmployee(database->getEmployee(idToCheck), nameToCheck);
}

void EmployeeCorrectnessTester::testDatabaseContains(int id)
{
    ASSERT_NO_THROW(database->getEmployee(id));
}

void EmployeeCorrectnessTester::testName(std::shared_ptr<Employee> givenE, std::string nameToCheck) const
{
    ASSERT_EQ(givenE->getName(), nameToCheck);
}

template<typename ExpectedT, typename ActualT>
void EmployeeCorrectnessTester::testIsCorrectDerivedType(ActualT ptrToBase) const
{
    auto ptrToDerived = std::dynamic_pointer_cast<ExpectedT>(ptrToBase);
    ASSERT_NE(ptrToDerived, decltype(ptrToDerived)());
}

void HourlyEmployeeCorrectnessTester::testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck)
{
    testName(givenE, nameToCheck);
    testClassification(givenE->getPaymentClassification());
    testIsCorrectDerivedType<WeeklySchedule>(givenE->getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE->getPaymentMethod());
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

void SalariedEmployeeCorrectnessTester::testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck)
{
    testName(givenE, nameToCheck);
    testClassification(givenE->getPaymentClassification());
    testIsCorrectDerivedType<MonthlySchedule>(givenE->getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE->getPaymentMethod());
}

void SalariedEmployeeCorrectnessTester::testClassification(std::shared_ptr<PaymentClassification> pc) const
{
    testIsCorrectDerivedType<SalariedClassification>(pc);
    auto classification = std::dynamic_pointer_cast<SalariedClassification>(pc);
    ASSERT_DOUBLE_EQ(classification->getSalary(), sSalary);
}

void CommissionedEmployeeCorrectnessTester::testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck)
{
    testName(givenE, nameToCheck);
    testClassification(givenE->getPaymentClassification());
    testIsCorrectDerivedType<BiweeklySchedule>(givenE->getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE->getPaymentMethod());
}

void CommissionedEmployeeCorrectnessTester::testClassification(std::shared_ptr<PaymentClassification> pc) const
{
    testIsCorrectDerivedType<CommissionedClassification>(pc);
    auto classification = std::dynamic_pointer_cast<CommissionedClassification>(pc);
    ASSERT_DOUBLE_EQ(classification->getSalary(), cSalary);
    ASSERT_DOUBLE_EQ(classification->getCommissionRate(), cRate);
}
