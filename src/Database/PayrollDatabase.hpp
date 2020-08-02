#ifndef PAYROLL_SYSTEM_PAYROLLDATABASE_HPP
#define PAYROLL_SYSTEM_PAYROLLDATABASE_HPP


#include <unordered_map>
#include <stdexcept>
#include <memory>
#include <sstream>
#include "../Employee/Employee.hpp"

class PayrollDatabase
{
public:
    virtual ~PayrollDatabase() = default;

    void                        addEmployee(int id, std::shared_ptr<Employee> employee);
    std::shared_ptr<Employee>   getEmployee(int id) const;
    std::vector<int>            getAllIds() const;
    void                        updateEmployee(int id, std::shared_ptr<Employee> newEmployee);
    void                        deleteEmployee(int id);
    auto                        size() const { return database.size(); }
    void                        clear() { database.clear(); unionMembershipDatabase.clear(); }

    void                        addUnionMember(int memberId, int empId);
    int                         getIdByUnionMemberId(int memberId);
    void                        removeUnionMember(int memberId);

public: //exceptions
    class not_found;
    class add_duplicate;


private:
    std::unordered_map<int, std::shared_ptr<Employee>> database;
    std::unordered_map<int, int> unionMembershipDatabase;

    //Singleton
private:
    PayrollDatabase() = default;
public:
    PayrollDatabase(PayrollDatabase& other) = delete;
    void operator=(const PayrollDatabase& other) = delete;
    static std::shared_ptr<PayrollDatabase> getInstance();
};

class PayrollDatabase::not_found : public std::runtime_error
{
public:
    explicit not_found(int id) :
        std::runtime_error("Payroll Database: not_found id = "+std::to_string(id))
    {}
};
class PayrollDatabase::add_duplicate : public std::runtime_error
{
public:
    explicit add_duplicate(int id) :
        std::runtime_error("Payroll Database: add_duplicate id = "+std::to_string(id))
    {}
};


#endif //PAYROLL_SYSTEM_PAYROLLDATABASE_HPP
