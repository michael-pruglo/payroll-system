#ifndef PAYROLL_SYSTEM_EMPLOYEE_HPP
#define PAYROLL_SYSTEM_EMPLOYEE_HPP


#include <string>


class Employee
{
public:
    class PaymentClassification;
    class SalariedClassification;
    class HourlyClassification;
    class CommissionedClassification;

    Employee(int id, std::string name, std::string address);

    std::string             getName() const { return name; }
    PaymentClassification*  getPaymentClassification() const { return paymentClassification; }
    void                    setPaymentClassification(PaymentClassification* pc) { paymentClassification = pc; }
private:
    int id;
    std::string name, address;
    PaymentClassification* paymentClassification;
};

class Employee::PaymentClassification{ public: virtual ~PaymentClassification() = default; };

class Employee::SalariedClassification : public Employee::PaymentClassification {  };
class Employee::HourlyClassification : public Employee::PaymentClassification {  };
class Employee::CommissionedClassification : public Employee::PaymentClassification {  };


#endif //PAYROLL_SYSTEM_EMPLOYEE_HPP
