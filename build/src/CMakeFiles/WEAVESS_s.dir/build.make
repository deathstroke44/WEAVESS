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
CMAKE_SOURCE_DIR = /data/kabir/similarity-search/models/WEAVESS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/kabir/similarity-search/models/WEAVESS/build

# Include any dependencies generated for this target.
include src/CMakeFiles/WEAVESS_s.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/WEAVESS_s.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/WEAVESS_s.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/WEAVESS_s.dir/flags.make

src/CMakeFiles/WEAVESS_s.dir/builder.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/builder.cpp.o: ../src/builder.cpp
src/CMakeFiles/WEAVESS_s.dir/builder.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/builder.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/builder.cpp.o -MF CMakeFiles/WEAVESS_s.dir/builder.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/builder.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/builder.cpp

src/CMakeFiles/WEAVESS_s.dir/builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/builder.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/builder.cpp > CMakeFiles/WEAVESS_s.dir/builder.cpp.i

src/CMakeFiles/WEAVESS_s.dir/builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/builder.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/builder.cpp -o CMakeFiles/WEAVESS_s.dir/builder.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o: ../src/component_candidate.cpp
src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_candidate.cpp

src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_candidate.cpp > CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_candidate.cpp -o CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o: ../src/component_conn.cpp
src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_conn.cpp

src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_conn.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_conn.cpp > CMakeFiles/WEAVESS_s.dir/component_conn.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_conn.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_conn.cpp -o CMakeFiles/WEAVESS_s.dir/component_conn.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o: ../src/component_entry.cpp
src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_entry.cpp

src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_entry.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_entry.cpp > CMakeFiles/WEAVESS_s.dir/component_entry.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_entry.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_entry.cpp -o CMakeFiles/WEAVESS_s.dir/component_entry.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.o: ../src/component_init.cpp
src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_init.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_init.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_init.cpp

src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_init.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_init.cpp > CMakeFiles/WEAVESS_s.dir/component_init.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_init.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_init.cpp -o CMakeFiles/WEAVESS_s.dir/component_init.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.o: ../src/component_load.cpp
src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_load.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_load.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_load.cpp

src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_load.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_load.cpp > CMakeFiles/WEAVESS_s.dir/component_load.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_load.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_load.cpp -o CMakeFiles/WEAVESS_s.dir/component_load.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o: ../src/component_prune.cpp
src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_prune.cpp

src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_prune.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_prune.cpp > CMakeFiles/WEAVESS_s.dir/component_prune.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_prune.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_prune.cpp -o CMakeFiles/WEAVESS_s.dir/component_prune.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o: ../src/component_refine.cpp
src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_refine.cpp

src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_refine.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_refine.cpp > CMakeFiles/WEAVESS_s.dir/component_refine.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_refine.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_refine.cpp -o CMakeFiles/WEAVESS_s.dir/component_refine.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.o: ../src/component_route.cpp
src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_route.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_route.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_route.cpp

src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_route.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_route.cpp > CMakeFiles/WEAVESS_s.dir/component_route.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_route.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_route.cpp -o CMakeFiles/WEAVESS_s.dir/component_route.cpp.s

src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o: src/CMakeFiles/WEAVESS_s.dir/flags.make
src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o: ../src/component_search_entry.cpp
src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o: src/CMakeFiles/WEAVESS_s.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o -MF CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o.d -o CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o -c /data/kabir/similarity-search/models/WEAVESS/src/component_search_entry.cpp

src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.i"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/kabir/similarity-search/models/WEAVESS/src/component_search_entry.cpp > CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.i

src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.s"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/kabir/similarity-search/models/WEAVESS/src/component_search_entry.cpp -o CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.s

# Object files for target WEAVESS_s
WEAVESS_s_OBJECTS = \
"CMakeFiles/WEAVESS_s.dir/builder.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_init.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_load.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_route.cpp.o" \
"CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o"

# External object files for target WEAVESS_s
WEAVESS_s_EXTERNAL_OBJECTS =

src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/builder.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_candidate.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_conn.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_entry.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_init.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_load.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_prune.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_refine.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_route.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/component_search_entry.cpp.o
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/build.make
src/libWEAVESS_s.so: src/CMakeFiles/WEAVESS_s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/kabir/similarity-search/models/WEAVESS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library libWEAVESS_s.so"
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WEAVESS_s.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/WEAVESS_s.dir/build: src/libWEAVESS_s.so
.PHONY : src/CMakeFiles/WEAVESS_s.dir/build

src/CMakeFiles/WEAVESS_s.dir/clean:
	cd /data/kabir/similarity-search/models/WEAVESS/build/src && $(CMAKE_COMMAND) -P CMakeFiles/WEAVESS_s.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/WEAVESS_s.dir/clean

src/CMakeFiles/WEAVESS_s.dir/depend:
	cd /data/kabir/similarity-search/models/WEAVESS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/kabir/similarity-search/models/WEAVESS /data/kabir/similarity-search/models/WEAVESS/src /data/kabir/similarity-search/models/WEAVESS/build /data/kabir/similarity-search/models/WEAVESS/build/src /data/kabir/similarity-search/models/WEAVESS/build/src/CMakeFiles/WEAVESS_s.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/WEAVESS_s.dir/depend

