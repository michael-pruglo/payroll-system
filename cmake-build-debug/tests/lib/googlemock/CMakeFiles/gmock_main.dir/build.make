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
include tests/lib/googlemock/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include tests/lib/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make

tests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj: tests/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make
tests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj: tests/lib/googlemock/CMakeFiles/gmock_main.dir/includes_CXX.rsp
tests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj: ../tests/lib/googlemock/src/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock && C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gmock_main.dir\src\gmock_main.cc.obj -c C:\Users\mickl\ClionProjects\payroll-system\tests\lib\googlemock\src\gmock_main.cc

tests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mickl\ClionProjects\payroll-system\tests\lib\googlemock\src\gmock_main.cc > CMakeFiles\gmock_main.dir\src\gmock_main.cc.i

tests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mickl\ClionProjects\payroll-system\tests\lib\googlemock\src\gmock_main.cc -o CMakeFiles\gmock_main.dir\src\gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_maind.a: tests/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.obj
lib/libgmock_maind.a: tests/lib/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_maind.a: tests/lib/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\..\lib\libgmock_maind.a"
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock_main.dir\cmake_clean_target.cmake
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gmock_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/lib/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_maind.a

.PHONY : tests/lib/googlemock/CMakeFiles/gmock_main.dir/build

tests/lib/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /d C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock && $(CMAKE_COMMAND) -P CMakeFiles\gmock_main.dir\cmake_clean.cmake
.PHONY : tests/lib/googlemock/CMakeFiles/gmock_main.dir/clean

tests/lib/googlemock/CMakeFiles/gmock_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mickl\ClionProjects\payroll-system C:\Users\mickl\ClionProjects\payroll-system\tests\lib\googlemock C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock C:\Users\mickl\ClionProjects\payroll-system\cmake-build-debug\tests\lib\googlemock\CMakeFiles\gmock_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/lib/googlemock/CMakeFiles/gmock_main.dir/depend

