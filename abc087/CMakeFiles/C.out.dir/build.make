# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087

# Include any dependencies generated for this target.
include CMakeFiles/C.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C.out.dir/flags.make

CMakeFiles/C.out.dir/C.cpp.obj: CMakeFiles/C.out.dir/flags.make
CMakeFiles/C.out.dir/C.cpp.obj: CMakeFiles/C.out.dir/includes_CXX.rsp
CMakeFiles/C.out.dir/C.cpp.obj: C.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C.out.dir/C.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\C.out.dir\C.cpp.obj -c C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087\C.cpp

CMakeFiles/C.out.dir/C.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C.out.dir/C.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087\C.cpp > CMakeFiles\C.out.dir\C.cpp.i

CMakeFiles/C.out.dir/C.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C.out.dir/C.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087\C.cpp -o CMakeFiles\C.out.dir\C.cpp.s

CMakeFiles/C.out.dir/C.cpp.obj.requires:

.PHONY : CMakeFiles/C.out.dir/C.cpp.obj.requires

CMakeFiles/C.out.dir/C.cpp.obj.provides: CMakeFiles/C.out.dir/C.cpp.obj.requires
	$(MAKE) -f CMakeFiles\C.out.dir\build.make CMakeFiles/C.out.dir/C.cpp.obj.provides.build
.PHONY : CMakeFiles/C.out.dir/C.cpp.obj.provides

CMakeFiles/C.out.dir/C.cpp.obj.provides.build: CMakeFiles/C.out.dir/C.cpp.obj


# Object files for target C.out
C_out_OBJECTS = \
"CMakeFiles/C.out.dir/C.cpp.obj"

# External object files for target C.out
C_out_EXTERNAL_OBJECTS =

C.out.exe: CMakeFiles/C.out.dir/C.cpp.obj
C.out.exe: CMakeFiles/C.out.dir/build.make
C.out.exe: CMakeFiles/C.out.dir/linklibs.rsp
C.out.exe: CMakeFiles/C.out.dir/objects1.rsp
C.out.exe: CMakeFiles/C.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C.out.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C.out.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C.out.dir/build: C.out.exe

.PHONY : CMakeFiles/C.out.dir/build

CMakeFiles/C.out.dir/requires: CMakeFiles/C.out.dir/C.cpp.obj.requires

.PHONY : CMakeFiles/C.out.dir/requires

CMakeFiles/C.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C.out.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C.out.dir/clean

CMakeFiles/C.out.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087 C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087 C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087 C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087 C:\Users\hashimoto\CLionProjects\ProgrammingContest\abc087\CMakeFiles\C.out.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C.out.dir/depend

