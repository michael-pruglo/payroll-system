#include <gtest/gtest.h>
#include "src/Transactions/DeleteEmployeeTransaction.hpp"

class DeleteEmployeeTest : public ::testing::Test
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

    void TearDown() override
    {
        database->clear();
        ASSERT_EQ(database->size(), 0);
    }

    int id = 9;
    std::string name = "Fin", address = "Finland";
    int initSize;
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};

TEST_F(DeleteEmployeeTest, DeleteEmployee)
{
    DeleteEmployeeTransaction dt(id);
    ASSERT_NO_THROW(dt.execute());
    ASSERT_THROW(database->getEmployee(id), PayrollDatabase::not_found);
    ASSERT_EQ(database->size(), initSize-1);
}

TEST_F(DeleteEmployeeTest, DeleteEmployeeTwiceThrows)
{
    DeleteEmployeeTransaction dt(id);
    ASSERT_NO_THROW(dt.execute());
    ASSERT_THROW(dt.execute(), PayrollDatabase::not_found);
    ASSERT_EQ(database->size(), initSize-1);
}