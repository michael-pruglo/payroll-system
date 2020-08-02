#ifndef PAYROLL_SYSTEM_EMPLOYEE_HPP
#define PAYROLL_SYSTEM_EMPLOYEE_HPP

#include <memory>
#include "PaymentClassification.hpp"
#include "PaymentSchedule.hpp"
#include "PaymentMethod.hpp"
#include "Affiliation.hpp"
#include "../Transactions/PaydayTransaction.hpp"


class Employee
{
public:
    Employee(int id, std::string name, std::string address);

    std::string                             getName() const { return name; }
    void                                    setName(std::string newName) { name = std::move(newName); }
    std::string                             getAddress() const { return address; }
    void                                    setAddress(std::string newAddress) { address = std::move(newAddress); }
    std::shared_ptr<PaymentClassification>  getPaymentClassification() const { return paymentClassification; }
    void                                    setPaymentClassification(std::shared_ptr<PaymentClassification> pc) { paymentClassification = pc; }
    std::shared_ptr<PaymentSchedule>        getPaymentSchedule() const { return paymentSchedule; }
    void                                    setPaymentSchedule(std::shared_ptr<PaymentSchedule> pc) { paymentSchedule = pc; }
    std::shared_ptr<PaymentMethod>          getPaymentMethod() const { return paymentMethod; }
    void                                    setPaymentMethod(std::shared_ptr<PaymentMethod> pc) { paymentMethod = pc; }
    std::shared_ptr<Affiliation>            getAffiliation() const { return affiliation; }
    void                                    setAffiliation(std::shared_ptr<Affiliation> a) { affiliation = a; }
    bool                                    isPayDate(Date date) const;
    void                                    payday(std::shared_ptr<Paycheck> paycheck);
private:
    int id;
    std::string name, address;
    std::shared_ptr<PaymentClassification> paymentClassification;
    std::shared_ptr<PaymentSchedule> paymentSchedule;
    std::shared_ptr<PaymentMethod> paymentMethod;
    std::shared_ptr<Affiliation> affiliation;
};


#endif //PAYROLL_SYSTEM_EMPLOYEE_HPP
