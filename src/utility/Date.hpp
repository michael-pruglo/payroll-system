#ifndef PAYROLL_SYSTEM_DATE_HPP
#define PAYROLL_SYSTEM_DATE_HPP


struct Date
{
    Date(int year, int month, int day) : year(year), month(month), day(day) {}

    int year, month, day;
};


#endif //PAYROLL_SYSTEM_DATE_HPP
