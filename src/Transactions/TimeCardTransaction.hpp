#ifndef PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP
#define PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP

#include <src/Database/PayrollDatabase.hpp>
#include "Transaction.hpp"

class TimeCardTransaction : public Transaction
{
public:
    TimeCardTransaction(const Date& date, double hours, int id) : date(date), hours(hours), id(id) {}

    virtual void execute() override
    {
        auto employee = PayrollDatabase::getInstance()->getEmployee(id);
        auto pc = employee->getPaymentClassification();
        auto hc = std::dynamic_pointer_cast<HourlyClassification>(pc);
        if (hc)
            hc->addTimeCard(TimeCard(date, hours));
        else
            throw std::runtime_error("TimeCardTransaction not on HourlyEmployee");
    }

    Date date;
    double hours;
    int id;
};


#endif //PAYROLL_SYSTEM_TIMECARDTRANSACTION_HPP
