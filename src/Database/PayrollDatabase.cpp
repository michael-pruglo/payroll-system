#include "PayrollDatabase.hpp"

#define EXECUTE_OPTION( CONTAINER, ELEM_TO_FIND, IF_CONTAINS, IF_DOESNT_CONTAIN ) \
    auto it = CONTAINER.find(ELEM_TO_FIND); \
    if (it == CONTAINER.end()) \
        IF_DOESNT_CONTAIN; \
    else \
        IF_CONTAINS;

#define DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND( FOO ) \
    EXECUTE_OPTION( database, id, FOO, throw not_found(id) )
#define UNION_DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND( FOO ) \
    EXECUTE_OPTION( unionMembershipDatabase, memberId, FOO, throw not_found(memberId) )

void PayrollDatabase::addEmployee(int id, std::shared_ptr<Employee> employee)
{
    if (database.contains(id))
        throw add_duplicate(id);
    else
        database.insert({id, employee});
}

std::shared_ptr<Employee> PayrollDatabase::getEmployee(int id) const
{
    DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(return it->second);
}

void PayrollDatabase::updateEmployee(int id, std::shared_ptr<Employee> newEmployee)
{
    DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(it->second = newEmployee);
}

void PayrollDatabase::deleteEmployee(int id)
{
    DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(database.erase(it));
}

void PayrollDatabase::addUnionMember(int memberId, int empId)
{
    if (unionMembershipDatabase.contains(memberId))
        throw add_duplicate(memberId);
    else
        unionMembershipDatabase.insert({memberId, empId});
}

int PayrollDatabase::getIdByUnionMemberId(int memberId)
{
    UNION_DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(return it->second);
}

void PayrollDatabase::removeUnionMember(int memberId)
{
    UNION_DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND(unionMembershipDatabase.erase(it));
}

#undef EXECUTE_OPTION
#undef DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND
#undef UNION_DB_IF_CONTAINS_EXECUTE_ELSE_THROW_NOT_FOUND

std::shared_ptr<PayrollDatabase> PayrollDatabase::getInstance()
{
    static std::shared_ptr<PayrollDatabase> _instance = nullptr;
    if (_instance == nullptr)
        _instance = std::shared_ptr<PayrollDatabase> {new PayrollDatabase()};
    return _instance;
}

std::vector<int> PayrollDatabase::getAllIds() const
{
    std::vector<int> res;
    res.reserve(database.size());
    for (const auto& [id, employee] : database)
        res.push_back(id);

    return res;
}
