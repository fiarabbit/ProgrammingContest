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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/A.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A.out.dir/flags.make

CMakeFiles/A.out.dir/A.cpp.obj: CMakeFiles/A.out.dir/flags.make
CMakeFiles/A.out.dir/A.cpp.obj: CMakeFiles/A.out.dir/includes_CXX.rsp
CMakeFiles/A.out.dir/A.cpp.obj: ../A.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A.out.dir/A.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\A.out.dir\A.cpp.obj -c C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\A.cpp

CMakeFiles/A.out.dir/A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A.out.dir/A.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\A.cpp > CMakeFiles\A.out.dir\A.cpp.i

CMakeFiles/A.out.dir/A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A.out.dir/A.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\A.cpp -o CMakeFiles\A.out.dir\A.cpp.s

CMakeFiles/A.out.dir/A.cpp.obj.requires:

.PHONY : CMakeFiles/A.out.dir/A.cpp.obj.requires

CMakeFiles/A.out.dir/A.cpp.obj.provides: CMakeFiles/A.out.dir/A.cpp.obj.requires
	$(MAKE) -f CMakeFiles\A.out.dir\build.make CMakeFiles/A.out.dir/A.cpp.obj.provides.build
.PHONY : CMakeFiles/A.out.dir/A.cpp.obj.provides

CMakeFiles/A.out.dir/A.cpp.obj.provides.build: CMakeFiles/A.out.dir/A.cpp.obj


# Object files for target A.out
A_out_OBJECTS = \
"CMakeFiles/A.out.dir/A.cpp.obj"

# External object files for target A.out
A_out_EXTERNAL_OBJECTS =

A.out.exe: CMakeFiles/A.out.dir/A.cpp.obj
A.out.exe: CMakeFiles/A.out.dir/build.make
A.out.exe: CMakeFiles/A.out.dir/linklibs.rsp
A.out.exe: CMakeFiles/A.out.dir/objects1.rsp
A.out.exe: CMakeFiles/A.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A.out.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\A.out.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A.out.dir/build: A.out.exe

.PHONY : CMakeFiles/A.out.dir/build

CMakeFiles/A.out.dir/requires: CMakeFiles/A.out.dir/A.cpp.obj.requires

.PHONY : CMakeFiles/A.out.dir/requires

CMakeFiles/A.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\A.out.dir\cmake_clean.cmake
.PHONY : CMakeFiles/A.out.dir/clean

CMakeFiles/A.out.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021 C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021 C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\cmake-build-release C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\cmake-build-release C:\Users\hashimoto\CLionProjects\ProgrammingContest\agc021\cmake-build-release\CMakeFiles\A.out.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A.out.dir/depend

