project(google_test)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${payroll_system_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "--coverage")

add_executable(google_test DatabaseTest.cpp AddEmployeeTest.cpp DeleteEmployeeTest.cpp TimeCardTest.cpp AddAndRetrieveEmployeeTester.hpp)
target_link_libraries(google_test gtest gtest_main)