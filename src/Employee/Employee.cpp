#include "Employee.hpp"

Employee::Employee(int id, std::string name, std::string address) :
        id(id),
        name(std::move(name)),
        address(std::move(address)),
        affiliation(new NoAffiliation())
{}

bool Employee::isPayDate(Date date) const
{
    return false;
}

void Employee::payday(std::shared_ptr<Paycheck> paycheck)
{

}