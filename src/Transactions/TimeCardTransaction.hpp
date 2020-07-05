#ifndef PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP
#define PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP

#include "Transaction.hpp"

class TimeCardTransaction : public Transaction
{
public:
    virtual void execute() override
    {

    }
};


#endif //PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP
