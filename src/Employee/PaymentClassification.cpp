#include <stdexcept>
#include "PaymentClassification.hpp"

#define EXECUTE_OPTION( CONTAINER, ELEM_TO_FIND, IF_CONTAINS, IF_DOESNT_CONTAIN ) \
    auto it = CONTAINER.find(ELEM_TO_FIND); \
    if (it == CONTAINER.end()) \
        IF_DOESNT_CONTAIN; \
    else \
        IF_CONTAINS;

TimeCard HourlyClassification::getTimeCard(Date date) const
{
    EXECUTE_OPTION(timeCards, date,
        return it->second,
        throw std::runtime_error("HourlyClassification::getTimeCard() - doesn't have such a timecard")
    )
}

SalesReceipt CommissionedClassification::getSalesReceipt(Date date) const
{
    EXECUTE_OPTION(salesReceipts, date,
       return it->second,
       throw std::runtime_error("CommissionedClassification::getSalesReceipt() - doesn't have such a receipt")
    )
}

#undef EXECUTE_OPTION