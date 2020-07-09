#ifndef PAYROLL_SYSTEM_SALESRECEIPT_HPP
#define PAYROLL_SYSTEM_SALESRECEIPT_HPP


#include "src/utility/Date.hpp"

class SalesReceipt
{
public:
    SalesReceipt(const Date& date, double amount) : date(date), amount(amount) {}
    Date getDate() const { return date; }
    double getAmount() const { return amount; }

private:
    Date date;
    double amount;
};

#endif //PAYROLL_SYSTEM_SALESRECEIPT_HPP
