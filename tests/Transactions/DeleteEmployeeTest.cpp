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

#define DELETION_TEST( EXECUTE ) \
    DeleteEmployeeTransaction dt(id); \
    ASSERT_NO_THROW(dt.execute()); \
    ASSERT_THROW(EXECUTE, PayrollDatabase::not_found); \
    ASSERT_EQ(database->size(), initSize-1);


TEST_F(DeleteEmployeeTest, DeleteEmployee)
{
    DELETION_TEST(database->getEmployee(id))
}

TEST_F(DeleteEmployeeTest, DeleteEmployeeTwiceThrows)
{
    DELETION_TEST(dt.execute())
}

TEST_F(DeleteEmployeeTest, TransactionOnNonExistentThrows)
{
    ASSERT_THROW(DeleteEmployeeTransaction(id+1).execute(), PayrollDatabase::not_found);
}

#undef DELETION_TEST