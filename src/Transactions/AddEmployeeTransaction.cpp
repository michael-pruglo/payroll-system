#include "AddEmployeeTransaction.hpp"
#include "../PayrollDatabase.hpp"

AddEmployeeTransaction::AddEmployeeTransaction(int id, std::string name, std::string address) :
    id(id),
    name(std::move(name)),
    address(std::move(address))
{
}

void AddEmployeeTransaction::execute()
{
    std::shared_ptr<Employee> e { new Employee(id, name, address) };
    e->setPaymentClassification(getPaymentClassification());
    e->setPaymentSchedule(getPaymentSchedule());
    e->setPaymentMethod(std::make_shared<HoldMethod>());

    PayrollDatabase::getInstance()->addEmployee(id, e);
}




AddHourlyEmployee::AddHourlyEmployee(int id, std::string name, std::string address, double hourlyRate) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    hourlyRate(hourlyRate)
{
}

std::shared_ptr<PaymentClassification> AddHourlyEmployee::getPaymentClassification() const
{
    return std::make_shared<HourlyClassification>(hourlyRate);
}

std::shared_ptr<PaymentSchedule> AddHourlyEmployee::getPaymentSchedule() const
{
    return std::make_shared<WeeklySchedule>();
}

AddSalariedEmployee::AddSalariedEmployee(int id, std::string name, std::string address, double salary) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    salary(salary)
{
}

std::shared_ptr<PaymentClassification> AddSalariedEmployee::getPaymentClassification() const
{
    return std::make_shared<SalariedClassification>(salary);
}

std::shared_ptr<PaymentSchedule> AddSalariedEmployee::getPaymentSchedule() const
{
    return std::make_shared<MonthlySchedule>();
}

AddCommissionedEmployee::AddCommissionedEmployee(int id, std::string name, std::string address,
                                                 double salary, double commissionRate) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    salary(salary),
    comissionRate(commissionRate)
{
}

std::shared_ptr<PaymentClassification> AddCommissionedEmployee::getPaymentClassification() const
{
    return std::make_shared<CommissionedClassification>(salary, comissionRate);
}

std::shared_ptr<PaymentSchedule> AddCommissionedEmployee::getPaymentSchedule() const
{
    return std::make_shared<BiweeklySchedule>();
}
