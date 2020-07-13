#ifndef PAYROLL_SYSTEM_CHANGEEMPLOYEETRANSACTION_HPP
#define PAYROLL_SYSTEM_CHANGEEMPLOYEETRANSACTION_HPP


#include "Transaction.hpp"
#include "../Employee/Employee.hpp"

class ChangeEmployeeTransaction : public Transaction
{
public:
    explicit ChangeEmployeeTransaction(int id) : id(id) {}
    virtual ~ChangeEmployeeTransaction() = default;

    virtual void execute() override;
    virtual void change(std::shared_ptr<Employee>) = 0;

protected:
    int id;
};

class ChangeNameTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeNameTransaction(int id, const std::string& newName) : ChangeEmployeeTransaction(id), newName(newName) {}
    void change(std::shared_ptr<Employee> employee) override;

private:
    std::string newName;
};

class ChangeAddressTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeAddressTransaction(int id, const std::string& newAddress) : ChangeEmployeeTransaction(id), newAddress(newAddress) {}
    void change(std::shared_ptr<Employee> employee) override;

private:
    std::string newAddress;
};

class ChangeClassificationTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeClassificationTransaction(int id) : ChangeEmployeeTransaction(id) {}
    virtual ~ChangeClassificationTransaction() = default;

    void change(std::shared_ptr<Employee> ptr) override;
    virtual std::shared_ptr<PaymentClassification> getClassification() const = 0;
    virtual std::shared_ptr<PaymentSchedule> getSchedule() const = 0;
};

class ChangeToHourlyTransaction : public ChangeClassificationTransaction
{
public:
    ChangeToHourlyTransaction(int id, double hRate) : ChangeClassificationTransaction(id), hRate(hRate) {}
    std::shared_ptr<PaymentClassification> getClassification() const override;
    std::shared_ptr<PaymentSchedule> getSchedule() const override;
private:
    double hRate;
};
class ChangeToSalariedTransaction : public ChangeClassificationTransaction
{
public:
    ChangeToSalariedTransaction(int id, double sSalary) : ChangeClassificationTransaction(id), sSalary(sSalary) {}
    std::shared_ptr<PaymentClassification> getClassification() const override;
    std::shared_ptr<PaymentSchedule> getSchedule() const override;
private:
    double sSalary;
};
class ChangeToCommissionedTransaction : public ChangeClassificationTransaction
{
public:
    ChangeToCommissionedTransaction(int id, double cSalary, double cRate) :
        ChangeClassificationTransaction(id),
        cSalary(cSalary),
        cRate(cRate)
    {}

    std::shared_ptr<PaymentClassification> getClassification() const override;
    std::shared_ptr<PaymentSchedule> getSchedule() const override;
private:
    double cSalary, cRate;
};

class ChangeMethodTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeMethodTransaction(int id) : ChangeEmployeeTransaction(id) {}
    virtual ~ChangeMethodTransaction() override = default;
    void change(std::shared_ptr<Employee> employee) override;
    virtual std::shared_ptr<PaymentMethod> getPaymentMethod() const = 0;
};
class ChangeToDirectMethodTransaction : public ChangeMethodTransaction
{
public:
    ChangeToDirectMethodTransaction(int id, std::string bank, int account);
    std::shared_ptr<PaymentMethod> getPaymentMethod() const override;
private:
    std::string bank;
    int account;
};
class ChangeToMailMethodTransaction : public ChangeMethodTransaction
{
public:
    ChangeToMailMethodTransaction(int id, std::string address);
    std::shared_ptr<PaymentMethod> getPaymentMethod() const override;
private:
    std::string address;
};
class ChangeToHoldMethodTransaction : public ChangeMethodTransaction
{
public:
    ChangeToHoldMethodTransaction(int id);
    std::shared_ptr<PaymentMethod> getPaymentMethod() const override;
};

class ChangeAffiliationTransaction : public ChangeEmployeeTransaction
{
public:
    ChangeAffiliationTransaction(int id) : ChangeEmployeeTransaction(id) {}
    virtual ~ChangeAffiliationTransaction() override = default;
    void change(std::shared_ptr<Employee> employee) override;
    virtual void recordMembership(std::shared_ptr<Employee> employee) = 0;
    virtual std::shared_ptr<Affiliation> getAffiliation() const = 0;
};
class ChangeToUnionAffiliationTransaction : public ChangeAffiliationTransaction
{
public:
    ChangeToUnionAffiliationTransaction(int id, int memberId);
    std::shared_ptr<Affiliation> getAffiliation() const override;
    void recordMembership(std::shared_ptr<Employee> employee) override;
private:
    int memberId;
};
class ChangeToNoAffiliationTransaction : public ChangeAffiliationTransaction
{
public:
    ChangeToNoAffiliationTransaction(int id);
    std::shared_ptr<Affiliation> getAffiliation() const override;
    void recordMembership(std::shared_ptr<Employee> employee) override;
};

#endif //PAYROLL_SYSTEM_CHANGEEMPLOYEETRANSACTION_HPP
