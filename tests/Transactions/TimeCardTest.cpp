#include <chrono>
#include <gtest/gtest.h>
#include <src/utility/Date.hpp>
#include <src/Transactions/AddEmployeeTransaction.hpp>
#include "src/Database/PayrollDatabase.hpp"
#include "src/Transactions/TimeCardTransaction.hpp"
#include "EmployeeCorrectnessTester.hpp"


class TimeCardTest : public ::testing::Test
{
protected:

    void SetUp() override
    {
        AddHourlyEmployee at(id, name, address, hRate);
        ASSERT_NO_THROW(at.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    void TearDown() override //TODO: construct a base class "TestingWithDB" and put there the examplebase
    {
        database->clear();
        ASSERT_EQ(database->size(), 0);
    }

    void assertDatabaseContains(int id) { ASSERT_NO_THROW(database->getEmployee(id)); }

    int id = 10;
    std::string name = "Jack", address = "Jamaica";
    Date date = Date(2020, 06, 11);
    double hours = 8.0, hRate = 10.0;
    int initSize;
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

TEST_F(TimeCardTest, TimeCardUpdates)
{
    assertDatabaseContains(id);

    TimeCardTransaction tct(date, hours, id);
    ASSERT_NO_THROW(tct.execute());

    EmployeeCorrectnessTester<
            HourlyClassification,
            WeeklySchedule
            >(hRate, 0, 0, 0)
            .invoke(id, name);
    //TODO: add check for timecard itself - 8 hours
}