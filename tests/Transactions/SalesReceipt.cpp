#include <tests/EmployeeFactory.hpp>
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
        AddCommissionedEmployee at(_ec.id, _ec.name, _ec.address, _ec.cSalary, _ec.cRate);
        ASSERT_NO_THROW(at.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    EmployeeFactory _ec{13};
};

TEST_F(SalesReceiptTest, SalesReceiptUpdates)
{
    assertDatabaseContains(_ec.id);

    SalesReceiptTransaction srt(_ec.date, _ec.amount, _ec.id);
    ASSERT_NO_THROW(srt.execute());

    CommissionedEmployeeCorrectnessTester(*database->getEmployee(_ec.id),
        _ec.cSalary, _ec.cRate, SalesReceipt(_ec.date, _ec.amount)).invoke(_ec.id, _ec.name, _ec.address);
}