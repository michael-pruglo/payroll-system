#include "src/Transactions/ChangeEmployeeTransaction.hpp"
#include "src/Transactions/ChangeEmployeeTransaction.cpp"
#include "src/Transactions/AddEmployeeTransaction.hpp"
#include "utility/EmployeeCorrectnessTester.hpp"
#include "utility/TestUsingDatabase.hpp"


class ChangeEmployeeTest : public TestUsingDatabase
{
protected:

    void SetUp() override
    {
        AddHourlyEmployee at(id, name, address, hRate);
        ASSERT_NO_THROW(at.execute());
        AddSalariedEmployee ast(sId, sName, sAddress, sSalary);
        ASSERT_NO_THROW(ast.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 2);
    }

    int id = 21, sId = 22;
    std::string name = "Lizz", address = "Lesoto", sName = "Sally", sAddress = "Salamore";
    double hRate = 10.0, sSalary = 1028.7;
};

TEST_F(ChangeEmployeeTest, ChangeName)
{
    assertDatabaseContains(id);

    std::string newName = "Elizabeth";
    ChangeNameTransaction cnt(id, newName);
    ASSERT_NO_THROW(cnt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(id), hRate).invoke(id, newName, address);
}

TEST_F(ChangeEmployeeTest, ChangeAddress)
{
    assertDatabaseContains(id);

    std::string newAddress = "England";
    ChangeAddressTransaction cat(id, newAddress);
    ASSERT_NO_THROW(cat.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(id), hRate).invoke(id, name, newAddress);
}

TEST_F(ChangeEmployeeTest, ChangeHourlyToCommissioned)
{
    assertDatabaseContains(id);

    double cRate = 0.8, cSalary = 999.9;
    ChangeToCommissionedTransaction ctct(id, cSalary, cRate);
    ASSERT_NO_THROW(ctct.execute());

    CommissionedEmployeeCorrectnessTester(*database->getEmployee(id), cSalary, cRate).invoke(id, name, address);
}
TEST_F(ChangeEmployeeTest, ChangeHourlyToSalaried)
{
    assertDatabaseContains(id);

    ChangeToSalariedTransaction ctst(id, sSalary);
    ASSERT_NO_THROW(ctst.execute());

    SalariedEmployeeCorrectnessTester(*database->getEmployee(id), sSalary).invoke(id, name, address);
}
TEST_F(ChangeEmployeeTest, ChangeSalariedToHourly)
{
    assertDatabaseContains(sId);

    ChangeToHourlyTransaction ctht(sId, hRate);
    ASSERT_NO_THROW(ctht.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(sId), hRate).invoke(sId, sName, sAddress);
}

TEST_F(ChangeEmployeeTest, ChangeMethodHoldToDirect)
{
    assertDatabaseContains(id);

    std::string bank = "Privat";
    int account = 937272;
    ChangeToDirectMethodTransaction ctdmt(id, bank, account);
    ASSERT_NO_THROW(ctdmt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(id), hRate)
        .invoke<DirectMethod>(id, name, address);
}

TEST_F(ChangeEmployeeTest, ChangeMethodHoldToMail)
{
    assertDatabaseContains(id);

    ChangeToMailMethodTransaction ctdmt(id, address);
    ASSERT_NO_THROW(ctdmt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(id), hRate)
        .invoke<MailMethod>(id, name, address);
}

TEST_F(ChangeEmployeeTest, ChangeMethodHoldToMailAndBack)
{
    assertDatabaseContains(id);

    ChangeToMailMethodTransaction ctdmt(id, address);
    ASSERT_NO_THROW(ctdmt.execute());
    ChangeToHoldMethodTransaction cthmt(id);
    ASSERT_NO_THROW(cthmt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(id), hRate)
        .invoke(id, name, address);
}