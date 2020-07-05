#include <gtest/gtest.h>
#include "src/PayrollDatabase.hpp"
#include "src/Transactions/TimeCardTransaction.hpp"


class TimeCardTest : public ::testing::Test
{
protected:

    void SetUp() override
    {
        ASSERT_NO_THROW(database->addEmployee(
                id, std::make_shared<Employee>(id, name, address)
        ));
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    void TearDown() override //TODO: construct a base class "TestingWithDB"
    {
        database->clear();
        ASSERT_EQ(database->size(), 0);
    }

    int id = 10;
    std::string name = "Jack", address = "Jamaica";
    int initSize;
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

TEST_F(TimeCardTest, Nothing)
{
    TimeCardTransaction tt();
}