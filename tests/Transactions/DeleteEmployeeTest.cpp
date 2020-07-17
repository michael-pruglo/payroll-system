#include <tests/EmployeeFactory.hpp>
#include "src/Transactions/DeleteEmployeeTransaction.hpp"
#include "utility/TestUsingDatabase.hpp"

class DeleteEmployeeTest : public TestUsingDatabase
{
protected:

    void SetUp() override
    {
        ASSERT_NO_THROW(database->addEmployee(
            _e.id, std::make_shared<Employee>(_e.id, _e.name, _e.address)
        ));
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }
    
    EmployeeFactory _e{9};
};

#define DELETION_TEST( EXECUTE ) \
    DeleteEmployeeTransaction dt(_e.id); \
    ASSERT_NO_THROW(dt.execute()); \
    ASSERT_THROW(EXECUTE, PayrollDatabase::not_found); \
    ASSERT_EQ(database->size(), initSize-1);


TEST_F(DeleteEmployeeTest, DeleteEmployee)
{
    DELETION_TEST(database->getEmployee(_e.id))
}

TEST_F(DeleteEmployeeTest, DeleteEmployeeTwiceThrows)
{
    DELETION_TEST(dt.execute())
}

TEST_F(DeleteEmployeeTest, TransactionOnNonExistentThrows)
{
    ASSERT_THROW(DeleteEmployeeTransaction(_e.id+1).execute(), PayrollDatabase::not_found);
}

#undef DELETION_TEST