# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hashimoto\CLionProjects\ProgrammingContest

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	"C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\hashimoto\CLionProjects\ProgrammingContest\CMakeFiles C:\Users\hashimoto\CLionProjects\ProgrammingContest\CMakeFiles\progress.marks
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\hashimoto\CLionProjects\ProgrammingContest\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named A.out

# Build rule for target.
A.out: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 A.out
.PHONY : A.out

# fast build rule for target.
A.out/fast:
	$(MAKE) -f abc086\CMakeFiles\A.out.dir\build.make abc086/CMakeFiles/A.out.dir/build
.PHONY : A.out/fast

#=============================================================================
# Target rules for targets named B.out

# Build rule for target.
B.out: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 B.out
.PHONY : B.out

# fast build rule for target.
B.out/fast:
	$(MAKE) -f abc086\CMakeFiles\B.out.dir\build.make abc086/CMakeFiles/B.out.dir/build
.PHONY : B.out/fast

#=============================================================================
# Target rules for targets named C.out

# Build rule for target.
C.out: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 C.out
.PHONY : C.out

# fast build rule for target.
C.out/fast:
	$(MAKE) -f abc086\CMakeFiles\C.out.dir\build.make abc086/CMakeFiles/C.out.dir/build
.PHONY : C.out/fast

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... A.out
	@echo ... B.out
	@echo ... C.out
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system
