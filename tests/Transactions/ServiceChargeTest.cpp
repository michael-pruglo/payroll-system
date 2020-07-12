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

    void assertDatabaseContains(int id) { ASSERT_NO_THROW(database->getEmployee(id)); }

    int id = 12;
    std::string name = "Josh", address = "Jerusalem";
    Date date = Date(2020, 8, 9);
    double amount = 17.0, hRate = 19.0;
};

TEST_F(ServiceChargeTest, ServiceChargeUpdates)
{
    assertDatabaseContains(id);

    ServiceChargeTransaction sct(date, amount, id);
    ASSERT_NO_THROW(sct.execute());

    HourlyEmployeeCorrectnessTester hect(*database->getEmployee(id), hRate);
    hect.addServiceCharge(ServiceCharge(date, amount));
    hect.invoke(id, name);
}