# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/inamdara/ICS45c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/inamdara/ICS45c

# Include any dependencies generated for this target.
include CMakeFiles/word_count.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/word_count.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/word_count.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/word_count.dir/flags.make

CMakeFiles/word_count.dir/src/word_count.cpp.o: CMakeFiles/word_count.dir/flags.make
CMakeFiles/word_count.dir/src/word_count.cpp.o: src/word_count.cpp
CMakeFiles/word_count.dir/src/word_count.cpp.o: CMakeFiles/word_count.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/inamdara/ICS45c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/word_count.dir/src/word_count.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/word_count.dir/src/word_count.cpp.o -MF CMakeFiles/word_count.dir/src/word_count.cpp.o.d -o CMakeFiles/word_count.dir/src/word_count.cpp.o -c /home/inamdara/ICS45c/src/word_count.cpp

CMakeFiles/word_count.dir/src/word_count.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/word_count.dir/src/word_count.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/inamdara/ICS45c/src/word_count.cpp > CMakeFiles/word_count.dir/src/word_count.cpp.i

CMakeFiles/word_count.dir/src/word_count.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/word_count.dir/src/word_count.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/inamdara/ICS45c/src/word_count.cpp -o CMakeFiles/word_count.dir/src/word_count.cpp.s

CMakeFiles/word_count.dir/src/word_count_main.cpp.o: CMakeFiles/word_count.dir/flags.make
CMakeFiles/word_count.dir/src/word_count_main.cpp.o: src/word_count_main.cpp
CMakeFiles/word_count.dir/src/word_count_main.cpp.o: CMakeFiles/word_count.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/inamdara/ICS45c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/word_count.dir/src/word_count_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/word_count.dir/src/word_count_main.cpp.o -MF CMakeFiles/word_count.dir/src/word_count_main.cpp.o.d -o CMakeFiles/word_count.dir/src/word_count_main.cpp.o -c /home/inamdara/ICS45c/src/word_count_main.cpp

CMakeFiles/word_count.dir/src/word_count_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/word_count.dir/src/word_count_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/inamdara/ICS45c/src/word_count_main.cpp > CMakeFiles/word_count.dir/src/word_count_main.cpp.i

CMakeFiles/word_count.dir/src/word_count_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/word_count.dir/src/word_count_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/inamdara/ICS45c/src/word_count_main.cpp -o CMakeFiles/word_count.dir/src/word_count_main.cpp.s

# Object files for target word_count
word_count_OBJECTS = \
"CMakeFiles/word_count.dir/src/word_count.cpp.o" \
"CMakeFiles/word_count.dir/src/word_count_main.cpp.o"

# External object files for target word_count
word_count_EXTERNAL_OBJECTS =

word_count: CMakeFiles/word_count.dir/src/word_count.cpp.o
word_count: CMakeFiles/word_count.dir/src/word_count_main.cpp.o
word_count: CMakeFiles/word_count.dir/build.make
word_count: CMakeFiles/word_count.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/inamdara/ICS45c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable word_count"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/word_count.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/word_count.dir/build: word_count
.PHONY : CMakeFiles/word_count.dir/build

CMakeFiles/word_count.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/word_count.dir/cmake_clean.cmake
.PHONY : CMakeFiles/word_count.dir/clean

CMakeFiles/word_count.dir/depend:
	cd /home/inamdara/ICS45c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/inamdara/ICS45c /home/inamdara/ICS45c /home/inamdara/ICS45c /home/inamdara/ICS45c /home/inamdara/ICS45c/CMakeFiles/word_count.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/word_count.dir/depend

