#include <tests/EmployeeFactory.hpp>
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/AddEmployeeTransaction.cpp"
#include "utility/EmployeeCorrectnessTester.hpp"
#include "utility/TestUsingDatabase.hpp"

class AddEmployeeTest : public TestUsingDatabase
{
protected:
    EmployeeFactory _eh{1}, _es{2}, _ec{3};
};

#define ADDITION_TEST( ADDITION_TRANSACTION, CHECK ) \
    ASSERT_NO_THROW(ADDITION_TRANSACTION.execute()); \
    ASSERT_EQ(database->size(), 1); \
    CHECK;


TEST_F(AddEmployeeTest, HourlyEmployee)
{
    ADDITION_TEST(
        ( AddHourlyEmployee(_eh.id, _eh.name, _eh.address, _eh.hRate) ),
        ( HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate).invoke(_eh.id, _eh.name, _eh.address) )
    )
}

TEST_F(AddEmployeeTest, SalariedEmployee)
{
    ADDITION_TEST(
        ( AddSalariedEmployee(_es.id, _es.name, _es.address, _es.sSalary)),
        ( SalariedEmployeeCorrectnessTester(*database->getEmployee(_es.id), _es.sSalary).invoke(_es.id, _es.name, _es.address))
    )
}

TEST_F(AddEmployeeTest, CommissionedEmployee)
{
    ADDITION_TEST(
        ( AddCommissionedEmployee(_ec.id, _ec.name,_ec.address, _ec.cSalary, _ec.cRate) ),
        ( CommissionedEmployeeCorrectnessTester(*database->getEmployee(_ec.id), _ec.cSalary, _ec.cRate).invoke(_ec.id, _ec.name, _ec.address) )
    )
}

#undef ADDITION_TEST