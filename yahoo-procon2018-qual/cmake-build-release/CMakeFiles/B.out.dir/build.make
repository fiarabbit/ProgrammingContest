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
CMAKE_SOURCE_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/B.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B.out.dir/flags.make

CMakeFiles/B.out.dir/B.cpp.obj: CMakeFiles/B.out.dir/flags.make
CMakeFiles/B.out.dir/B.cpp.obj: CMakeFiles/B.out.dir/includes_CXX.rsp
CMakeFiles/B.out.dir/B.cpp.obj: ../B.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B.out.dir/B.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\B.out.dir\B.cpp.obj -c C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\B.cpp

CMakeFiles/B.out.dir/B.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B.out.dir/B.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\B.cpp > CMakeFiles\B.out.dir\B.cpp.i

CMakeFiles/B.out.dir/B.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B.out.dir/B.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\B.cpp -o CMakeFiles\B.out.dir\B.cpp.s

CMakeFiles/B.out.dir/B.cpp.obj.requires:

.PHONY : CMakeFiles/B.out.dir/B.cpp.obj.requires

CMakeFiles/B.out.dir/B.cpp.obj.provides: CMakeFiles/B.out.dir/B.cpp.obj.requires
	$(MAKE) -f CMakeFiles\B.out.dir\build.make CMakeFiles/B.out.dir/B.cpp.obj.provides.build
.PHONY : CMakeFiles/B.out.dir/B.cpp.obj.provides

CMakeFiles/B.out.dir/B.cpp.obj.provides.build: CMakeFiles/B.out.dir/B.cpp.obj


# Object files for target B.out
B_out_OBJECTS = \
"CMakeFiles/B.out.dir/B.cpp.obj"

# External object files for target B.out
B_out_EXTERNAL_OBJECTS =

B.out.exe: CMakeFiles/B.out.dir/B.cpp.obj
B.out.exe: CMakeFiles/B.out.dir/build.make
B.out.exe: CMakeFiles/B.out.dir/linklibs.rsp
B.out.exe: CMakeFiles/B.out.dir/objects1.rsp
B.out.exe: CMakeFiles/B.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B.out.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\B.out.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B.out.dir/build: B.out.exe

.PHONY : CMakeFiles/B.out.dir/build

CMakeFiles/B.out.dir/requires: CMakeFiles/B.out.dir/B.cpp.obj.requires

.PHONY : CMakeFiles/B.out.dir/requires

CMakeFiles/B.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\B.out.dir\cmake_clean.cmake
.PHONY : CMakeFiles/B.out.dir/clean

CMakeFiles/B.out.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\cmake-build-release C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\cmake-build-release C:\Users\hashimoto\CLionProjects\ProgrammingContest\yahoo-procon2018-qual\cmake-build-release\CMakeFiles\B.out.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B.out.dir/depend

