# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Project\build

# Include any dependencies generated for this target.
include CMakeFiles/FinalProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FinalProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FinalProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FinalProject.dir/flags.make

CMakeFiles/FinalProject.dir/main.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/main.cpp.obj: D:/Project/main.cpp
CMakeFiles/FinalProject.dir/main.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FinalProject.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/main.cpp.obj -MF CMakeFiles\FinalProject.dir\main.cpp.obj.d -o CMakeFiles\FinalProject.dir\main.cpp.obj -c D:\Project\main.cpp

CMakeFiles/FinalProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\main.cpp > CMakeFiles\FinalProject.dir\main.cpp.i

CMakeFiles/FinalProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\main.cpp -o CMakeFiles\FinalProject.dir\main.cpp.s

CMakeFiles/FinalProject.dir/Commands.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/Commands.cpp.obj: D:/Project/Commands.cpp
CMakeFiles/FinalProject.dir/Commands.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FinalProject.dir/Commands.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/Commands.cpp.obj -MF CMakeFiles\FinalProject.dir\Commands.cpp.obj.d -o CMakeFiles\FinalProject.dir\Commands.cpp.obj -c D:\Project\Commands.cpp

CMakeFiles/FinalProject.dir/Commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/Commands.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\Commands.cpp > CMakeFiles\FinalProject.dir\Commands.cpp.i

CMakeFiles/FinalProject.dir/Commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/Commands.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\Commands.cpp -o CMakeFiles\FinalProject.dir\Commands.cpp.s

CMakeFiles/FinalProject.dir/XMLElement.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/XMLElement.cpp.obj: D:/Project/XMLElement.cpp
CMakeFiles/FinalProject.dir/XMLElement.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FinalProject.dir/XMLElement.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/XMLElement.cpp.obj -MF CMakeFiles\FinalProject.dir\XMLElement.cpp.obj.d -o CMakeFiles\FinalProject.dir\XMLElement.cpp.obj -c D:\Project\XMLElement.cpp

CMakeFiles/FinalProject.dir/XMLElement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/XMLElement.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\XMLElement.cpp > CMakeFiles\FinalProject.dir\XMLElement.cpp.i

CMakeFiles/FinalProject.dir/XMLElement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/XMLElement.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\XMLElement.cpp -o CMakeFiles\FinalProject.dir\XMLElement.cpp.s

CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.obj: D:/Project/XMLGeneratorT.cpp
CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.obj -MF CMakeFiles\FinalProject.dir\XMLGeneratorT.cpp.obj.d -o CMakeFiles\FinalProject.dir\XMLGeneratorT.cpp.obj -c D:\Project\XMLGeneratorT.cpp

CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\XMLGeneratorT.cpp > CMakeFiles\FinalProject.dir\XMLGeneratorT.cpp.i

CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\XMLGeneratorT.cpp -o CMakeFiles\FinalProject.dir\XMLGeneratorT.cpp.s

CMakeFiles/FinalProject.dir/XMLParser.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/XMLParser.cpp.obj: D:/Project/XMLParser.cpp
CMakeFiles/FinalProject.dir/XMLParser.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FinalProject.dir/XMLParser.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/XMLParser.cpp.obj -MF CMakeFiles\FinalProject.dir\XMLParser.cpp.obj.d -o CMakeFiles\FinalProject.dir\XMLParser.cpp.obj -c D:\Project\XMLParser.cpp

CMakeFiles/FinalProject.dir/XMLParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/XMLParser.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\XMLParser.cpp > CMakeFiles\FinalProject.dir\XMLParser.cpp.i

CMakeFiles/FinalProject.dir/XMLParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/XMLParser.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\XMLParser.cpp -o CMakeFiles\FinalProject.dir\XMLParser.cpp.s

CMakeFiles/FinalProject.dir/XMLPath.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/XMLPath.cpp.obj: D:/Project/XMLPath.cpp
CMakeFiles/FinalProject.dir/XMLPath.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FinalProject.dir/XMLPath.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/XMLPath.cpp.obj -MF CMakeFiles\FinalProject.dir\XMLPath.cpp.obj.d -o CMakeFiles\FinalProject.dir\XMLPath.cpp.obj -c D:\Project\XMLPath.cpp

CMakeFiles/FinalProject.dir/XMLPath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/XMLPath.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\XMLPath.cpp > CMakeFiles\FinalProject.dir\XMLPath.cpp.i

CMakeFiles/FinalProject.dir/XMLPath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/XMLPath.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\XMLPath.cpp -o CMakeFiles\FinalProject.dir\XMLPath.cpp.s

CMakeFiles/FinalProject.dir/XMLTree.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/XMLTree.cpp.obj: D:/Project/XMLTree.cpp
CMakeFiles/FinalProject.dir/XMLTree.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/FinalProject.dir/XMLTree.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/XMLTree.cpp.obj -MF CMakeFiles\FinalProject.dir\XMLTree.cpp.obj.d -o CMakeFiles\FinalProject.dir\XMLTree.cpp.obj -c D:\Project\XMLTree.cpp

CMakeFiles/FinalProject.dir/XMLTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/XMLTree.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\XMLTree.cpp > CMakeFiles\FinalProject.dir\XMLTree.cpp.i

CMakeFiles/FinalProject.dir/XMLTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/XMLTree.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\XMLTree.cpp -o CMakeFiles\FinalProject.dir\XMLTree.cpp.s

CMakeFiles/FinalProject.dir/Runner.cpp.obj: CMakeFiles/FinalProject.dir/flags.make
CMakeFiles/FinalProject.dir/Runner.cpp.obj: D:/Project/Runner.cpp
CMakeFiles/FinalProject.dir/Runner.cpp.obj: CMakeFiles/FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/FinalProject.dir/Runner.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FinalProject.dir/Runner.cpp.obj -MF CMakeFiles\FinalProject.dir\Runner.cpp.obj.d -o CMakeFiles\FinalProject.dir\Runner.cpp.obj -c D:\Project\Runner.cpp

CMakeFiles/FinalProject.dir/Runner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/Runner.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\Runner.cpp > CMakeFiles\FinalProject.dir\Runner.cpp.i

CMakeFiles/FinalProject.dir/Runner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/Runner.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\Runner.cpp -o CMakeFiles\FinalProject.dir\Runner.cpp.s

# Object files for target FinalProject
FinalProject_OBJECTS = \
"CMakeFiles/FinalProject.dir/main.cpp.obj" \
"CMakeFiles/FinalProject.dir/Commands.cpp.obj" \
"CMakeFiles/FinalProject.dir/XMLElement.cpp.obj" \
"CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.obj" \
"CMakeFiles/FinalProject.dir/XMLParser.cpp.obj" \
"CMakeFiles/FinalProject.dir/XMLPath.cpp.obj" \
"CMakeFiles/FinalProject.dir/XMLTree.cpp.obj" \
"CMakeFiles/FinalProject.dir/Runner.cpp.obj"

# External object files for target FinalProject
FinalProject_EXTERNAL_OBJECTS =

FinalProject.exe: CMakeFiles/FinalProject.dir/main.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/Commands.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/XMLElement.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/XMLGeneratorT.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/XMLParser.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/XMLPath.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/XMLTree.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/Runner.cpp.obj
FinalProject.exe: CMakeFiles/FinalProject.dir/build.make
FinalProject.exe: CMakeFiles/FinalProject.dir/linkLibs.rsp
FinalProject.exe: CMakeFiles/FinalProject.dir/objects1.rsp
FinalProject.exe: CMakeFiles/FinalProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable FinalProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FinalProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FinalProject.dir/build: FinalProject.exe
.PHONY : CMakeFiles/FinalProject.dir/build

CMakeFiles/FinalProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FinalProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FinalProject.dir/clean

CMakeFiles/FinalProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Project D:\Project D:\Project\build D:\Project\build D:\Project\build\CMakeFiles\FinalProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FinalProject.dir/depend
