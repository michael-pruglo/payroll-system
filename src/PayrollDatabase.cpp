#include "PayrollDatabase.hpp"

#define EXECUTE_OPTION( IF_CONTAINS, IF_DOESNT_CONTAIN ) \
    auto it = database.find(id); \
    if (it == database.end()) \
        IF_DOESNT_CONTAIN; \
    else \
        IF_CONTAINS;
#define IF_CONTAINS_EXECUTE_ELSE_THROW( FOO ) EXECUTE_OPTION( FOO, throw not_found(id) )

void PayrollDatabase::addEmployee(int id, std::shared_ptr<Employee> employee)
{
    EXECUTE_OPTION(throw add_duplicate(id), database.insert({id, employee}));
}

std::shared_ptr<Employee> PayrollDatabase::getEmployee(int id) const
{
    IF_CONTAINS_EXECUTE_ELSE_THROW(return it->second);
}

void PayrollDatabase::updateEmployee(int id, std::shared_ptr<Employee> newEmployee)
{
    IF_CONTAINS_EXECUTE_ELSE_THROW(it->second = newEmployee);
}

void PayrollDatabase::deleteEmployee(int id)
{
    IF_CONTAINS_EXECUTE_ELSE_THROW(database.erase(it));
}

#undef EXECUTE_OPTION
#undef IF_CONTAINS_EXECUTE_ELSE_THROW


std::shared_ptr<PayrollDatabase> PayrollDatabase::_instance = nullptr;

std::shared_ptr<PayrollDatabase> PayrollDatabase::getInstance()
{
    if (_instance == nullptr)
        _instance = std::shared_ptr<PayrollDatabase> {new PayrollDatabase()};
    return _instance;
}
