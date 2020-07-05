#include <gtest/gtest.h>
#include "src/Database/PayrollDatabase.hpp"
#include "src/Database/PayrollDatabase.cpp"
#include "src/Employee/Employee.hpp"

class PayrollDatabaseTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        ASSERT_NO_THROW(addBob());
        initSize = database->size();
        ASSERT_EQ(initSize, 1);
    }
    void TearDown() override
    {
        database->clear();
        ASSERT_EQ(database->size(), 0);
    }

    int bobId = 1, inexistentId = -1;
    std::shared_ptr<Employee> bob { new Employee(bobId, "Bob", "Boob st.") };
    inline void addBob() { database->addEmployee(bobId, bob); }
    void addNBobs(int n) { for (int i=0; i<n; ++i) database->addEmployee(i+bobId+1, bob); }


    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
    int initSize;
};

TEST_F(PayrollDatabaseTest, AddMultipleTimesThrowsAddDuplicate)
{
    for (int i = 0; i < 10; ++i)
    {
        ASSERT_THROW(addBob(), PayrollDatabase::add_duplicate);
        ASSERT_EQ(database->size(), initSize);
    }
}

TEST_F(PayrollDatabaseTest, AddMultipleDifferent)
{
    int n = 15;
    ASSERT_NO_THROW(addNBobs(n));
    ASSERT_EQ(database->size(), 1+n);
}

TEST_F(PayrollDatabaseTest, CanRetreive)
{
    ASSERT_NO_THROW({
        auto givenE = database->getEmployee(bobId);
        ASSERT_EQ(bob, givenE);
        ASSERT_EQ(database->size(), initSize);
    });
}

TEST_F(PayrollDatabaseTest, CanRetreiveMultipleTimes)
{
    ASSERT_NO_THROW({
        for (int i = 0; i < 10; ++i)
        {
            auto givenE = database->getEmployee(bobId);
            ASSERT_EQ(bob, givenE);
            ASSERT_EQ(database->size(), initSize);
        }
    });
}

TEST_F(PayrollDatabaseTest, RetrieveInexistentThrowsNotFound)
{
    ASSERT_THROW(database->getEmployee(inexistentId), PayrollDatabase::not_found);
    ASSERT_EQ(database->size(), initSize);
}

TEST_F(PayrollDatabaseTest, Update)
{
    std::shared_ptr<Employee> frank { new Employee(bobId, "Frank", "French st.") };
    ASSERT_NO_THROW(database->updateEmployee(bobId, frank));
    auto givenE = database->getEmployee(bobId);
    ASSERT_EQ(frank, givenE);
    ASSERT_EQ(database->size(), initSize);
}

TEST_F(PayrollDatabaseTest, UpdateInexistentThrowsNotFound)
{
    ASSERT_THROW(database->updateEmployee(inexistentId, nullptr), PayrollDatabase::not_found);
    ASSERT_EQ(database->size(), initSize);
}

TEST_F(PayrollDatabaseTest, Delete)
{
    ASSERT_NO_THROW(database->deleteEmployee(bobId));
    ASSERT_EQ(database->size(), initSize-1);
}

TEST_F(PayrollDatabaseTest, DeleteTwice)
{
    ASSERT_NO_THROW(database->deleteEmployee(bobId));
    ASSERT_THROW(database->deleteEmployee(bobId), PayrollDatabase::not_found);
    ASSERT_EQ(database->size(), initSize-1);
}

TEST_F(PayrollDatabaseTest, DeleteInexistentThrowsNotFound)
{
    ASSERT_THROW(database->deleteEmployee(inexistentId), PayrollDatabase::not_found);
    ASSERT_EQ(database->size(), initSize);
}

TEST_F(PayrollDatabaseTest, Clear)
{
    ASSERT_NO_THROW(addNBobs(17));
    database->clear();
    ASSERT_EQ(database->size(), 0);
}