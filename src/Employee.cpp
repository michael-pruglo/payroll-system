#include "Employee.hpp"

Employee::Employee(int id, std::string name, std::string address) :
        id(id),
        name(std::move(name)),
        address(std::move(address))
{}