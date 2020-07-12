cmake_minimum_required(VERSION 3.16)
project(payroll_system)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(tests)

add_executable(payroll_system src/main.cpp src/Transactions/Transaction.hpp src/Employee/Employee.hpp src/Database/PayrollDatabase.cpp src/Database/PayrollDatabase.hpp src/Transactions/AddEmployeeTransaction.cpp src/Transactions/AddEmployeeTransaction.hpp src/Transactions/DeleteEmployeeTransaction.hpp src/Transactions/TimeCardTransaction.hpp src/Employee/PaymentClassification.hpp src/Employee/PaymentSchedule.hpp src/Employee/PaymentMethod.hpp src/utility/Date.hpp src/Employee/TimeCard.hpp src/Transactions/SalesReceiptTransaction.hpp src/Employee/SalesReceipt.hpp src/Employee/PaymentClassification.cpp src/Transactions/ServiceChargeTransaction.hpp src/Employee/ServiceCharge.hpp src/Employee/Affiliation.hpp src/Transactions/ChangeEmployeeTransaction.cpp src/Transactions/ChangeEmployeeTransaction.hpp)