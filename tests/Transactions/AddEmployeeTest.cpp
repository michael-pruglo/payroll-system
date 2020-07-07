#include <gtest/gtest.h>
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/AddEmployeeTransaction.cpp"
#include "tests/Transactions/utility/EmployeeCorrectnessTester.hpp"
#include "tests/Transactions/utility/TestUsingDatabase.hpp"

class AddEmployeeTest : public TestUsingDatabase
{
protected:

    int         hId = 1,                sId = 2,                cId = 3;
    std::string hName = "Howard",       sName = "Sally",        cName = "Camilla";
    std::string hAddress = "Hour st.",  sAddress = "Sal st.",   cAddress = "Comi st.";
    double      hRate = 17.7,           sSalary = 1000.33,      cSalary = 2000.88, cRate = 0.05;
};

TEST_F(AddEmployeeTest, HourlyEmployee)
{
    AddHourlyEmployee at(hId, hName, hAddress, hRate);
    ASSERT_NO_THROW(at.execute());
    ASSERT_EQ(database->size(), 1);
    HourlyEmployeeCorrectnessTester(hRate).invoke(hId, hName);
}

TEST_F(AddEmployeeTest, SalariedEmployee)
{
    AddSalariedEmployee at(sId, sName, sAddress, sSalary);
    ASSERT_NO_THROW(at.execute());
    ASSERT_EQ(database->size(), 1);
    SalariedEmployeeCorrectnessTester(sSalary).invoke(sId, sName);
}

TEST_F(AddEmployeeTest, CommissionedEmployee)
{
    AddCommissionedEmployee at(cId, cName, cAddress, cSalary, cRate);
    ASSERT_NO_THROW(at.execute());
    ASSERT_EQ(database->size(), 1);
    CommissionedEmployeeCorrectnessTester(cSalary, cRate).invoke(cId, cName);
}