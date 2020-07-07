#include <gtest/gtest.h>
#include "src/utility/Date.hpp"
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/TimeCardTransaction.hpp"
#include "tests/Transactions/utility/EmployeeCorrectnessTester.hpp"
#include "tests/Transactions/utility/TestUsingDatabase.hpp"


class TimeCardTest : public TestUsingDatabase
{
protected:

    void SetUp() override
    {
        AddHourlyEmployee at(id, name, address, hRate);
        ASSERT_NO_THROW(at.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    void assertDatabaseContains(int id) { ASSERT_NO_THROW(database->getEmployee(id)); }

    int id = 10;
    std::string name = "Jack", address = "Jamaica";
    Date date = Date(2020, 06, 11);
    double hours = 8.0, hRate = 10.0;
};

TEST_F(TimeCardTest, TimeCardUpdates)
{
    assertDatabaseContains(id);

    TimeCardTransaction tct(date, hours, id);
    ASSERT_NO_THROW(tct.execute());

    HourlyEmployeeCorrectnessTester(hRate).invoke(id, name);
}