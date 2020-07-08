#ifndef PAYROLL_SYSTEM_SALESRECEIPTTRANSACTION_HPP
#define PAYROLL_SYSTEM_SALESRECEIPTTRANSACTION_HPP

#include "src/Employee/SalesReceipt.hpp"
#include "src/Database/PayrollDatabase.hpp"
#include "Transaction.hpp"

class SalesReceiptTransaction : public Transaction
{
public:
    SalesReceiptTransaction(const Date& date, double amount, int id) :
        date(date), amount(amount), id(id) {}

    virtual void execute() override
    {
        auto employee = PayrollDatabase::getInstance()->getEmployee(id);
        auto pc = employee->getPaymentClassification();
        auto hc = std::dynamic_pointer_cast<CommissionedClassification>(pc);
        if (hc)
            hc->addSalesReceipt(SalesReceipt(date, amount));
        else
            throw std::runtime_error("SalesReceiptTransaction not on CommissionedEmployee");
    }

    Date date;
    double amount;
    int id;
};


#endif //PAYROLL_SYSTEM_SALESRECEIPTTRANSACTION_HPP
