#ifndef PAYROLL_SYSTEM_TIMECARD_HPP
#define PAYROLL_SYSTEM_TIMECARD_HPP

#include <src/utility/Date.hpp>

class TimeCard
{
public:
    TimeCard(const Date& date, double hours) : date(date), hours(hours) {}
    Date getDate() const { return date; }
    double getHours() const { return hours; }

private:
    Date date;
    double hours;
};


#endif //PAYROLL_SYSTEM_TIMECARD_HPP
