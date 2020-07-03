#include "AddEmployeeTransaction.hpp"

AddEmployeeTransaction::AddEmployeeTransaction(int id, std::string name, std::string address) :
    id(id),
    name(std::move(name)),
    address(std::move(address))
{
}

void AddEmployeeTransaction::execute()
{

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

AddComissionedEmployee::AddComissionedEmployee(int id, std::string name, std::string address,
                                               double salary, double comissionRate) :
    AddEmployeeTransaction(id, std::move(name), std::move(address)),
    salary(salary),
    comissionRate(comissionRate)
{
}
