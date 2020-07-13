#ifndef PAYROLL_SYSTEM_PAYMENTMETHOD_HPP
#define PAYROLL_SYSTEM_PAYMENTMETHOD_HPP


class PaymentMethod
{
public: virtual ~PaymentMethod() = default;
};

class HoldMethod : public PaymentMethod {};
class DirectMethod : public PaymentMethod
{
public:
    DirectMethod(std::string bank, int account) : bank(bank), account(account) {}
private:
    std::string bank;
    int account;
};
class MailMethod : public PaymentMethod
{
public:
    MailMethod(const std::string& address) : address(address) {}
private:
    std::string address;
};


#endif //PAYROLL_SYSTEM_PAYMENTMETHOD_HPP
