# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\QtCode\Windows\texteditor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\QtCode\Windows\texteditor\build-texteditor-Desktop_Qt_5_14_2_MinGW_64_bit-Debug

# Utility rule file for texteditor_autogen.

# Include the progress variables for this target.
include CMakeFiles/texteditor_autogen.dir/progress.make

CMakeFiles/texteditor_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\QtCode\Windows\texteditor\build-texteditor-Desktop_Qt_5_14_2_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target texteditor"
	D:\CMake\bin\cmake.exe -E cmake_autogen D:/QtCode/Windows/texteditor/build-texteditor-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/CMakeFiles/texteditor_autogen.dir/AutogenInfo.json Debug

texteditor_autogen: CMakeFiles/texteditor_autogen
texteditor_autogen: CMakeFiles/texteditor_autogen.dir/build.make

.PHONY : texteditor_autogen

# Rule to build all files generated by this target.
CMakeFiles/texteditor_autogen.dir/build: texteditor_autogen

.PHONY : CMakeFiles/texteditor_autogen.dir/build

CMakeFiles/texteditor_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\texteditor_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/texteditor_autogen.dir/clean

CMakeFiles/texteditor_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\QtCode\Windows\texteditor D:\QtCode\Windows\texteditor D:\QtCode\Windows\texteditor\build-texteditor-Desktop_Qt_5_14_2_MinGW_64_bit-Debug D:\QtCode\Windows\texteditor\build-texteditor-Desktop_Qt_5_14_2_MinGW_64_bit-Debug D:\QtCode\Windows\texteditor\build-texteditor-Desktop_Qt_5_14_2_MinGW_64_bit-Debug\CMakeFiles\texteditor_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/texteditor_autogen.dir/depend

