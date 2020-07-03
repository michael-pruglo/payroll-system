#include <gtest/gtest.h>
#include "src/PayrollDatabase.hpp"
#include "src/PayrollDatabase.cpp"
#include "src/Employee.hpp"

class PayrollDatabaseTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        ASSERT_NO_THROW(addBob());
        initSize = database.size();
        ASSERT_EQ(initSize, 1);
    }

    Employee bob;
    int bobId = 1, inexistentId = -1;
    inline void addBob() { database.addEmployee(bobId, &bob); }


    PayrollDatabase database;
    int initSize;
};

TEST_F(PayrollDatabaseTest, AddMultipleTimesThrowsAddDuplicate)
{
    for (int i = 0; i < 10; ++i)
    {
        ASSERT_THROW(addBob(), PayrollDatabase::add_duplicate);
        ASSERT_EQ(database.size(), initSize);
    }
}

TEST_F(PayrollDatabaseTest, CanRetreive)
{
    ASSERT_NO_THROW({
        auto givenE = database.getEmployee(bobId);
        ASSERT_EQ(&bob, givenE);
        ASSERT_EQ(database.size(), initSize);
    });
}

TEST_F(PayrollDatabaseTest, CanRetreiveMultipleTimes)
{
    ASSERT_NO_THROW({
        for (int i = 0; i < 10; ++i)
        {
            auto givenE = database.getEmployee(bobId);
            ASSERT_EQ(&bob, givenE);
            ASSERT_EQ(database.size(), initSize);
        }
    });
}

TEST_F(PayrollDatabaseTest, RetrieveInexistentThrowsNotFound)
{
    ASSERT_THROW(database.getEmployee(inexistentId), PayrollDatabase::not_found);
    ASSERT_EQ(database.size(), initSize);
}

TEST_F(PayrollDatabaseTest, Update)
{
    Employee frank;
    ASSERT_NO_THROW(database.updateEmployee(bobId, &frank));
    auto givenE = database.getEmployee(bobId);
    ASSERT_EQ(&frank, givenE);
    ASSERT_EQ(database.size(), initSize);
}

TEST_F(PayrollDatabaseTest, UpdateInexistentThrowsNotFound)
{
    ASSERT_THROW(database.updateEmployee(inexistentId, nullptr), PayrollDatabase::not_found);
    ASSERT_EQ(database.size(), initSize);
}

TEST_F(PayrollDatabaseTest, Delete)
{
    ASSERT_NO_THROW(database.deleteEmployee(bobId));
    ASSERT_EQ(database.size(), initSize-1);
}

TEST_F(PayrollDatabaseTest, DeleteTwice)
{
    ASSERT_NO_THROW(database.deleteEmployee(bobId));
    ASSERT_THROW(database.deleteEmployee(bobId), PayrollDatabase::not_found);
    ASSERT_EQ(database.size(), initSize-1);
}

TEST_F(PayrollDatabaseTest, DeleteInexistentThrowsNotFound)
{
    ASSERT_THROW(database.deleteEmployee(inexistentId), PayrollDatabase::not_found);
    ASSERT_EQ(database.size(), initSize);
}
