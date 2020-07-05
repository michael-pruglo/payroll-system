#ifndef PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP
#define PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP

#include "Transaction.hpp"

class TimeCardTransaction : public Transaction
{
public:
    TimeCardTransaction(const Date& date, double hours, int id) : date(date), hours(hours), id(id) {}

    virtual void execute() override
    {

    }

    Date date;
    double hours;
    int id;
};


#endif //PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP
