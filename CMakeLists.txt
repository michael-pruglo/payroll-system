cmake_minimum_required(VERSION 3.16)
project(payroll_system)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(tests)

add_executable(payroll_system src/main.cpp)