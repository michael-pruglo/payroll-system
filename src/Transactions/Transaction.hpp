#ifndef PAYROLL_SYSTEM_TRANSACTION_HPP
#define PAYROLL_SYSTEM_TRANSACTION_HPP


class Transaction
{
public:
    virtual ~Transaction() = default;
    virtual void execute() = 0;
};


#endif //PAYROLL_SYSTEM_TRANSACTION_HPP
