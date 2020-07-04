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
    ASSERT_NO_THROW(transaction->execute());
    ASSERT_NO_THROW({
        auto givenE = database->getEmployee(idToCheck);
        ASSERT_EQ(givenE->getName(), nameToCheck);
        Employee::PaymentClassification* pc = givenE->getPaymentClassification();
        ClassificationT* sc = dynamic_cast<ClassificationT*> (pc);
        ASSERT_TRUE(sc != nullptr);
    });
}

TEST_F(AddEmployeeTest, AddHourlyEmployee)
{
    AddHourlyEmployee ht(hId, hName, hAddress, hRate);
    addAndRetrieveTest<Employee::HourlyClassification>(&ht, hId, hName);
}

TEST_F(AddEmployeeTest, CanAddSalariedEmployee)
{
    AddSalariedEmployee st(sId, sName, sAddress, sSalary);
    addAndRetrieveTest<Employee::SalariedClassification>(&st, sId, sName);
}

TEST_F(AddEmployeeTest, CanAddCommissionedEmployee)
{
    AddCommissionedEmployee ct(cId, cName, cAddress, cSalary, cRate);
    addAndRetrieveTest<Employee::CommissionedClassification>(&ct, cId, cName);
}