# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "D:\jetbrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\jetbrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\lion_ide\test_glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\lion_ide\test_glfw\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/test_glfw.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_glfw.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_glfw.dir/flags.make

CMakeFiles/test_glfw.dir/main.cpp.obj: CMakeFiles/test_glfw.dir/flags.make
CMakeFiles/test_glfw.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\lion_ide\test_glfw\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_glfw.dir/main.cpp.obj"
	D:\jetbrains\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_glfw.dir\main.cpp.obj -c D:\lion_ide\test_glfw\main.cpp

CMakeFiles/test_glfw.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_glfw.dir/main.cpp.i"
	D:\jetbrains\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\lion_ide\test_glfw\main.cpp > CMakeFiles\test_glfw.dir\main.cpp.i

CMakeFiles/test_glfw.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_glfw.dir/main.cpp.s"
	D:\jetbrains\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\lion_ide\test_glfw\main.cpp -o CMakeFiles\test_glfw.dir\main.cpp.s

CMakeFiles/test_glfw.dir/glad.c.obj: CMakeFiles/test_glfw.dir/flags.make
CMakeFiles/test_glfw.dir/glad.c.obj: ../glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\lion_ide\test_glfw\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_glfw.dir/glad.c.obj"
	D:\jetbrains\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_glfw.dir\glad.c.obj   -c D:\lion_ide\test_glfw\glad.c

CMakeFiles/test_glfw.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_glfw.dir/glad.c.i"
	D:\jetbrains\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\lion_ide\test_glfw\glad.c > CMakeFiles\test_glfw.dir\glad.c.i

CMakeFiles/test_glfw.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_glfw.dir/glad.c.s"
	D:\jetbrains\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\lion_ide\test_glfw\glad.c -o CMakeFiles\test_glfw.dir\glad.c.s

# Object files for target test_glfw
test_glfw_OBJECTS = \
"CMakeFiles/test_glfw.dir/main.cpp.obj" \
"CMakeFiles/test_glfw.dir/glad.c.obj"

# External object files for target test_glfw
test_glfw_EXTERNAL_OBJECTS =

test_glfw.exe: CMakeFiles/test_glfw.dir/main.cpp.obj
test_glfw.exe: CMakeFiles/test_glfw.dir/glad.c.obj
test_glfw.exe: CMakeFiles/test_glfw.dir/build.make
test_glfw.exe: CMakeFiles/test_glfw.dir/linklibs.rsp
test_glfw.exe: CMakeFiles/test_glfw.dir/objects1.rsp
test_glfw.exe: CMakeFiles/test_glfw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\lion_ide\test_glfw\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_glfw.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_glfw.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_glfw.dir/build: test_glfw.exe

.PHONY : CMakeFiles/test_glfw.dir/build

CMakeFiles/test_glfw.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_glfw.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_glfw.dir/clean

CMakeFiles/test_glfw.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\lion_ide\test_glfw D:\lion_ide\test_glfw D:\lion_ide\test_glfw\cmake-build-release D:\lion_ide\test_glfw\cmake-build-release D:\lion_ide\test_glfw\cmake-build-release\CMakeFiles\test_glfw.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_glfw.dir/depend

