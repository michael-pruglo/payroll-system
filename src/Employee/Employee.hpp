#ifndef PAYROLL_SYSTEM_EMPLOYEE_HPP
#define PAYROLL_SYSTEM_EMPLOYEE_HPP

#include <memory>
#include "PaymentClassification.hpp"
#include "PaymentSchedule.hpp"
#include "PaymentMethod.hpp"


class Employee
{
public:
    Employee(int id, std::string name, std::string address) :
            id(id),
            name(std::move(name)),
            address(std::move(address))
    {}

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

#endif //PAYROLL_SYSTEM_EMPLOYEE_HPP
