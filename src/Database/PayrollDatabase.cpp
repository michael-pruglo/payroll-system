#include "PayrollDatabase.hpp"

#define EXECUTE_OPTION( CONTAINER, ELEM_TO_FIND, IF_CONTAINS, IF_DOESNT_CONTAIN ) \
    auto it = CONTAINER.find(ELEM_TO_FIND); \
    if (it == CONTAINER.end()) \
        IF_DOESNT_CONTAIN; \
    else \
        IF_CONTAINS;

#define IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND( FOO ) EXECUTE_OPTION( database, id, FOO, throw not_found(id) )

void PayrollDatabase::addEmployee(int id, std::shared_ptr<Employee> employee)
{
    if(database.contains(id))
        throw add_duplicate(id);
    else
        database.insert({id, employee});
}

std::shared_ptr<Employee> PayrollDatabase::getEmployee(int id) const
{
    IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(return it->second);
}

void PayrollDatabase::updateEmployee(int id, std::shared_ptr<Employee> newEmployee)
{
    IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(it->second = newEmployee);
}

void PayrollDatabase::deleteEmployee(int id)
{
    IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(database.erase(it));
}

#undef EXECUTE_OPTION
#undef IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND


std::shared_ptr<PayrollDatabase> PayrollDatabase::_instance = nullptr;

std::shared_ptr<PayrollDatabase> PayrollDatabase::getInstance()
{
    if (_instance == nullptr)
        _instance = std::shared_ptr<PayrollDatabase> {new PayrollDatabase()};
    return _instance;
}
