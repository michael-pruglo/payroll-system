cmake_minimum_required(VERSION 3.16)
project(payroll_system)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(tests)

add_executable(payroll_system src/main.cpp src/Transactions/Transaction.hpp src/Employee/Employee.hpp src/PayrollDatabase.cpp src/PayrollDatabase.hpp src/Transactions/AddEmployeeTransaction.cpp src/Transactions/AddEmployeeTransaction.hpp src/Transactions/DeleteEmployeeTransaction.hpp src/Transactions/TimeCardTransaction.cpp src/Transactions/TimeCardTransaction.hpp src/Employee/PaymentClassification.hpp src/Employee/PaymentSchedule.hpp src/Employee/PaymentMethod.hpp)