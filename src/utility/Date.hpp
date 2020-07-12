#ifndef PAYROLL_SYSTEM_DATE_HPP
#define PAYROLL_SYSTEM_DATE_HPP


struct Date
{
    Date(int year, int month, int day) : year(year), month(month), day(day) {}

    int year, month, day;
};

inline bool operator<(Date d1, Date d2)
{
    return d1.year<d2.year || d1.month<d2.month || d1.day<d2.day;
}
inline bool operator==(Date d1, Date d2)
{
    return d1.year==d2.year && d1.month==d2.month && d1.day==d2.day;
}


#endif //PAYROLL_SYSTEM_DATE_HPP
