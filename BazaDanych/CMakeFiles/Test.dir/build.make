# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/konrad/Dokumenty/CLionProjects/BagOfWords

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/test/main.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/test/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.dir/test/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/test/main.cpp.o -c /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/main.cpp

CMakeFiles/Test.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/test/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/main.cpp > CMakeFiles/Test.dir/test/main.cpp.i

CMakeFiles/Test.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/test/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/main.cpp -o CMakeFiles/Test.dir/test/main.cpp.s

CMakeFiles/Test.dir/test/main.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/test/main.cpp.o.requires

CMakeFiles/Test.dir/test/main.cpp.o.provides: CMakeFiles/Test.dir/test/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/test/main.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/test/main.cpp.o.provides

CMakeFiles/Test.dir/test/main.cpp.o.provides.build: CMakeFiles/Test.dir/test/main.cpp.o


CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o: ../test/VisualDictionaryTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o -c /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/VisualDictionaryTest.cpp

CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/VisualDictionaryTest.cpp > CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.i

CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/VisualDictionaryTest.cpp -o CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.s

CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.requires

CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.provides: CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.provides

CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.provides.build: CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o


CMakeFiles/Test.dir/test/DatabaseTest.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/test/DatabaseTest.cpp.o: ../test/DatabaseTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Test.dir/test/DatabaseTest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/test/DatabaseTest.cpp.o -c /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/DatabaseTest.cpp

CMakeFiles/Test.dir/test/DatabaseTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/test/DatabaseTest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/DatabaseTest.cpp > CMakeFiles/Test.dir/test/DatabaseTest.cpp.i

CMakeFiles/Test.dir/test/DatabaseTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/test/DatabaseTest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/CLionProjects/BagOfWords/test/DatabaseTest.cpp -o CMakeFiles/Test.dir/test/DatabaseTest.cpp.s

CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.requires

CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.provides: CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.provides

CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.provides.build: CMakeFiles/Test.dir/test/DatabaseTest.cpp.o


CMakeFiles/Test.dir/src/PictureDatabase.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/PictureDatabase.cpp.o: ../src/PictureDatabase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Test.dir/src/PictureDatabase.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/src/PictureDatabase.cpp.o -c /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/PictureDatabase.cpp

CMakeFiles/Test.dir/src/PictureDatabase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/PictureDatabase.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/PictureDatabase.cpp > CMakeFiles/Test.dir/src/PictureDatabase.cpp.i

CMakeFiles/Test.dir/src/PictureDatabase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/PictureDatabase.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/PictureDatabase.cpp -o CMakeFiles/Test.dir/src/PictureDatabase.cpp.s

CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.requires

CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.provides: CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.provides

CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.provides.build: CMakeFiles/Test.dir/src/PictureDatabase.cpp.o


CMakeFiles/Test.dir/src/VisualDictionary.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/VisualDictionary.cpp.o: ../src/VisualDictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Test.dir/src/VisualDictionary.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/src/VisualDictionary.cpp.o -c /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/VisualDictionary.cpp

CMakeFiles/Test.dir/src/VisualDictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/VisualDictionary.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/VisualDictionary.cpp > CMakeFiles/Test.dir/src/VisualDictionary.cpp.i

CMakeFiles/Test.dir/src/VisualDictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/VisualDictionary.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/VisualDictionary.cpp -o CMakeFiles/Test.dir/src/VisualDictionary.cpp.s

CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.requires

CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.provides: CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.provides

CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.provides.build: CMakeFiles/Test.dir/src/VisualDictionary.cpp.o


CMakeFiles/Test.dir/src/BOW.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/BOW.cpp.o: ../src/BOW.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Test.dir/src/BOW.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/src/BOW.cpp.o -c /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/BOW.cpp

CMakeFiles/Test.dir/src/BOW.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/BOW.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/BOW.cpp > CMakeFiles/Test.dir/src/BOW.cpp.i

CMakeFiles/Test.dir/src/BOW.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/BOW.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/BOW.cpp -o CMakeFiles/Test.dir/src/BOW.cpp.s

CMakeFiles/Test.dir/src/BOW.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/src/BOW.cpp.o.requires

CMakeFiles/Test.dir/src/BOW.cpp.o.provides: CMakeFiles/Test.dir/src/BOW.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/src/BOW.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/src/BOW.cpp.o.provides

CMakeFiles/Test.dir/src/BOW.cpp.o.provides.build: CMakeFiles/Test.dir/src/BOW.cpp.o


CMakeFiles/Test.dir/src/PictureInformation.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/PictureInformation.cpp.o: ../src/PictureInformation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Test.dir/src/PictureInformation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/src/PictureInformation.cpp.o -c /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/PictureInformation.cpp

CMakeFiles/Test.dir/src/PictureInformation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/PictureInformation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/PictureInformation.cpp > CMakeFiles/Test.dir/src/PictureInformation.cpp.i

CMakeFiles/Test.dir/src/PictureInformation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/PictureInformation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/CLionProjects/BagOfWords/src/PictureInformation.cpp -o CMakeFiles/Test.dir/src/PictureInformation.cpp.s

CMakeFiles/Test.dir/src/PictureInformation.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/src/PictureInformation.cpp.o.requires

CMakeFiles/Test.dir/src/PictureInformation.cpp.o.provides: CMakeFiles/Test.dir/src/PictureInformation.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/src/PictureInformation.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/src/PictureInformation.cpp.o.provides

CMakeFiles/Test.dir/src/PictureInformation.cpp.o.provides.build: CMakeFiles/Test.dir/src/PictureInformation.cpp.o


# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/test/main.cpp.o" \
"CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o" \
"CMakeFiles/Test.dir/test/DatabaseTest.cpp.o" \
"CMakeFiles/Test.dir/src/PictureDatabase.cpp.o" \
"CMakeFiles/Test.dir/src/VisualDictionary.cpp.o" \
"CMakeFiles/Test.dir/src/BOW.cpp.o" \
"CMakeFiles/Test.dir/src/PictureInformation.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/test/main.cpp.o
Test: CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o
Test: CMakeFiles/Test.dir/test/DatabaseTest.cpp.o
Test: CMakeFiles/Test.dir/src/PictureDatabase.cpp.o
Test: CMakeFiles/Test.dir/src/VisualDictionary.cpp.o
Test: CMakeFiles/Test.dir/src/BOW.cpp.o
Test: CMakeFiles/Test.dir/src/PictureInformation.cpp.o
Test: CMakeFiles/Test.dir/build.make
Test: /usr/local/lib/libopencv_xphoto.so.3.1.0
Test: /usr/local/lib/libopencv_xobjdetect.so.3.1.0
Test: /usr/local/lib/libopencv_tracking.so.3.1.0
Test: /usr/local/lib/libopencv_surface_matching.so.3.1.0
Test: /usr/local/lib/libopencv_structured_light.so.3.1.0
Test: /usr/local/lib/libopencv_stereo.so.3.1.0
Test: /usr/local/lib/libopencv_saliency.so.3.1.0
Test: /usr/local/lib/libopencv_rgbd.so.3.1.0
Test: /usr/local/lib/libopencv_reg.so.3.1.0
Test: /usr/local/lib/libopencv_plot.so.3.1.0
Test: /usr/local/lib/libopencv_optflow.so.3.1.0
Test: /usr/local/lib/libopencv_line_descriptor.so.3.1.0
Test: /usr/local/lib/libopencv_fuzzy.so.3.1.0
Test: /usr/local/lib/libopencv_dpm.so.3.1.0
Test: /usr/local/lib/libopencv_dnn.so.3.1.0
Test: /usr/local/lib/libopencv_datasets.so.3.1.0
Test: /usr/local/lib/libopencv_ccalib.so.3.1.0
Test: /usr/local/lib/libopencv_bioinspired.so.3.1.0
Test: /usr/local/lib/libopencv_bgsegm.so.3.1.0
Test: /usr/local/lib/libopencv_aruco.so.3.1.0
Test: /usr/local/lib/libopencv_videostab.so.3.1.0
Test: /usr/local/lib/libopencv_superres.so.3.1.0
Test: /usr/local/lib/libopencv_stitching.so.3.1.0
Test: /usr/local/lib/libopencv_photo.so.3.1.0
Test: /usr/local/lib/libboost_system.so
Test: /usr/local/lib/libboost_filesystem.so
Test: /usr/local/lib/libboost_serialization.so
Test: /usr/local/lib/libopencv_text.so.3.1.0
Test: /usr/local/lib/libopencv_face.so.3.1.0
Test: /usr/local/lib/libopencv_ximgproc.so.3.1.0
Test: /usr/local/lib/libopencv_xfeatures2d.so.3.1.0
Test: /usr/local/lib/libopencv_shape.so.3.1.0
Test: /usr/local/lib/libopencv_video.so.3.1.0
Test: /usr/local/lib/libopencv_objdetect.so.3.1.0
Test: /usr/local/lib/libopencv_calib3d.so.3.1.0
Test: /usr/local/lib/libopencv_features2d.so.3.1.0
Test: /usr/local/lib/libopencv_ml.so.3.1.0
Test: /usr/local/lib/libopencv_highgui.so.3.1.0
Test: /usr/local/lib/libopencv_videoio.so.3.1.0
Test: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
Test: /usr/local/lib/libopencv_imgproc.so.3.1.0
Test: /usr/local/lib/libopencv_flann.so.3.1.0
Test: /usr/local/lib/libopencv_core.so.3.1.0
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test

.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/test/main.cpp.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/test/VisualDictionaryTest.cpp.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/test/DatabaseTest.cpp.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/src/PictureDatabase.cpp.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/src/VisualDictionary.cpp.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/src/BOW.cpp.o.requires
CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/src/PictureInformation.cpp.o.requires

.PHONY : CMakeFiles/Test.dir/requires

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/konrad/Dokumenty/CLionProjects/BagOfWords /home/konrad/Dokumenty/CLionProjects/BagOfWords /home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych /home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych /home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.dir/depend
