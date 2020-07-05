#ifndef PAYROLL_SYSTEM_PAYMENTSCHEDULE_HPP
#define PAYROLL_SYSTEM_PAYMENTSCHEDULE_HPP


class PaymentSchedule
{
public: virtual ~PaymentSchedule() = default;
};

class WeeklySchedule : public PaymentSchedule {};
class MonthlySchedule : public PaymentSchedule {};
class BiweeklySchedule : public PaymentSchedule {};


#endif //PAYROLL_SYSTEM_PAYMENTSCHEDULE_HPP
