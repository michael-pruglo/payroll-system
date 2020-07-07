#ifndef PAYROLL_SYSTEM_TESTUSINGDATABASE_HPP
#define PAYROLL_SYSTEM_TESTUSINGDATABASE_HPP


#include <gtest/gtest.h>
#include "src/Database/PayrollDatabase.hpp"

class TestUsingDatabase : public ::testing::Test
{
protected:

    void TearDown() override
    {
        database->clear();
        ASSERT_EQ(database->size(), 0);
    }

    int initSize = 0;
    std::shared_ptr<PayrollDatabase> database = PayrollDatabase::getInstance();
};


#endif //PAYROLL_SYSTEM_TESTUSINGDATABASE_HPP
