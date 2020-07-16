#include <gtest/gtest.h>
#include <src/utility/Date.hpp>

TEST(DateTest, Create)
{
    ASSERT_NO_THROW(Date(1996, 7, 8));
}

TEST(DateTest, Leap1) { ASSERT_TRUE(Date::isLeapYear(2004)); }
TEST(DateTest, Leap2) { ASSERT_TRUE(Date::isLeapYear(2000)); }
TEST(DateTest, Leap3) { ASSERT_TRUE(Date::isLeapYear(2008)); }
TEST(DateTest, Leap4) { ASSERT_FALSE(Date::isLeapYear(2001)); }
TEST(DateTest, Leap5) { ASSERT_FALSE(Date::isLeapYear(1900)); }
TEST(DateTest, Month1) { ASSERT_TRUE(Date(1990, 1, 31).isLastDayOfMonth()); }
TEST(DateTest, Month2) { ASSERT_TRUE(Date(1990, 2, 28).isLastDayOfMonth()); }
TEST(DateTest, Month3) { ASSERT_TRUE(Date(2004, 2, 29).isLastDayOfMonth()); }
TEST(DateTest, Month4) { ASSERT_TRUE(Date(1990, 3, 31).isLastDayOfMonth()); }
TEST(DateTest, Month5) { ASSERT_TRUE(Date(1990, 4, 30).isLastDayOfMonth()); }
TEST(DateTest, Month6) { ASSERT_TRUE(Date(1990, 5, 31).isLastDayOfMonth()); }
TEST(DateTest, Month7) { ASSERT_TRUE(Date(1990, 6, 30).isLastDayOfMonth()); }
TEST(DateTest, Month8) { ASSERT_TRUE(Date(1990, 7, 31).isLastDayOfMonth()); }
TEST(DateTest, Month9) { ASSERT_TRUE(Date(1990, 8, 31).isLastDayOfMonth()); }
TEST(DateTest, Month10) { ASSERT_TRUE(Date(1990, 9, 30).isLastDayOfMonth()); }
TEST(DateTest, Month11) { ASSERT_TRUE(Date(1990, 10, 31).isLastDayOfMonth()); }
TEST(DateTest, Month12) { ASSERT_TRUE(Date(1990, 11, 30).isLastDayOfMonth()); }
TEST(DateTest, Month13) { ASSERT_TRUE(Date(1990, 12, 31).isLastDayOfMonth()); }