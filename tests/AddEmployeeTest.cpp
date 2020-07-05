#include <gtest/gtest.h>
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/AddEmployeeTransaction.cpp"
#include "AddAndRetrieveEmployeeTester.hpp"

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
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

TEST_F(AddEmployeeTest, HourlyEmployee)
{
    AddHourlyEmployee ht(hId, hName, hAddress, hRate);
    AddAndRetrieveEmployeeTester<
            HourlyClassification,
            WeeklySchedule
            >(hRate, sSalary, cSalary, cRate)
            .invoke(&ht, hId, hName);
}

TEST_F(AddEmployeeTest, SalariedEmployee)
{
    AddSalariedEmployee st(sId, sName, sAddress, sSalary);
    AddAndRetrieveEmployeeTester<
            SalariedClassification,
            MonthlySchedule
            >(hRate, sSalary, cSalary, cRate)
            .invoke(&st, sId, sName);
}

TEST_F(AddEmployeeTest, CommissionedEmployee)
{
    AddCommissionedEmployee ct(cId, cName, cAddress, cSalary, cRate);
    AddAndRetrieveEmployeeTester<
            CommissionedClassification,
            BiweeklySchedule
            >(hRate, sSalary, cSalary, cRate)
            .invoke(&ct, cId, cName);
}