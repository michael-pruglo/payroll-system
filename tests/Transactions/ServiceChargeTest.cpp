#include "src/Employee/ServiceCharge.hpp"
#include "src/utility/Date.hpp"
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "src/Transactions/ServiceChargeTransaction.hpp"
#include "utility/EmployeeCorrectnessTester.hpp"
#include "utility/TestUsingDatabase.hpp"


class ServiceChargeTest : public TestUsingDatabase
{
protected:

    void SetUp() override
    {
        AddHourlyEmployee at(id, name, address, hRate);
        ASSERT_NO_THROW(at.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    int id = 12;
    std::string name = "Josh", address = "Jerusalem";
    Date date = Date(2020, 8, 9);
    double amount = 17.0, hRate = 19.0;
};

#define TESTJOSH( BODY ) \
    assertDatabaseContains(id); \
    HourlyEmployeeCorrectnessTester hect(*database->getEmployee(id), hRate);\
    BODY \
    hect.invoke(id, name, address);\

TEST_F(ServiceChargeTest, ServiceChargeUpdates)
{
    TESTJOSH(
        ServiceChargeTransaction sct(date, amount, id);
        ASSERT_NO_THROW(sct.execute());

        hect.addServiceCharge(ServiceCharge(date, amount));
    )
}

TEST_F(ServiceChargeTest, NServiceCharges)
{
    TESTJOSH(
        for (int i = 0; i < 17; ++i)
        {
            auto date = Date(i, 5, 5);
            auto amount = 18.0+i;

            ServiceChargeTransaction sct(date, amount, id);
            ASSERT_NO_THROW(sct.execute());

            hect.addServiceCharge(ServiceCharge(date, amount));
        }
    )
}

#undef TESTJOSH