#ifndef PAYROLL_SYSTEM_PAYMENTMETHOD_HPP
#define PAYROLL_SYSTEM_PAYMENTMETHOD_HPP


class PaymentMethod
{
public: virtual ~PaymentMethod() = default;
};

class HoldMethod : public PaymentMethod {};


#endif //PAYROLL_SYSTEM_PAYMENTMETHOD_HPP
