# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/Pulpit/Restaurant/start

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Pulpit/Restaurant/start/cmake-build-debug

# Include any dependencies generated for this target.
include library/CMakeFiles/LibraryTester.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include library/CMakeFiles/LibraryTester.dir/compiler_depend.make

# Include the progress variables for this target.
include library/CMakeFiles/LibraryTester.dir/progress.make

# Include the compile flags for this target's objects.
include library/CMakeFiles/LibraryTester.dir/flags.make

library/CMakeFiles/LibraryTester.dir/test/master.cpp.o: library/CMakeFiles/LibraryTester.dir/flags.make
library/CMakeFiles/LibraryTester.dir/test/master.cpp.o: /home/student/Pulpit/Restaurant/start/library/test/master.cpp
library/CMakeFiles/LibraryTester.dir/test/master.cpp.o: library/CMakeFiles/LibraryTester.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Pulpit/Restaurant/start/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object library/CMakeFiles/LibraryTester.dir/test/master.cpp.o"
	cd /home/student/Pulpit/Restaurant/start/cmake-build-debug/library && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/LibraryTester.dir/test/master.cpp.o -MF CMakeFiles/LibraryTester.dir/test/master.cpp.o.d -o CMakeFiles/LibraryTester.dir/test/master.cpp.o -c /home/student/Pulpit/Restaurant/start/library/test/master.cpp

library/CMakeFiles/LibraryTester.dir/test/master.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibraryTester.dir/test/master.cpp.i"
	cd /home/student/Pulpit/Restaurant/start/cmake-build-debug/library && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Pulpit/Restaurant/start/library/test/master.cpp > CMakeFiles/LibraryTester.dir/test/master.cpp.i

library/CMakeFiles/LibraryTester.dir/test/master.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibraryTester.dir/test/master.cpp.s"
	cd /home/student/Pulpit/Restaurant/start/cmake-build-debug/library && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Pulpit/Restaurant/start/library/test/master.cpp -o CMakeFiles/LibraryTester.dir/test/master.cpp.s

# Object files for target LibraryTester
LibraryTester_OBJECTS = \
"CMakeFiles/LibraryTester.dir/test/master.cpp.o"

# External object files for target LibraryTester
LibraryTester_EXTERNAL_OBJECTS =

library/LibraryTester: library/CMakeFiles/LibraryTester.dir/test/master.cpp.o
library/LibraryTester: library/CMakeFiles/LibraryTester.dir/build.make
library/LibraryTester: library/libLibrary.a
library/LibraryTester: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so.1.74.0
library/LibraryTester: library/CMakeFiles/LibraryTester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Pulpit/Restaurant/start/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LibraryTester"
	cd /home/student/Pulpit/Restaurant/start/cmake-build-debug/library && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LibraryTester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/CMakeFiles/LibraryTester.dir/build: library/LibraryTester
.PHONY : library/CMakeFiles/LibraryTester.dir/build

library/CMakeFiles/LibraryTester.dir/clean:
	cd /home/student/Pulpit/Restaurant/start/cmake-build-debug/library && $(CMAKE_COMMAND) -P CMakeFiles/LibraryTester.dir/cmake_clean.cmake
.PHONY : library/CMakeFiles/LibraryTester.dir/clean

library/CMakeFiles/LibraryTester.dir/depend:
	cd /home/student/Pulpit/Restaurant/start/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Pulpit/Restaurant/start /home/student/Pulpit/Restaurant/start/library /home/student/Pulpit/Restaurant/start/cmake-build-debug /home/student/Pulpit/Restaurant/start/cmake-build-debug/library /home/student/Pulpit/Restaurant/start/cmake-build-debug/library/CMakeFiles/LibraryTester.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : library/CMakeFiles/LibraryTester.dir/depend

