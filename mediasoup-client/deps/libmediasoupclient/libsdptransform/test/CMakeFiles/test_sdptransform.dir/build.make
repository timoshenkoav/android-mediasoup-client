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
CMAKE_COMMAND = /Users/alex/Android/sdk/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /Users/alex/Android/sdk/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client

# Include any dependencies generated for this target.
include deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/compiler_depend.make

# Include the progress variables for this target.
include deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/progress.make

# Include the compile flags for this target's objects.
include deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/flags.make

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.o: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/flags.make
deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.o: deps/libmediasoupclient/deps/libsdptransform/test/tests.cpp
deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.o: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.o"
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && /Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=x86_64-none-linux-android28 --sysroot=/Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.o -MF CMakeFiles/test_sdptransform.dir/tests.cpp.o.d -o CMakeFiles/test_sdptransform.dir/tests.cpp.o -c /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/deps/libsdptransform/test/tests.cpp

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sdptransform.dir/tests.cpp.i"
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && /Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=x86_64-none-linux-android28 --sysroot=/Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/deps/libsdptransform/test/tests.cpp > CMakeFiles/test_sdptransform.dir/tests.cpp.i

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sdptransform.dir/tests.cpp.s"
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && /Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=x86_64-none-linux-android28 --sysroot=/Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/deps/libsdptransform/test/tests.cpp -o CMakeFiles/test_sdptransform.dir/tests.cpp.s

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.o: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/flags.make
deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.o: deps/libmediasoupclient/deps/libsdptransform/test/parse.test.cpp
deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.o: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.o"
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && /Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=x86_64-none-linux-android28 --sysroot=/Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.o -MF CMakeFiles/test_sdptransform.dir/parse.test.cpp.o.d -o CMakeFiles/test_sdptransform.dir/parse.test.cpp.o -c /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/deps/libsdptransform/test/parse.test.cpp

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sdptransform.dir/parse.test.cpp.i"
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && /Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=x86_64-none-linux-android28 --sysroot=/Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/deps/libsdptransform/test/parse.test.cpp > CMakeFiles/test_sdptransform.dir/parse.test.cpp.i

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sdptransform.dir/parse.test.cpp.s"
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && /Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++ --target=x86_64-none-linux-android28 --sysroot=/Users/alex/Android/sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/darwin-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/deps/libsdptransform/test/parse.test.cpp -o CMakeFiles/test_sdptransform.dir/parse.test.cpp.s

# Object files for target test_sdptransform
test_sdptransform_OBJECTS = \
"CMakeFiles/test_sdptransform.dir/tests.cpp.o" \
"CMakeFiles/test_sdptransform.dir/parse.test.cpp.o"

# External object files for target test_sdptransform
test_sdptransform_EXTERNAL_OBJECTS =

output/x86_64/test_sdptransform: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/tests.cpp.o
output/x86_64/test_sdptransform: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/parse.test.cpp.o
output/x86_64/test_sdptransform: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/build.make
output/x86_64/test_sdptransform: deps/libmediasoupclient/libsdptransform/libsdptransform.a
output/x86_64/test_sdptransform: deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../../../output/x86_64/test_sdptransform"
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sdptransform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/build: output/x86_64/test_sdptransform
.PHONY : deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/build

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/clean:
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test && $(CMAKE_COMMAND) -P CMakeFiles/test_sdptransform.dir/cmake_clean.cmake
.PHONY : deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/clean

deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/depend:
	cd /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/deps/libsdptransform/test /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test /Users/alex/Projects/Engageli/mediasoup-client-android/mediasoup-client/deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : deps/libmediasoupclient/libsdptransform/test/CMakeFiles/test_sdptransform.dir/depend
