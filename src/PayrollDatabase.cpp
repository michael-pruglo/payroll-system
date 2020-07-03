#include "PayrollDatabase.hpp"

#define EXECUTE_OPTION( IF_CONTAINS, IF_DOESNT_CONTAIN ) \
    auto it = database.find(id); \
    if (it == database.end()) \
        IF_DOESNT_CONTAIN; \
    else \
        IF_CONTAINS;
#define IF_CONTAINS_EXECUTE_ELSE_THROW( FOO ) EXECUTE_OPTION( FOO, throw not_found() )

void PayrollDatabase::addEmployee(int id, Employee *employee)
{
    EXECUTE_OPTION(throw add_duplicate(), database.insert({id, employee}));
}

Employee *PayrollDatabase::getEmployee(int id) const
{
    IF_CONTAINS_EXECUTE_ELSE_THROW(return it->second);
}

void PayrollDatabase::updateEmployee(int id, Employee *newEmployee)
{
    IF_CONTAINS_EXECUTE_ELSE_THROW(it->second = newEmployee);
}

void PayrollDatabase::deleteEmployee(int id)
{
    IF_CONTAINS_EXECUTE_ELSE_THROW(database.erase(it));
}

#undef EXECUTE_OPTION
#undef IF_CONTAINS_EXECUTE_ELSE_THROW
