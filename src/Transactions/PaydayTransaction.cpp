#include "PaydayTransaction.hpp"
#include "../Database/PayrollDatabase.hpp"

PaydayTransaction::PaydayTransaction(Date date) : date(date)
{}

void PaydayTransaction::execute()
{
    for (auto id : PayrollDatabase::getInstance()->getAllIds())
    {
        auto emp = PayrollDatabase::getInstance()->getEmployee(id);
        if (emp->isPayDate(date))
        {
            auto paycheck = std::make_shared<Paycheck>(date);
            paychecks[id] = paycheck;
            emp->payday(paycheck);
        }
    }
}

std::shared_ptr<Paycheck> PaydayTransaction::getPaycheck(int employeeId) const
{
    return paychecks.at(employeeId);
}

