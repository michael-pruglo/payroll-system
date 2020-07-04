cmake_minimum_required(VERSION 3.16)
project(payroll_system)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(tests)

add_executable(payroll_system src/main.cpp src/Transaction.hpp src/Employee.cpp src/Employee.hpp src/PayrollDatabase.cpp src/PayrollDatabase.hpp src/AddEmployeeTransaction.cpp src/AddEmployeeTransaction.hpp src/DeleteEmployeeTransaction.hpp)