# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cloquet/PSU_2015_zappy/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cloquet/PSU_2015_zappy/server/build

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/src/main.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/main.c.o: ../src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cloquet/PSU_2015_zappy/server/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/server.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/server.dir/src/main.c.o   -c /home/cloquet/PSU_2015_zappy/server/src/main.c

CMakeFiles/server.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cloquet/PSU_2015_zappy/server/src/main.c > CMakeFiles/server.dir/src/main.c.i

CMakeFiles/server.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cloquet/PSU_2015_zappy/server/src/main.c -o CMakeFiles/server.dir/src/main.c.s

CMakeFiles/server.dir/src/main.c.o.requires:
.PHONY : CMakeFiles/server.dir/src/main.c.o.requires

CMakeFiles/server.dir/src/main.c.o.provides: CMakeFiles/server.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/server.dir/src/main.c.o.provides

CMakeFiles/server.dir/src/main.c.o.provides.build: CMakeFiles/server.dir/src/main.c.o

CMakeFiles/server.dir/src/set_params.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/set_params.c.o: ../src/set_params.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cloquet/PSU_2015_zappy/server/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/server.dir/src/set_params.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/server.dir/src/set_params.c.o   -c /home/cloquet/PSU_2015_zappy/server/src/set_params.c

CMakeFiles/server.dir/src/set_params.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/set_params.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cloquet/PSU_2015_zappy/server/src/set_params.c > CMakeFiles/server.dir/src/set_params.c.i

CMakeFiles/server.dir/src/set_params.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/set_params.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cloquet/PSU_2015_zappy/server/src/set_params.c -o CMakeFiles/server.dir/src/set_params.c.s

CMakeFiles/server.dir/src/set_params.c.o.requires:
.PHONY : CMakeFiles/server.dir/src/set_params.c.o.requires

CMakeFiles/server.dir/src/set_params.c.o.provides: CMakeFiles/server.dir/src/set_params.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/set_params.c.o.provides.build
.PHONY : CMakeFiles/server.dir/src/set_params.c.o.provides

CMakeFiles/server.dir/src/set_params.c.o.provides.build: CMakeFiles/server.dir/src/set_params.c.o

CMakeFiles/server.dir/src/utils.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/utils.c.o: ../src/utils.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cloquet/PSU_2015_zappy/server/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/server.dir/src/utils.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/server.dir/src/utils.c.o   -c /home/cloquet/PSU_2015_zappy/server/src/utils.c

CMakeFiles/server.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/utils.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cloquet/PSU_2015_zappy/server/src/utils.c > CMakeFiles/server.dir/src/utils.c.i

CMakeFiles/server.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/utils.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cloquet/PSU_2015_zappy/server/src/utils.c -o CMakeFiles/server.dir/src/utils.c.s

CMakeFiles/server.dir/src/utils.c.o.requires:
.PHONY : CMakeFiles/server.dir/src/utils.c.o.requires

CMakeFiles/server.dir/src/utils.c.o.provides: CMakeFiles/server.dir/src/utils.c.o.requires
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/utils.c.o.provides.build
.PHONY : CMakeFiles/server.dir/src/utils.c.o.provides

CMakeFiles/server.dir/src/utils.c.o.provides.build: CMakeFiles/server.dir/src/utils.c.o

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/src/main.c.o" \
"CMakeFiles/server.dir/src/set_params.c.o" \
"CMakeFiles/server.dir/src/utils.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server: CMakeFiles/server.dir/src/main.c.o
server: CMakeFiles/server.dir/src/set_params.c.o
server: CMakeFiles/server.dir/src/utils.c.o
server: CMakeFiles/server.dir/build.make
server: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server
.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/main.c.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/set_params.c.o.requires
CMakeFiles/server.dir/requires: CMakeFiles/server.dir/src/utils.c.o.requires
.PHONY : CMakeFiles/server.dir/requires

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /home/cloquet/PSU_2015_zappy/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cloquet/PSU_2015_zappy/server /home/cloquet/PSU_2015_zappy/server /home/cloquet/PSU_2015_zappy/server/build /home/cloquet/PSU_2015_zappy/server/build /home/cloquet/PSU_2015_zappy/server/build/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

