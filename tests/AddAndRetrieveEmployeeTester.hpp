#ifndef PAYROLL_SYSTEM_ADDANDRETRIEVEEMPLOYEETESTER_HPP
#define PAYROLL_SYSTEM_ADDANDRETRIEVEEMPLOYEETESTER_HPP


#include <gtest/gtest.h>
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/PayrollDatabase.hpp"

template<typename ClassificationT, typename ScheduleT>
class AddAndRetrieveEmployeeTester
{
public:
    AddAndRetrieveEmployeeTester(double hRate, double sSalary, double cSalary, double cRate);
    void invoke(AddEmployeeTransaction* transaction, int idToCheck, std::string nameToCheck);

private:
    void testDatabaseContains(int id);
    void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck);
    void testName(std::shared_ptr<Employee> givenE, std::string nameToCheck) const;
    void testClassification(std::shared_ptr<Employee> givenE) const;
    template<typename ExpectedT, typename ActualT>
    void testIsCorrectDerivedType(ActualT ptrToBase) const;

private:
    double hRate, sSalary, cSalary, cRate;
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

template<typename ClassificationT, typename ScheduleT>
AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::
    AddAndRetrieveEmployeeTester(double hRate, double sSalary, double cSalary, double cRate) :
        hRate(hRate),
        sSalary(sSalary),
        cSalary(cSalary),
        cRate(cRate)
{
}

template<typename ClassificationT, typename ScheduleT>
void
AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::
        invoke(AddEmployeeTransaction* transaction, int idToCheck, std::string nameToCheck)
{
    transaction->execute();

    testDatabaseContains(idToCheck);
    testEmployee(database->getEmployee(idToCheck), nameToCheck);
}

template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::
        testDatabaseContains(int id)
{
    ASSERT_NO_THROW(database->getEmployee(id));
}

template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::
        testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck)
{
    testName(givenE, nameToCheck);
    testClassification(givenE);
    testIsCorrectDerivedType<ScheduleT>(givenE->getPaymentSchedule());
    testIsCorrectDerivedType<HoldMethod>(givenE->getPaymentMethod());
}

template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::
        testName(std::shared_ptr<Employee> givenE, std::string nameToCheck) const
{
    ASSERT_EQ(givenE->getName(), nameToCheck);
}
template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::
        testClassification(std::shared_ptr<Employee> givenE) const
{
    auto pc = givenE->getPaymentClassification();
    testIsCorrectDerivedType<ClassificationT>(pc);

    auto classification = std::dynamic_pointer_cast<ClassificationT>(pc);
    if      constexpr (std::is_same_v<ClassificationT, HourlyClassification>)
        ASSERT_DOUBLE_EQ(classification->getHourlyRate(), hRate);
    else if constexpr (std::is_same_v<ClassificationT, SalariedClassification>)
        ASSERT_DOUBLE_EQ(classification->getSalary(), sSalary);
    else if constexpr (std::is_same_v<ClassificationT, CommissionedClassification>)
    {
        ASSERT_DOUBLE_EQ(classification->getSalary(), cSalary);
        ASSERT_DOUBLE_EQ(classification->getCommissionRate(), cRate);
    }
    else
        FAIL()<<"Unknown Payment Classification subclass";
}

template<typename ClassificationT, typename ScheduleT>
template<typename ExpectedT, typename ActualT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::
        testIsCorrectDerivedType(ActualT ptrToBase) const
{
    auto ptrToDerived = std::dynamic_pointer_cast<ExpectedT>(ptrToBase);
    ASSERT_NE(ptrToDerived, decltype(ptrToDerived)());
}



#endif //PAYROLL_SYSTEM_ADDANDRETRIEVEEMPLOYEETESTER_HPP
