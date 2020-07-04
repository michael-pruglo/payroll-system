#ifndef PAYROLL_SYSTEM_EMPLOYEE_HPP
#define PAYROLL_SYSTEM_EMPLOYEE_HPP


#include <string>
#include <memory>


class Employee
{
public:
    class PaymentClassification;
    class SalariedClassification;
    class HourlyClassification;
    class CommissionedClassification;

    Employee(int id, std::string name, std::string address);

    std::string                             getName() const { return name; }
    std::shared_ptr<PaymentClassification>  getPaymentClassification() const { return paymentClassification; }
    void                                    setPaymentClassification(std::shared_ptr<PaymentClassification> pc) { paymentClassification = pc; }
private:
    int id;
    std::string name, address;
    std::shared_ptr<PaymentClassification> paymentClassification;
};

class Employee::PaymentClassification{ public: virtual ~PaymentClassification() = default; };

class Employee::HourlyClassification : public Employee::PaymentClassification
{
public:
    explicit HourlyClassification(double hourlyRate) : hourlyRate(hourlyRate) {}
    double getHourlyRate() const { return hourlyRate; }
private:
    double hourlyRate;
};
class Employee::SalariedClassification : public Employee::PaymentClassification
{
public:
    SalariedClassification(double salary) : salary(salary) {}
    double getSalary() const { return salary; }
private:
    double salary;
};
class Employee::CommissionedClassification : public Employee::PaymentClassification
{
public:
    CommissionedClassification(double salary, double commissionRate) :
        salary(salary), commissionRate(commissionRate) {}

    double getSalary() const { return salary; }
    double getCommissionRate() const { return commissionRate; }
private:
    double salary, commissionRate;
};


#endif //PAYROLL_SYSTEM_EMPLOYEE_HPP
