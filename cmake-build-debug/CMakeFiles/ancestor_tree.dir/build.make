# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/avi/CLionProjects/ancestor-tree-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ancestor_tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ancestor_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ancestor_tree.dir/flags.make

CMakeFiles/ancestor_tree.dir/Demo.cpp.o: CMakeFiles/ancestor_tree.dir/flags.make
CMakeFiles/ancestor_tree.dir/Demo.cpp.o: ../Demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ancestor_tree.dir/Demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ancestor_tree.dir/Demo.cpp.o -c /home/avi/CLionProjects/ancestor-tree-cpp/Demo.cpp

CMakeFiles/ancestor_tree.dir/Demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ancestor_tree.dir/Demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/avi/CLionProjects/ancestor-tree-cpp/Demo.cpp > CMakeFiles/ancestor_tree.dir/Demo.cpp.i

CMakeFiles/ancestor_tree.dir/Demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ancestor_tree.dir/Demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/avi/CLionProjects/ancestor-tree-cpp/Demo.cpp -o CMakeFiles/ancestor_tree.dir/Demo.cpp.s

CMakeFiles/ancestor_tree.dir/TestCounter.cpp.o: CMakeFiles/ancestor_tree.dir/flags.make
CMakeFiles/ancestor_tree.dir/TestCounter.cpp.o: ../TestCounter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ancestor_tree.dir/TestCounter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ancestor_tree.dir/TestCounter.cpp.o -c /home/avi/CLionProjects/ancestor-tree-cpp/TestCounter.cpp

CMakeFiles/ancestor_tree.dir/TestCounter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ancestor_tree.dir/TestCounter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/avi/CLionProjects/ancestor-tree-cpp/TestCounter.cpp > CMakeFiles/ancestor_tree.dir/TestCounter.cpp.i

CMakeFiles/ancestor_tree.dir/TestCounter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ancestor_tree.dir/TestCounter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/avi/CLionProjects/ancestor-tree-cpp/TestCounter.cpp -o CMakeFiles/ancestor_tree.dir/TestCounter.cpp.s

CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.o: CMakeFiles/ancestor_tree.dir/flags.make
CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.o: ../FamilyTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.o -c /home/avi/CLionProjects/ancestor-tree-cpp/FamilyTree.cpp

CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/avi/CLionProjects/ancestor-tree-cpp/FamilyTree.cpp > CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.i

CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/avi/CLionProjects/ancestor-tree-cpp/FamilyTree.cpp -o CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.s

CMakeFiles/ancestor_tree.dir/Test.cpp.o: CMakeFiles/ancestor_tree.dir/flags.make
CMakeFiles/ancestor_tree.dir/Test.cpp.o: ../Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ancestor_tree.dir/Test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ancestor_tree.dir/Test.cpp.o -c /home/avi/CLionProjects/ancestor-tree-cpp/Test.cpp

CMakeFiles/ancestor_tree.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ancestor_tree.dir/Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/avi/CLionProjects/ancestor-tree-cpp/Test.cpp > CMakeFiles/ancestor_tree.dir/Test.cpp.i

CMakeFiles/ancestor_tree.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ancestor_tree.dir/Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/avi/CLionProjects/ancestor-tree-cpp/Test.cpp -o CMakeFiles/ancestor_tree.dir/Test.cpp.s

# Object files for target ancestor_tree
ancestor_tree_OBJECTS = \
"CMakeFiles/ancestor_tree.dir/Demo.cpp.o" \
"CMakeFiles/ancestor_tree.dir/TestCounter.cpp.o" \
"CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.o" \
"CMakeFiles/ancestor_tree.dir/Test.cpp.o"

# External object files for target ancestor_tree
ancestor_tree_EXTERNAL_OBJECTS =

ancestor_tree: CMakeFiles/ancestor_tree.dir/Demo.cpp.o
ancestor_tree: CMakeFiles/ancestor_tree.dir/TestCounter.cpp.o
ancestor_tree: CMakeFiles/ancestor_tree.dir/FamilyTree.cpp.o
ancestor_tree: CMakeFiles/ancestor_tree.dir/Test.cpp.o
ancestor_tree: CMakeFiles/ancestor_tree.dir/build.make
ancestor_tree: CMakeFiles/ancestor_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ancestor_tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ancestor_tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ancestor_tree.dir/build: ancestor_tree

.PHONY : CMakeFiles/ancestor_tree.dir/build

CMakeFiles/ancestor_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ancestor_tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ancestor_tree.dir/clean

CMakeFiles/ancestor_tree.dir/depend:
	cd /home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/avi/CLionProjects/ancestor-tree-cpp /home/avi/CLionProjects/ancestor-tree-cpp /home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug /home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug /home/avi/CLionProjects/ancestor-tree-cpp/cmake-build-debug/CMakeFiles/ancestor_tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ancestor_tree.dir/depend

