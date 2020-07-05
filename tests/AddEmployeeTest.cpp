#include <gtest/gtest.h>
#include "src/AddEmployeeTransaction.hpp"
#include "src/AddEmployeeTransaction.cpp"

int         hId = 1,                sId = 2,                cId = 3;
std::string hName = "Howard",       sName = "Sally",        cName = "Camilla";
std::string hAddress = "Hour st.",  sAddress = "Sal st.",   cAddress = "Comi st.";
double      hRate = 17.7,           sSalary = 1000.33,      cSalary = 2000.88, cRate = 0.05;

class AddEmployeeTest : public ::testing::Test
{
protected:

    void TearDown() override
    {
        database->clear();
        ASSERT_EQ(database->size(), 0);
    }

    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};


template<typename ClassificationT, typename ScheduleT>
class AddAndRetrieveEmployeeTester
{
public:
    AddAndRetrieveEmployeeTester() {}
    void invoke(AddEmployeeTransaction* transaction, int idToCheck, std::string nameToCheck);

private:
    void testDatabaseContains(int id);
    void testEmployee(std::shared_ptr<Employee> givenE, std::string nameToCheck);
    void testName(std::shared_ptr<Employee> givenE, std::string nameToCheck) const;
    void testClassification(std::shared_ptr<Employee> givenE) const;
    template<typename ExpectedT, typename ActualT>
    void testIsCorrectDerivedType(ActualT ptrToBase) const;

private:
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

template<typename ClassificationT, typename ScheduleT>
void
AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::invoke(AddEmployeeTransaction* transaction,
        int idToCheck, std::string nameToCheck)
{
    transaction->execute();

    testDatabaseContains(idToCheck);
    testEmployee(database->getEmployee(idToCheck), nameToCheck);
}

template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testDatabaseContains(int id)
{
    ASSERT_NO_THROW(database->getEmployee(id));
}

template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testEmployee(
        std::shared_ptr<Employee> givenE, std::string nameToCheck)
{
    testName(givenE, nameToCheck);
    testClassification(givenE);
    testIsCorrectDerivedType<ScheduleT>(givenE->getPaymentSchedule());
    testIsCorrectDerivedType<Employee::HoldMethod>(givenE->getPaymentMethod());
}

template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testName(std::shared_ptr<Employee> givenE, std::string nameToCheck) const
{
    ASSERT_EQ(givenE->getName(), nameToCheck);
}
template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testClassification(std::shared_ptr<Employee> givenE) const
{
    auto pc = givenE->getPaymentClassification();
    testIsCorrectDerivedType<ClassificationT>(pc);

    auto classification = std::dynamic_pointer_cast<ClassificationT>(pc);
    if      constexpr (std::is_same_v<ClassificationT, Employee::HourlyClassification>)
        ASSERT_DOUBLE_EQ(classification->getHourlyRate(), hRate);
    else if constexpr (std::is_same_v<ClassificationT, Employee::SalariedClassification>)
        ASSERT_DOUBLE_EQ(classification->getSalary(), sSalary);
    else if constexpr (std::is_same_v<ClassificationT, Employee::CommissionedClassification>)
    {
        ASSERT_DOUBLE_EQ(classification->getSalary(), cSalary);
        ASSERT_DOUBLE_EQ(classification->getCommissionRate(), cRate);
    }
    else
        FAIL()<<"Unknown Payment Classification subclass";
}

template<typename ClassificationT, typename ScheduleT>
template<typename ExpectedT, typename ActualT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testIsCorrectDerivedType(ActualT ptrToBase) const
{
    auto ptrToDerived = std::dynamic_pointer_cast<ExpectedT>(ptrToBase);
    ASSERT_NE(ptrToDerived, decltype(ptrToDerived)());
}


TEST_F(AddEmployeeTest, HourlyEmployee)
{
    AddHourlyEmployee ht(hId, hName, hAddress, hRate);
    AddAndRetrieveEmployeeTester<
            Employee::HourlyClassification,
            Employee::WeeklySchedule
            >().invoke(&ht, hId, hName);
}

TEST_F(AddEmployeeTest, SalariedEmployee)
{
    AddSalariedEmployee st(sId, sName, sAddress, sSalary);
    AddAndRetrieveEmployeeTester<
            Employee::SalariedClassification,
            Employee::MonthlySchedule
            >().invoke(&st, sId, sName);
}

TEST_F(AddEmployeeTest, CommissionedEmployee)
{
    AddCommissionedEmployee ct(cId, cName, cAddress, cSalary, cRate);
    AddAndRetrieveEmployeeTester<
            Employee::CommissionedClassification,
            Employee::BiweeklySchedule
            >().invoke(&ct, cId, cName);
}