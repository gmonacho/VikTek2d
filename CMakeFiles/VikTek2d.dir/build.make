# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Users/gmonacho/.brew/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /Users/gmonacho/.brew/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gmonacho/Documents/101/VikTek2d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gmonacho/Documents/101/VikTek2d

# Include any dependencies generated for this target.
include CMakeFiles/VikTek2d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VikTek2d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VikTek2d.dir/flags.make

CMakeFiles/VikTek2d.dir/src/main.cpp.o: CMakeFiles/VikTek2d.dir/flags.make
CMakeFiles/VikTek2d.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gmonacho/Documents/101/VikTek2d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VikTek2d.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VikTek2d.dir/src/main.cpp.o -c /Users/gmonacho/Documents/101/VikTek2d/src/main.cpp

CMakeFiles/VikTek2d.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VikTek2d.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gmonacho/Documents/101/VikTek2d/src/main.cpp > CMakeFiles/VikTek2d.dir/src/main.cpp.i

CMakeFiles/VikTek2d.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VikTek2d.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gmonacho/Documents/101/VikTek2d/src/main.cpp -o CMakeFiles/VikTek2d.dir/src/main.cpp.s

# Object files for target VikTek2d
VikTek2d_OBJECTS = \
"CMakeFiles/VikTek2d.dir/src/main.cpp.o"

# External object files for target VikTek2d
VikTek2d_EXTERNAL_OBJECTS =

VikTek2d: CMakeFiles/VikTek2d.dir/src/main.cpp.o
VikTek2d: CMakeFiles/VikTek2d.dir/build.make
VikTek2d: CMakeFiles/VikTek2d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gmonacho/Documents/101/VikTek2d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VikTek2d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VikTek2d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VikTek2d.dir/build: VikTek2d

.PHONY : CMakeFiles/VikTek2d.dir/build

CMakeFiles/VikTek2d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VikTek2d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VikTek2d.dir/clean

CMakeFiles/VikTek2d.dir/depend:
	cd /Users/gmonacho/Documents/101/VikTek2d && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gmonacho/Documents/101/VikTek2d /Users/gmonacho/Documents/101/VikTek2d /Users/gmonacho/Documents/101/VikTek2d /Users/gmonacho/Documents/101/VikTek2d /Users/gmonacho/Documents/101/VikTek2d/CMakeFiles/VikTek2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VikTek2d.dir/depend

