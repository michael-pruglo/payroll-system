# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mickl\ClionProjects\payroll-system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/google_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/google_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/google_test.dir/flags.make

tests/CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.obj: ../tests/Database/DatabaseTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Database\DatabaseTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Database\DatabaseTest.cpp

tests/CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Database\DatabaseTest.cpp > CMakeFiles\google_test.dir\Database\DatabaseTest.cpp.i

tests/CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Database\DatabaseTest.cpp -o CMakeFiles\google_test.dir\Database\DatabaseTest.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.obj: ../tests/Transactions/AddEmployeeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\AddEmployeeTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\AddEmployeeTest.cpp

tests/CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\AddEmployeeTest.cpp > CMakeFiles\google_test.dir\Transactions\AddEmployeeTest.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\AddEmployeeTest.cpp -o CMakeFiles\google_test.dir\Transactions\AddEmployeeTest.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.obj: ../tests/Transactions/DeleteEmployeeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\DeleteEmployeeTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\DeleteEmployeeTest.cpp

tests/CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\DeleteEmployeeTest.cpp > CMakeFiles\google_test.dir\Transactions\DeleteEmployeeTest.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\DeleteEmployeeTest.cpp -o CMakeFiles\google_test.dir\Transactions\DeleteEmployeeTest.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.obj: ../tests/Transactions/TimeCardTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\TimeCardTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\TimeCardTest.cpp

tests/CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\TimeCardTest.cpp > CMakeFiles\google_test.dir\Transactions\TimeCardTest.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\TimeCardTest.cpp -o CMakeFiles\google_test.dir\Transactions\TimeCardTest.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.obj: ../tests/Transactions/utility/EmployeeCorrectnessTester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\utility\EmployeeCorrectnessTester.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\utility\EmployeeCorrectnessTester.cpp

tests/CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\utility\EmployeeCorrectnessTester.cpp > CMakeFiles\google_test.dir\Transactions\utility\EmployeeCorrectnessTester.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\utility\EmployeeCorrectnessTester.cpp -o CMakeFiles\google_test.dir\Transactions\utility\EmployeeCorrectnessTester.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.obj: ../tests/Transactions/SalesReceipt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\SalesReceipt.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\SalesReceipt.cpp

tests/CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\SalesReceipt.cpp > CMakeFiles\google_test.dir\Transactions\SalesReceipt.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\SalesReceipt.cpp -o CMakeFiles\google_test.dir\Transactions\SalesReceipt.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.obj: ../tests/Transactions/ServiceChargeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\ServiceChargeTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\ServiceChargeTest.cpp

tests/CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\ServiceChargeTest.cpp > CMakeFiles\google_test.dir\Transactions\ServiceChargeTest.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\ServiceChargeTest.cpp -o CMakeFiles\google_test.dir\Transactions\ServiceChargeTest.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.obj: ../tests/Transactions/ChangeEmployeeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\ChangeEmployeeTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\ChangeEmployeeTest.cpp

tests/CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\ChangeEmployeeTest.cpp > CMakeFiles\google_test.dir\Transactions\ChangeEmployeeTest.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\ChangeEmployeeTest.cpp -o CMakeFiles\google_test.dir\Transactions\ChangeEmployeeTest.cpp.s

tests/CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.obj: ../tests/Transactions/PaydayTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object tests/CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\Transactions\PaydayTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\PaydayTest.cpp

tests/CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\PaydayTest.cpp > CMakeFiles\google_test.dir\Transactions\PaydayTest.cpp.i

tests/CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\Transactions\PaydayTest.cpp -o CMakeFiles\google_test.dir\Transactions\PaydayTest.cpp.s

tests/CMakeFiles/google_test.dir/DateTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/DateTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/DateTest.cpp.obj: ../tests/DateTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object tests/CMakeFiles/google_test.dir/DateTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\DateTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\DateTest.cpp

tests/CMakeFiles/google_test.dir/DateTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/DateTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\DateTest.cpp > CMakeFiles\google_test.dir\DateTest.cpp.i

tests/CMakeFiles/google_test.dir/DateTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/DateTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\DateTest.cpp -o CMakeFiles\google_test.dir\DateTest.cpp.s

tests/CMakeFiles/google_test.dir/EmployeeFactory.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/EmployeeFactory.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/EmployeeFactory.cpp.obj: ../tests/EmployeeFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object tests/CMakeFiles/google_test.dir/EmployeeFactory.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\EmployeeFactory.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\EmployeeFactory.cpp

tests/CMakeFiles/google_test.dir/EmployeeFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/EmployeeFactory.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\EmployeeFactory.cpp > CMakeFiles\google_test.dir\EmployeeFactory.cpp.i

tests/CMakeFiles/google_test.dir/EmployeeFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/EmployeeFactory.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\EmployeeFactory.cpp -o CMakeFiles\google_test.dir\EmployeeFactory.cpp.s

tests/CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.obj: tests/CMakeFiles/google_test.dir/flags.make
tests/CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.obj: tests/CMakeFiles/google_test.dir/includes_CXX.rsp
tests/CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.obj: ../tests/EmployeeFactoryTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object tests/CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\google_test.dir\EmployeeFactoryTest.cpp.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\EmployeeFactoryTest.cpp

tests/CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\EmployeeFactoryTest.cpp > CMakeFiles\google_test.dir\EmployeeFactoryTest.cpp.i

tests/CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\EmployeeFactoryTest.cpp -o CMakeFiles\google_test.dir\EmployeeFactoryTest.cpp.s

# Object files for target google_test
google_test_OBJECTS = \
"CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.obj" \
"CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.obj" \
"CMakeFiles/google_test.dir/DateTest.cpp.obj" \
"CMakeFiles/google_test.dir/EmployeeFactory.cpp.obj" \
"CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.obj"

# External object files for target google_test
google_test_EXTERNAL_OBJECTS =

tests/google_test.exe: tests/CMakeFiles/google_test.dir/Database/DatabaseTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/AddEmployeeTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/DeleteEmployeeTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/TimeCardTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/utility/EmployeeCorrectnessTester.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/SalesReceipt.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/ServiceChargeTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/ChangeEmployeeTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/Transactions/PaydayTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/DateTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/EmployeeFactory.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/EmployeeFactoryTest.cpp.obj
tests/google_test.exe: tests/CMakeFiles/google_test.dir/build.make
tests/google_test.exe: lib/libgtestd.a
tests/google_test.exe: lib/libgtest_maind.a
tests/google_test.exe: lib/libgtestd.a
tests/google_test.exe: tests/CMakeFiles/google_test.dir/linklibs.rsp
tests/google_test.exe: tests/CMakeFiles/google_test.dir/objects1.rsp
tests/google_test.exe: tests/CMakeFiles/google_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable google_test.exe"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\google_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/google_test.dir/build: tests/google_test.exe

.PHONY : tests/CMakeFiles/google_test.dir/build

tests/CMakeFiles/google_test.dir/clean:
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests && $(CMAKE_COMMAND) -P CMakeFiles\google_test.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/google_test.dir/clean

tests/CMakeFiles/google_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mickl\ClionProjects\payroll-system C:\Users\mickl\ClionProjects\payroll-system\tests C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\CMakeFiles\google_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/google_test.dir/depend

