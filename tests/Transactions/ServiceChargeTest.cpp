#include <tests/EmployeeFactory.hpp>
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
        AddHourlyEmployee at(_eh.id, _eh.name, _eh.address, _eh.hRate);
        ASSERT_NO_THROW(at.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 1);
    }

    EmployeeFactory _eh{15};
};

#define TESTJOSH( BODY ) \
    assertDatabaseContains(_eh.id); \
    HourlyEmployeeCorrectnessTester hect(*database->getEmployee(_eh.id), _eh.hRate);\
    BODY \
    hect.invoke(_eh.id, _eh.name, _eh.address);\

TEST_F(ServiceChargeTest, ServiceChargeUpdates)
{
    TESTJOSH(
        ServiceChargeTransaction sct(_eh.date, _eh.amount, _eh.id);
        ASSERT_NO_THROW(sct.execute());

        hect.addServiceCharge(ServiceCharge(_eh.date, _eh.amount));
    )
}

TEST_F(ServiceChargeTest, NServiceCharges)
{
    TESTJOSH(
        for (int i = 0; i < 17; ++i)
        {
            auto date = Date(i, 5, 5);
            auto amount = 18.0+i;

            ServiceChargeTransaction sct(date, amount, _eh.id);
            ASSERT_NO_THROW(sct.execute());

            hect.addServiceCharge(ServiceCharge(date, amount));
        }
    )
}

#undef TESTJOSH