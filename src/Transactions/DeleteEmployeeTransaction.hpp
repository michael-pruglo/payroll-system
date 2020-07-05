#ifndef PAYROLL_SYSTEM_DELETEEMPLOYEETRANSACTION_HPP
#define PAYROLL_SYSTEM_DELETEEMPLOYEETRANSACTION_HPP


#include "Transaction.hpp"
#include "src/Database/PayrollDatabase.hpp"

class DeleteEmployeeTransaction : public Transaction
{
public:
    DeleteEmployeeTransaction(int id) : id(id) {}
    virtual void execute() override
    {
        PayrollDatabase::getInstance()->deleteEmployee(id);
    }

private:
    int id;
};


#endif //PAYROLL_SYSTEM_DELETEEMPLOYEETRANSACTION_HPP
