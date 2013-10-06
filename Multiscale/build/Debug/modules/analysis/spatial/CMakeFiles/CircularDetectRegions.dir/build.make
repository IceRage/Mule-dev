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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ovidiu/Repositories/git/multiscale/Multiscale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug

# Include any dependencies generated for this target.
include modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/depend.make

# Include the progress variables for this target.
include modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/progress.make

# Include the compile flags for this target's objects.
include modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o: ../../modules/analysis/spatial/src/CircularityMeasure.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/CircularityMeasure.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/CircularityMeasure.cpp > CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/CircularityMeasure.cpp -o CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o: ../../modules/analysis/spatial/src/Detector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/Detector.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/Detector.cpp > CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/Detector.cpp -o CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o: ../../modules/analysis/spatial/src/MatFactory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/MatFactory.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/MatFactory.cpp > CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/MatFactory.cpp -o CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o: ../../modules/analysis/spatial/src/CircularDetectRegions.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/CircularDetectRegions.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/CircularDetectRegions.cpp > CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/CircularDetectRegions.cpp -o CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o: ../../modules/analysis/spatial/src/Region.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/Region.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/Region.cpp > CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/Region.cpp -o CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o: ../../modules/analysis/spatial/src/RegionDetector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/RegionDetector.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/RegionDetector.cpp > CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/RegionDetector.cpp -o CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o: ../../modules/analysis/spatial/src/SpatialCollection2D.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/SpatialCollection2D.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/SpatialCollection2D.cpp > CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/SpatialCollection2D.cpp -o CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/flags.make
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o: ../../modules/analysis/spatial/src/factory/CircularMatFactory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o -c /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/factory/CircularMatFactory.cpp

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.i"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/factory/CircularMatFactory.cpp > CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.i

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.s"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial/src/factory/CircularMatFactory.cpp -o CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.s

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.requires:
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.provides: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.requires
	$(MAKE) -f modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.provides.build
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.provides

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.provides.build: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o

# Object files for target CircularDetectRegions
CircularDetectRegions_OBJECTS = \
"CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o" \
"CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o" \
"CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o" \
"CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o" \
"CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o" \
"CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o" \
"CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o" \
"CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o"

# External object files for target CircularDetectRegions
CircularDetectRegions_EXTERNAL_OBJECTS =

../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o
../../bin/CircularDetectRegions_d: ../../lib/libutil_d.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_calib3d.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_contrib.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_core.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_features2d.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_flann.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_gpu.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_highgui.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_imgproc.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_legacy.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_ml.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_nonfree.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_objdetect.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_photo.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_stitching.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_ts.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_video.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libopencv_videostab.so
../../bin/CircularDetectRegions_d: /usr/local/lib/libboost_program_options.a
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build.make
../../bin/CircularDetectRegions_d: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../../../bin/CircularDetectRegions_d"
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CircularDetectRegions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build: ../../bin/CircularDetectRegions_d
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/build

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularityMeasure.cpp.o.requires
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Detector.cpp.o.requires
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/MatFactory.cpp.o.requires
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/CircularDetectRegions.cpp.o.requires
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/Region.cpp.o.requires
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/RegionDetector.cpp.o.requires
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/SpatialCollection2D.cpp.o.requires
modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires: modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/src/factory/CircularMatFactory.cpp.o.requires
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/requires

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/clean:
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial && $(CMAKE_COMMAND) -P CMakeFiles/CircularDetectRegions.dir/cmake_clean.cmake
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/clean

modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/depend:
	cd /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ovidiu/Repositories/git/multiscale/Multiscale /home/ovidiu/Repositories/git/multiscale/Multiscale/modules/analysis/spatial /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial /home/ovidiu/Repositories/git/multiscale/Multiscale/build/Debug/modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/analysis/spatial/CMakeFiles/CircularDetectRegions.dir/depend
