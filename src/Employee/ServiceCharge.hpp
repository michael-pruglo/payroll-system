#ifndef PAYROLL_SYSTEM_SERVICECHARGE_HPP
#define PAYROLL_SYSTEM_SERVICECHARGE_HPP


#include "../utility/Date.hpp"

class ServiceCharge
{
public:
    ServiceCharge(const Date& date, double amount) : date(date), amount(amount) {}
    Date getDate() const { return date; }
    double getAmount() const { return amount; }

    bool operator<(const ServiceCharge& other) const { return date<other.date; }
    bool operator==(const ServiceCharge& other) const { return date==other.date && amount==other.amount; }

private:
    Date date;
    double amount;
};


#endif //PAYROLL_SYSTEM_SERVICECHARGE_HPP
