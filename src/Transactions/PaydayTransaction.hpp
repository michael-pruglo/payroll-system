#ifndef PAYROLL_SYSTEM_PAYDAYTRANSACTION_HPP
#define PAYROLL_SYSTEM_PAYDAYTRANSACTION_HPP

#include <memory>
#include <unordered_map>
#include "Transaction.hpp"
#include "../utility/Date.hpp"

class Paycheck
{
public:
    explicit    Paycheck(const Date& date) : date(date) {}
    Date        getDate() const { return date; }
    double      getGrossPay () const { return grossPay; }

private:
    Date date;
    double grossPay;
};

class PaydayTransaction : public Transaction
{
public:
    explicit                    PaydayTransaction(Date date);
    void                        execute() override;
    std::shared_ptr<Paycheck>   getPaycheck(int employeeId) const;

private:
    Date date;
    std::unordered_map<int, std::shared_ptr<Paycheck>> paychecks;
};


#endif //PAYROLL_SYSTEM_PAYDAYTRANSACTION_HPP
