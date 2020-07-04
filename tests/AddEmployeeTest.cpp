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
    void testReturnedEmployee(int idToCheck, std::string nameToCheck);
    void testClassificationType() const;
    void testScheduleType() const;
    void testMethodType() const;

private:
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
    std::shared_ptr<Employee> givenE;
};

template<typename ClassificationT, typename ScheduleT>
void
AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::invoke(AddEmployeeTransaction* transaction, int idToCheck,
                                                                 std::string nameToCheck)
{
    transaction->execute();
    testReturnedEmployee(idToCheck, nameToCheck);
    testClassificationType();
    testScheduleType();
    testMethodType();
}

template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testReturnedEmployee(int idToCheck, std::string nameToCheck)
{
    givenE = database->getEmployee(idToCheck);
    ASSERT_EQ(givenE->getName(), nameToCheck);
}
template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testClassificationType() const
{
    auto pc = givenE->getPaymentClassification();
    auto classification = std::dynamic_pointer_cast<ClassificationT>(pc);
    ASSERT_NE(classification, decltype(classification)());

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
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testScheduleType() const
{
    auto ps = givenE->getPaymentSchedule();
    auto schedule = std::dynamic_pointer_cast<ScheduleT>(ps);
    ASSERT_NE(schedule, decltype(schedule)());
}
template<typename ClassificationT, typename ScheduleT>
void AddAndRetrieveEmployeeTester<ClassificationT, ScheduleT>::testMethodType() const
{
    auto pm = givenE->getPaymentMethod();
    auto method = std::dynamic_pointer_cast<Employee::HoldMethod>(pm);
    ASSERT_NE(method, decltype(method)());
}



TEST_F(AddEmployeeTest, HourlyEmployee)
{
    AddHourlyEmployee ht(hId, hName, hAddress, hRate);
    ASSERT_NO_THROW((AddAndRetrieveEmployeeTester<
            Employee::HourlyClassification,
            Employee::WeeklySchedule
            >().invoke(&ht, hId, hName)));
}

TEST_F(AddEmployeeTest, SalariedEmployee)
{
    AddSalariedEmployee st(sId, sName, sAddress, sSalary);
    ASSERT_NO_THROW((AddAndRetrieveEmployeeTester<
            Employee::SalariedClassification,
            Employee::MonthlySchedule
            >().invoke(&st, sId, sName)));
}

TEST_F(AddEmployeeTest, CommissionedEmployee)
{
    AddCommissionedEmployee ct(cId, cName, cAddress, cSalary, cRate);
    ASSERT_NO_THROW((AddAndRetrieveEmployeeTester<
            Employee::CommissionedClassification,
            Employee::BiweeklySchedule
            >().invoke(&ct, cId, cName)));
}