#include "EmployeeFactory.hpp"

namespace 
{
    std::string rstring() { int len = rand()%10; std::string res(len, ' '); for (int i = 0; i < len; ++i) res[i]=char(rand()%26+'a'); return res; }
    int rint() { return rand()%1000; }
    double rdouble() { return rint()/100.0; }
    Date rdate() { return Date(1990+rand()%121, rand()%12+1, rand()%28+1); }
}

EmployeeFactory::EmployeeFactory(int seed) : date(0,0,0)
{
    srand(seed);
    id = rint();
    name = rstring();
    address = rstring();
    hRate = rdouble();
    sSalary = rdouble();
    cSalary = rdouble();
    cRate = rdouble();
    date = rdate();
    amount = rdouble();
    hours = rdouble();
}
