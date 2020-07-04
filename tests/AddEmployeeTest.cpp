#include <gtest/gtest.h>
#include <src/Employee.hpp>
#include "src/AddEmployeeTransaction.hpp"
#include "src/AddEmployeeTransaction.cpp"
#include "src/PayrollDatabase.hpp"
#include "src/Employee.hpp"

class AddEmployeeTest : public ::testing::Test
{
protected:

    void TearDown() override
    {
        database->clear();
        ASSERT_EQ(database->size(), 0);
    }

    int         hId = 1,                sId = 2,                cId = 3;
    std::string hName = "Howard",       sName = "Sally",        cName = "Camilla";
    std::string hAddress = "Hour st.",  sAddress = "Sal st.",   cAddress = "Comi st.";
    double      hRate = 17.7,           sSalary = 1000.33,      cSalary = 2000.88, cRate = 0.05;
    template<typename ClassificationT>
    void addAndRetrieveTest(AddEmployeeTransaction* transaction,
            int idToCheck, std::string nameToCheck);

    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

template<typename ClassificationT>
void AddEmployeeTest::addAndRetrieveTest(AddEmployeeTransaction* transaction,
        int idToCheck, std::string nameToCheck)
{
    transaction->execute();
    auto givenE = database->getEmployee(idToCheck);
    ASSERT_EQ(givenE->getName(), nameToCheck);

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

TEST_F(AddEmployeeTest, AddHourlyEmployee)
{
    AddHourlyEmployee ht(hId, hName, hAddress, hRate);
    ASSERT_NO_THROW(addAndRetrieveTest<Employee::HourlyClassification>(&ht, hId, hName));
}

TEST_F(AddEmployeeTest, CanAddSalariedEmployee)
{
    AddSalariedEmployee st(sId, sName, sAddress, sSalary);
    ASSERT_NO_THROW(addAndRetrieveTest<Employee::SalariedClassification>(&st, sId, sName));
}

TEST_F(AddEmployeeTest, CanAddCommissionedEmployee)
{
    AddCommissionedEmployee ct(cId, cName, cAddress, cSalary, cRate);
    ASSERT_NO_THROW(addAndRetrieveTest<Employee::CommissionedClassification>(&ct, cId, cName));
}