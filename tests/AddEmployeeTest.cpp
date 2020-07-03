#include <gtest/gtest.h>
#include "src/AddEmployeeTransaction.hpp"
#include "src/AddEmployeeTransaction.cpp"
#include "src/PayrollDatabase.hpp"
#include "src/Employee.hpp"

class AddEmployeeTest : public ::testing::Test
{
protected:

    PayrollDatabase database;
};

TEST_F(AddEmployeeTest, CanAddHourlyEmployee)
{
    AddHourlyEmployee t(1, "Bob", "BobAddress", 17.7);
    t.execute();
}

TEST_F(AddEmployeeTest, CanAddSalariedEmployee)
{
    AddSalariedEmployee t(2, "Frank", "FrankAddress", 1000.33);
    t.execute();
}

TEST_F(AddEmployeeTest, CanAddComissionedEmployee)
{
    AddComissionedEmployee t(3, "Joe", "JoeAddress", 2000.55, 0.05);
    t.execute();
}