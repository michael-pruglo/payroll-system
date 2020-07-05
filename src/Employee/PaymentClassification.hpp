#ifndef PAYROLL_SYSTEM_PAYMENTCLASSIFICATION_HPP
#define PAYROLL_SYSTEM_PAYMENTCLASSIFICATION_HPP


class PaymentClassification { public: virtual ~PaymentClassification() = default; };
class HourlyClassification : public PaymentClassification
{
public:
    explicit HourlyClassification(double hourlyRate) : hourlyRate(hourlyRate) {}
    double getHourlyRate() const { return hourlyRate; }
private:
    double hourlyRate;
};
class SalariedClassification : public PaymentClassification
{
public:
    SalariedClassification(double salary) : salary(salary) {}
    double getSalary() const { return salary; }
private:
    double salary;
};
class CommissionedClassification : public PaymentClassification
{
public:
    CommissionedClassification(double salary, double commissionRate) :
            salary(salary), commissionRate(commissionRate) {}

    double getSalary() const { return salary; }
    double getCommissionRate() const { return commissionRate; }
private:
    double salary, commissionRate;
};


#endif //PAYROLL_SYSTEM_PAYMENTCLASSIFICATION_HPP
