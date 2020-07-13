#include "ChangeEmployeeTransaction.hpp"
#include "../Database/PayrollDatabase.hpp"

void ChangeEmployeeTransaction::execute()
{
    auto employee = PayrollDatabase::getInstance()->getEmployee(id);
    change(employee);
}

void ChangeNameTransaction::change(std::shared_ptr<Employee> employee)
{
    employee->setName(newName);
}

void ChangeAddressTransaction::change(std::shared_ptr<Employee> employee)
{
    employee->setAddress(newAddress);
}

void ChangeClassificationTransaction::change(std::shared_ptr<Employee> employee)
{
    employee->setPaymentClassification(getClassification());
    employee->setPaymentSchedule(getSchedule());
}

std::shared_ptr<PaymentClassification> ChangeToHourlyTransaction::getClassification() const
{
    return std::make_shared<HourlyClassification>(hRate);
}

std::shared_ptr<PaymentSchedule> ChangeToHourlyTransaction::getSchedule() const
{
    return std::make_shared<WeeklySchedule>();
}

std::shared_ptr<PaymentClassification> ChangeToSalariedTransaction::getClassification() const
{
    return std::make_shared<SalariedClassification>(sSalary);
}

std::shared_ptr<PaymentSchedule> ChangeToSalariedTransaction::getSchedule() const
{
    return std::make_shared<MonthlySchedule>();
}

std::shared_ptr<PaymentClassification> ChangeToCommissionedTransaction::getClassification() const
{
    return std::make_shared<CommissionedClassification>(cSalary, cRate);
}

std::shared_ptr<PaymentSchedule> ChangeToCommissionedTransaction::getSchedule() const
{
    return std::make_shared<BiweeklySchedule>();
}

void ChangeMethodTransaction::change(std::shared_ptr<Employee> employee)
{
    employee->setPaymentMethod(getPaymentMethod());
}

ChangeToDirectMethodTransaction::ChangeToDirectMethodTransaction(int id, std::string bank, int account) :
    ChangeMethodTransaction(id),
    bank(bank),
    account(account)
{}

std::shared_ptr<PaymentMethod> ChangeToDirectMethodTransaction::getPaymentMethod() const
{
    return std::make_shared<DirectMethod>(bank, account);
}

ChangeToMailMethodTransaction::ChangeToMailMethodTransaction(int id, std::string address) :
    ChangeMethodTransaction(id),
    address(address)
{}

std::shared_ptr<PaymentMethod> ChangeToMailMethodTransaction::getPaymentMethod() const
{
    return std::make_shared<MailMethod>(address);
}

ChangeToHoldMethodTransaction::ChangeToHoldMethodTransaction(int id) :
    ChangeMethodTransaction(id)
{}

std::shared_ptr<PaymentMethod> ChangeToHoldMethodTransaction::getPaymentMethod() const
{
    return std::make_shared<HoldMethod>();
}

void ChangeAffiliationTransaction::change(std::shared_ptr<Employee> employee)
{
    recordMembership(employee);
    employee->setAffiliation(getAffiliation());
}

ChangeToUnionAffiliationTransaction::ChangeToUnionAffiliationTransaction(int id, int memberId) :
    ChangeAffiliationTransaction(id),
    memberId(memberId)
{}

std::shared_ptr<Affiliation> ChangeToUnionAffiliationTransaction::getAffiliation() const
{
    return std::make_shared<UnionAffiliation>(memberId);
}

void ChangeToUnionAffiliationTransaction::recordMembership(std::shared_ptr<Employee> employee)
{
    PayrollDatabase::getInstance()->addUnionMember(memberId, id);
}

ChangeToNoAffiliationTransaction::ChangeToNoAffiliationTransaction(int id) :
    ChangeAffiliationTransaction(id)
{}

std::shared_ptr<Affiliation> ChangeToNoAffiliationTransaction::getAffiliation() const
{
    return std::make_shared<NoAffiliation>();
}

void ChangeToNoAffiliationTransaction::recordMembership(std::shared_ptr<Employee> employee)
{
    auto affiliation = employee->getAffiliation();
    if (auto uaffiliation = std::dynamic_pointer_cast<UnionAffiliation>(affiliation))
    {
        int memberId = uaffiliation->getMemberId();
        PayrollDatabase::getInstance()->removeUnionMember(memberId);
    }
}
