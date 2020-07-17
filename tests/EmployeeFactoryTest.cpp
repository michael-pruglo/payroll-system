#include <gtest/gtest.h>
#include "EmployeeFactory.hpp"

TEST(EmployeeFactoryTest, SameSeed)
{
    EmployeeFactory ef1(99), ef2(99);
    ASSERT_EQ(ef1, ef2);
}