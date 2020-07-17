#include <tests/EmployeeFactory.hpp>
#include "src/utility/Date.hpp"
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/TimeCardTransaction.hpp"
#include "utility/EmployeeCorrectnessTester.hpp"
#include "utility/TestUsingDatabase.hpp"


class TimeCardTest : public TestUsingDatabase
{
protected:

    void SetUp() override
    {
        AddHourlyEmployee at(_eh.id, _eh.name, _eh.address, _eh.hRate);
        ASSERT_NO_THROW(at.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    EmployeeFactory _eh{20};
};

TEST_F(TimeCardTest, TimeCardUpdates)
{
    assertDatabaseContains(_eh.id);

    TimeCardTransaction tct(_eh.date, _eh.hours, _eh.id);
    ASSERT_NO_THROW(tct.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate, TimeCard(_eh.date, _eh.hours))
        .invoke(_eh.id, _eh.name, _eh.address);
}