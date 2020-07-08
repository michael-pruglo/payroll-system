#include <gtest/gtest.h>
#include "src/utility/Date.hpp"
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/SalesReceiptTransaction.hpp"
#include "utility/EmployeeCorrectnessTester.hpp"
#include "utility/TestUsingDatabase.hpp"


class SalesReceiptTest : public TestUsingDatabase
{
protected:

    void SetUp() override
    {
        AddCommissionedEmployee at(id, name, address, cSalary, cRate);
        ASSERT_NO_THROW(at.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    void assertDatabaseContains(int id) { ASSERT_NO_THROW(database->getEmployee(id)); }

    int id = 11;
    std::string name = "Nick", address = "Nicaragua";
    Date date = Date(2020, 7, 7);
    double amount = 17.0, cSalary = 600.0, cRate = 33.0;
};

TEST_F(SalesReceiptTest, SalesReceiptUpdates)
{
    assertDatabaseContains(id);

    SalesReceiptTransaction srt(date, amount, id);
    ASSERT_NO_THROW(srt.execute());

    CommissionedEmployeeCorrectnessTester(cSalary, cRate, SalesReceipt(date, amount)).invoke(id, name);
}