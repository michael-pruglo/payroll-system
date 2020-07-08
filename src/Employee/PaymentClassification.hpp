#ifndef PAYROLL_SYSTEM_PAYMENTCLASSIFICATION_HPP
#define PAYROLL_SYSTEM_PAYMENTCLASSIFICATION_HPP


#include "TimeCard.hpp"
#include "SalesReceipt.hpp"

class PaymentClassification { public: virtual ~PaymentClassification() = default; };
class HourlyClassification : public PaymentClassification
{
public:
    explicit HourlyClassification(double hourlyRate) : hourlyRate(hourlyRate) {}
    double getHourlyRate() const { return hourlyRate; }
    void addTimeCard(TimeCard tc) { timeCards.insert({tc.getDate(), tc}); }
    TimeCard getTimeCard(Date date) const
    {
        auto it = timeCards.find(date);
        if (it != timeCards.end())
            return it->second;
        else
            throw std::runtime_error("HourlyClassification::getTimeCard() - doesn't have such a timecard");
    }
private:
    double hourlyRate;
    std::map<Date, TimeCard> timeCards;
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
    void addSalesReceipt(SalesReceipt sr) { salesReceipts.insert({sr.getDate(), sr}); }
    SalesReceipt getSalesReceipt(Date date) const
    {
        auto it = salesReceipts.find(date);
        if (it != salesReceipts.end())
            return it->second;
        else
            throw std::runtime_error("CommissionedClassification::getSalesReceipt() - doesn't have such a receipt");
    }
private:
    double salary, commissionRate;
    std::map<Date, SalesReceipt> salesReceipts;
};


#endif //PAYROLL_SYSTEM_PAYMENTCLASSIFICATION_HPP
