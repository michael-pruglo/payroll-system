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
