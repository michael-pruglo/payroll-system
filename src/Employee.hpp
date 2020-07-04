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

    class PaymentSchedule;
    class WeeklySchedule;
    class MonthlySchedule;
    class BiweeklySchedule;

    class PaymentMethod;
    class HoldMethod;

    Employee(int id, std::string name, std::string address);

    std::string                             getName() const { return name; }
    std::shared_ptr<PaymentClassification>  getPaymentClassification() const { return paymentClassification; }
    void                                    setPaymentClassification(std::shared_ptr<PaymentClassification> pc) { paymentClassification = pc; }
    std::shared_ptr<PaymentSchedule>        getPaymentSchedule() const { return paymentSchedule; }
    void                                    setPaymentSchedule(std::shared_ptr<PaymentSchedule> pc) { paymentSchedule = pc; }
    std::shared_ptr<PaymentMethod>          getPaymentMethod() const { return paymentMethod; }
    void                                    setPaymentMethod(std::shared_ptr<PaymentMethod> pc) { paymentMethod = pc; }
private:
    int id;
    std::string name, address;
    std::shared_ptr<PaymentClassification> paymentClassification;
    std::shared_ptr<PaymentSchedule> paymentSchedule;
    std::shared_ptr<PaymentMethod> paymentMethod;
};

class Employee::PaymentClassification { public: virtual ~PaymentClassification() = default; };
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

class Employee::PaymentSchedule { public: virtual ~PaymentSchedule() = default; };
class Employee::WeeklySchedule : public Employee::PaymentSchedule {};
class Employee::MonthlySchedule : public Employee::PaymentSchedule {};
class Employee::BiweeklySchedule : public Employee::PaymentSchedule {};

class Employee::PaymentMethod { public: virtual ~PaymentMethod() = default; };
class Employee::HoldMethod : public Employee::PaymentMethod {};

#endif //PAYROLL_SYSTEM_EMPLOYEE_HPP
