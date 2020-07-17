#include <tests/EmployeeFactory.hpp>
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
        AddHourlyEmployee at(_eh.id, _eh.name, _eh.address, _eh.hRate);
        ASSERT_NO_THROW(at.execute());
        AddSalariedEmployee ast(_es.id, _es.name, _es.address, _es.sSalary);
        ASSERT_NO_THROW(ast.execute());
        initSize = database->size();
        EXPECT_EQ(initSize, 2);
    }

    EmployeeFactory _eh{4}, _es{5};
};

TEST_F(ChangeEmployeeTest, ChangeName)
{
    assertDatabaseContains(_eh.id);

    std::string newName = "Elizabeth";
    ChangeNameTransaction cnt(_eh.id, newName);
    ASSERT_NO_THROW(cnt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate).invoke(_eh.id, newName, _eh.address);
}

TEST_F(ChangeEmployeeTest, ChangeAddress)
{
    assertDatabaseContains(_eh.id);

    std::string newAddress = "England";
    ChangeAddressTransaction cat(_eh.id, newAddress);
    ASSERT_NO_THROW(cat.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate).invoke(_eh.id, _eh.name, newAddress);
}

TEST_F(ChangeEmployeeTest, ChangeHourlyToCommissioned)
{
    assertDatabaseContains(_eh.id);

    double cRate = 0.8, cSalary = 999.9;
    ChangeToCommissionedTransaction ctct(_eh.id, cSalary, cRate);
    ASSERT_NO_THROW(ctct.execute());

    CommissionedEmployeeCorrectnessTester(*database->getEmployee(_eh.id), cSalary, cRate).invoke(_eh.id, _eh.name, _eh.address);
}
TEST_F(ChangeEmployeeTest, ChangeHourlyToSalaried)
{
    assertDatabaseContains(_eh.id);

    ChangeToSalariedTransaction ctst(_eh.id, _es.sSalary);
    ASSERT_NO_THROW(ctst.execute());

    SalariedEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _es.sSalary).invoke(_eh.id, _eh.name, _eh.address);
}
TEST_F(ChangeEmployeeTest, ChangeSalariedToHourly)
{
    assertDatabaseContains(_es.id);

    ChangeToHourlyTransaction ctht(_es.id, _es.hRate);
    ASSERT_NO_THROW(ctht.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_es.id), _es.hRate).invoke(_es.id, _es.name, _es.address);
}

TEST_F(ChangeEmployeeTest, ChangeMethodHoldToDirect)
{
    assertDatabaseContains(_eh.id);

    std::string bank = "Privat";
    int account = 937272;
    ChangeToDirectMethodTransaction ctdmt(_eh.id, bank, account);
    ASSERT_NO_THROW(ctdmt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate)
        .invoke<DirectMethod>(_eh.id, _eh.name, _eh.address);
}
TEST_F(ChangeEmployeeTest, ChangeMethodHoldToMail)
{
    assertDatabaseContains(_eh.id);

    ChangeToMailMethodTransaction ctdmt(_eh.id, _eh.address);
    ASSERT_NO_THROW(ctdmt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate)
        .invoke<MailMethod>(_eh.id, _eh.name, _eh.address);
}
TEST_F(ChangeEmployeeTest, ChangeMethodHoldToMailAndBack)
{
    assertDatabaseContains(_eh.id);

    ChangeToMailMethodTransaction ctdmt(_eh.id, _eh.address);
    ASSERT_NO_THROW(ctdmt.execute());
    ChangeToHoldMethodTransaction cthmt(_eh.id);
    ASSERT_NO_THROW(cthmt.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate)
        .invoke(_eh.id, _eh.name, _eh.address);
}

TEST_F(ChangeEmployeeTest, ChangeAffiliationToMember)
{
    assertDatabaseContains(_eh.id);

    int memberId = 88;
    ChangeToUnionAffiliationTransaction ctuat(_eh.id, memberId);
    ASSERT_NO_THROW(ctuat.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(database->getIdByUnionMemberId(memberId)), _eh.hRate)
        .invoke<HoldMethod, UnionAffiliation>(_eh.id, _eh.name, _eh.address);
}
TEST_F(ChangeEmployeeTest, ChangeAffiliationToNo)
{
    assertDatabaseContains(_eh.id);

    ChangeToNoAffiliationTransaction ctnat(_eh.id);
    ASSERT_NO_THROW(ctnat.execute());

    HourlyEmployeeCorrectnessTester(*database->getEmployee(_eh.id), _eh.hRate)
        .invoke<HoldMethod, NoAffiliation>(_eh.id, _eh.name, _eh.address);
}