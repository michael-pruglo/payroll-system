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
    auto db = PayrollDatabase::getInstance();
    std::shared_ptr<Employee> e { new Employee(id, name, address) };
    e->setPaymentClassification(getPaymentClassification());
    e->setPaymentSchedule(getPaymentSchedule());
    e->setPaymentMethod(std::make_shared<Employee::HoldMethod>());
    db->addEmployee(id, e);
}




AddHourlyEmployee::AddHourlyEmployee(int id, std::string name, std::string address, double hourlyRate) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    hourlyRate(hourlyRate)
{
}

AddSalariedEmployee::AddSalariedEmployee(int id, std::string name, std::string address, double salary) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    salary(salary)
{
}

AddCommissionedEmployee::AddCommissionedEmployee(int id, std::string name, std::string address,
                                                 double salary, double commissionRate) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    salary(salary),
    comissionRate(commissionRate)
{
}
