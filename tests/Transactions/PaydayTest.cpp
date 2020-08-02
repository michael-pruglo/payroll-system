#include <gtest/gtest.h>
#include <src/Transactions/AddEmployeeTransaction.hpp>
#include <tests/EmployeeFactory.hpp>
#include "utility/TestUsingDatabase.hpp"
#include <src/Transactions/PaydayTransaction.hpp>
#include <src/Transactions/PaydayTransaction.cpp>

class PaydayTest : public TestUsingDatabase
{
protected:

    void SetUp() override
    {
        AddSalariedEmployee ase(_es.id, _es.name, _es.address, _es.sSalary);
        ASSERT_NO_THROW(ase.execute());
    }

    EmployeeFactory _es{10};
};

TEST_F(PaydayTest, SingleSalariedEmployee)
{
    Date payDate(2020, 8, 9);
    PaydayTransaction pt(payDate);
    pt.execute();
    auto paycheck = pt.getPaycheck(_es.id);
    ASSERT_EQ(paycheck->getDate(), payDate);
    ASSERT_EQ(paycheck->getGrossPay(), _es.sSalary);
}