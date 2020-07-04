#include "AddEmployeeTransaction.hpp"
#include "PayrollDatabase.hpp"

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
    e->setPaymentMethod(std::make_shared<Employee::HoldMethod>());

    PayrollDatabase::getInstance()->addEmployee(id, e);
}




AddHourlyEmployee::AddHourlyEmployee(int id, std::string name, std::string address, double hourlyRate) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    hourlyRate(hourlyRate)
{
}

std::shared_ptr<Employee::PaymentClassification> AddHourlyEmployee::getPaymentClassification() const
{
    return std::make_shared<Employee::HourlyClassification>(hourlyRate);
}

std::shared_ptr<Employee::PaymentSchedule> AddHourlyEmployee::getPaymentSchedule() const
{
    return std::make_shared<Employee::WeeklySchedule>();
}

AddSalariedEmployee::AddSalariedEmployee(int id, std::string name, std::string address, double salary) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    salary(salary)
{
}

std::shared_ptr<Employee::PaymentClassification> AddSalariedEmployee::getPaymentClassification() const
{
    return std::make_shared<Employee::SalariedClassification>(salary);
}

std::shared_ptr<Employee::PaymentSchedule> AddSalariedEmployee::getPaymentSchedule() const
{
    return std::make_shared<Employee::MonthlySchedule>();
}

AddCommissionedEmployee::AddCommissionedEmployee(int id, std::string name, std::string address,
                                                 double salary, double commissionRate) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    salary(salary),
    comissionRate(commissionRate)
{
}

std::shared_ptr<Employee::PaymentClassification> AddCommissionedEmployee::getPaymentClassification() const
{
    return std::make_shared<Employee::CommissionedClassification>(salary, comissionRate);
}

std::shared_ptr<Employee::PaymentSchedule> AddCommissionedEmployee::getPaymentSchedule() const
{
    return std::make_shared<Employee::BiweeklySchedule>();
}
