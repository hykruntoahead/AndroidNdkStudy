# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build

# Include any dependencies generated for this target.
include src/CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/hello.dir/flags.make

src/CMakeFiles/hello.dir/main.c.o: src/CMakeFiles/hello.dir/flags.make
src/CMakeFiles/hello.dir/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/hello.dir/main.c.o"
	cd /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hello.dir/main.c.o   -c /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/src/main.c

src/CMakeFiles/hello.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello.dir/main.c.i"
	cd /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/src/main.c > CMakeFiles/hello.dir/main.c.i

src/CMakeFiles/hello.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello.dir/main.c.s"
	cd /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/src/main.c -o CMakeFiles/hello.dir/main.c.s

src/CMakeFiles/hello.dir/main.c.o.requires:

.PHONY : src/CMakeFiles/hello.dir/main.c.o.requires

src/CMakeFiles/hello.dir/main.c.o.provides: src/CMakeFiles/hello.dir/main.c.o.requires
	$(MAKE) -f src/CMakeFiles/hello.dir/build.make src/CMakeFiles/hello.dir/main.c.o.provides.build
.PHONY : src/CMakeFiles/hello.dir/main.c.o.provides

src/CMakeFiles/hello.dir/main.c.o.provides.build: src/CMakeFiles/hello.dir/main.c.o


# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/main.c.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

bin/hello: src/CMakeFiles/hello.dir/main.c.o
bin/hello: src/CMakeFiles/hello.dir/build.make
bin/hello: lib/libhello.so
bin/hello: src/CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/hello"
	cd /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/hello.dir/build: bin/hello

.PHONY : src/CMakeFiles/hello.dir/build

src/CMakeFiles/hello.dir/requires: src/CMakeFiles/hello.dir/main.c.o.requires

.PHONY : src/CMakeFiles/hello.dir/requires

src/CMakeFiles/hello.dir/clean:
	cd /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/src && $(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/hello.dir/clean

src/CMakeFiles/hello.dir/depend:
	cd /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6 /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/src /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/src /home/hyk/AndroidStudioProjects/AndroidNdkStudy/CMake/cmake_demo/demo6/build/src/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/hello.dir/depend

