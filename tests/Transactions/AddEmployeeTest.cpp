#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/AddEmployeeTransaction.cpp"
#include "utility/EmployeeCorrectnessTester.hpp"
#include "utility/TestUsingDatabase.hpp"

class AddEmployeeTest : public TestUsingDatabase
{
protected:

    int         hId = 1,                sId = 2,                cId = 3;
    std::string hName = "Howard",       sName = "Sally",        cName = "Camilla";
    std::string hAddress = "Hour st.",  sAddress = "Sal st.",   cAddress = "Comi st.";
    double      hRate = 17.7,           sSalary = 1000.33,      cSalary = 2000.88, cRate = 0.05;
};

#define ADDITION_TEST( ADDITION_TRANSACTION, CHECK ) \
    ASSERT_NO_THROW(ADDITION_TRANSACTION.execute()); \
    ASSERT_EQ(database->size(), 1); \
    CHECK;


TEST_F(AddEmployeeTest, HourlyEmployee)
{
    ADDITION_TEST(
        ( AddHourlyEmployee(hId, hName, hAddress, hRate) ),
        ( HourlyEmployeeCorrectnessTester(*database->getEmployee(hId), hRate).invoke(hId, hName, hAddress) )
    )
}

TEST_F(AddEmployeeTest, SalariedEmployee)
{
    ADDITION_TEST(
        ( AddSalariedEmployee(sId, sName, sAddress, sSalary)),
        ( SalariedEmployeeCorrectnessTester(*database->getEmployee(sId), sSalary).invoke(sId, sName, sAddress))
    )
}

TEST_F(AddEmployeeTest, CommissionedEmployee)
{
    ADDITION_TEST(
        ( AddCommissionedEmployee(cId, cName, cAddress, cSalary, cRate) ),
        ( CommissionedEmployeeCorrectnessTester(*database->getEmployee(cId), cSalary, cRate).invoke(cId, cName, cAddress) )
    )
}

#undef ADDITION_TEST