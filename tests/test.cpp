

/*
class AddEmployeeTransactionTest : public ::testing::Test
{
protected:

    int empID = 1;
    std::string empName = "Bob", empAddress = "Home";
    double empSalary = 1000.00;

    void SetUp() override
    {
    }

    void TearDown() override
    {
        //TODO: delete the employee
    }



    Employee* employee;
};

TEST_F(AddEmployeeTransactionTest, CanCreateSalariedTransaction)
{
    AddSalariedEmployee t(empID, empName, empAddress, empSalary);
    t.execute();
}

TEST(AddEmployeeTransaction, AddSalariedEmployee)
{


    Employee* e = GpayrollDatabase.GetEmployee(empID);
    ASSERT_EQ(e->getName(), "Bob"); //std::string("Bob")

    PaymentClassification* pc = e->getClassification();
    SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
    ASSERT_TRUE(sc != nullptr);
    ASSERT_DOUBLE_EQ(sc->getSalary(), 1000.00);

    PaymentSchedule* ps = e->getSchedule();
    MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
    ASSERT_TRUE(ms != nullptr);

    PaymentMethod* pm = e->getMethod();
    HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
    ASSERT_TRUE(hm != nullptr);
}*/