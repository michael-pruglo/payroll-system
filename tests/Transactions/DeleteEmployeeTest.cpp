#include <gtest/gtest.h>
#include "src/Transactions/DeleteEmployeeTransaction.hpp"
#include "utility/TestUsingDatabase.hpp"

class DeleteEmployeeTest : public TestUsingDatabase
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

    int id = 9;
    std::string name = "Fin", address = "Finland";
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