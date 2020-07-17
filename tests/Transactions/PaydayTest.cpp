#include <gtest/gtest.h>
#include <src/Transactions/AddEmployeeTransaction.hpp>
#include <tests/EmployeeFactory.hpp>
#include "utility/TestUsingDatabase.hpp"

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

}