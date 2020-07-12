#ifndef PAYROLL_SYSTEM_SERVICECHARGETRANSACTION_HPP
#define PAYROLL_SYSTEM_SERVICECHARGETRANSACTION_HPP


#include "Transaction.hpp"
#include "../Database/PayrollDatabase.hpp"

class ServiceChargeTransaction : public Transaction
{
public:
    ServiceChargeTransaction(const Date& date, double amount, int id) : date(date), amount(amount), id(id) {}

    virtual void execute() override
    {
        auto employee = PayrollDatabase::getInstance()->getEmployee(id);
        auto aff = employee->getAffiliation();
        aff->addServiceCharge(ServiceCharge(date, amount));
        employee->setAffiliation(aff);
    }

    Date date;
    double amount;
    int id;
};


#endif //PAYROLL_SYSTEM_SERVICECHARGETRANSACTION_HPP
