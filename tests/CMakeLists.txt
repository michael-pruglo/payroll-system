project(google_test)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${payroll_system_SOURCE_DIR})

add_executable(google_test test.cpp DatabaseTest.cpp)
target_link_libraries(google_test gtest gtest_main)