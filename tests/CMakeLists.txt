project(google_test)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${payroll_system_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "--coverage")

add_executable(google_test Database/DatabaseTest.cpp Transactions/AddEmployeeTest.cpp Transactions/DeleteEmployeeTest.cpp Transactions/TimeCardTest.cpp Transactions/utility/EmployeeCorrectnessTester.hpp Transactions/utility/TestUsingDatabase.hpp Transactions/utility/EmployeeCorrectnessTester.cpp Transactions/SalesReceipt.cpp Transactions/ServiceChargeTest.cpp Transactions/ChangeEmployeeTest.cpp Transactions/PaydayTest.cpp DateTest.cpp EmployeeFactory.cpp EmployeeFactory.hpp EmployeeFactoryTest.cpp)
target_link_libraries(google_test gtest gtest_main)