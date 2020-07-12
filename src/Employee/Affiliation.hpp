#ifndef PAYROLL_SYSTEM_AFFILIATION_HPP
#define PAYROLL_SYSTEM_AFFILIATION_HPP


#include <vector>
#include "ServiceCharge.hpp"

class Affiliation
{
public:
    virtual ~Affiliation() = default;
    virtual void addServiceCharge(ServiceCharge serviceCharge) = 0;
    virtual std::vector<ServiceCharge> getServiceCharges() const = 0;
};

class NoAffiliation : public Affiliation
{
public:
    void addServiceCharge(ServiceCharge serviceCharge) override {}
    std::vector<ServiceCharge> getServiceCharges() const override { return {}; }
};
class UnionAffiliation : public Affiliation
{
public:
    void addServiceCharge(ServiceCharge serviceCharge) override
    {
        serviceCharges.push_back(serviceCharge);
    }

    std::vector<ServiceCharge> getServiceCharges() const override
    {
        return serviceCharges;
    }

private:
    double dues;
    std::vector<ServiceCharge> serviceCharges;
};

#endif //PAYROLL_SYSTEM_AFFILIATION_HPP