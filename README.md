Project multiscale
==========

## Contents

1. **Introduction**
2. **Requirements**
    1. Building
    2. Running
3. **Running the movie generating scripts** 
    1. Rectangular geometry
    2. Circular geometry
4. **Running the region detection and analysis scripts**
    1. Rectangular geometry
    2. Circular geometry
5. **Contact**

## 1. Introduction

**Author:** Ovidiu Parvu                                                        
**Created on:** 4th of February, 2013                                           
**Modified on:** 6th of July, 2013                                          
**Current version:** 0.1.0

## 2. Requirements
   
### 2.1. Requirements for building the program

For building the program the following software need to be installed on your
computer:
* Boost library (ver. 1.52.0)
* g++ (ver. 4.7 or higher)
* OpenCV (ver. 2.4.4 or higher)

__Notes:__ 
1. You will have to change the paths to the boost libraries in the Makefile before building the project.
2. You will have to change the paths to the OpenCV libraries and header files in the Makefile before building the project.

### 2.2. Requirements for running the software

For running the program the following software need to be installed on your
computer:
* avconv
* Bash or an alternative shell which supports the same commands
* gnuplot (ver. 4.6)
* GNU parallel
* OpenCV (ver. 2.4.4 or higher)

__Notes:__ 
1. The path to the OpenCV libraries should be included in your PATH environment variable, such that they are accessible at runtime.

## 3. Running the movie generating scripts
   
### 3.1. Rectangular geometry

For generating a movie from a _.csv_ file considering a rectangular geometry use the script _RectangularGeometryViewer.sh_. The information regarding required parameters is displayed when running the script.

### 3.2. Circular geometry

For generating a movie from a _.csv_ file considering a circular geometry use the script _CircularGeometryViewer.sh_. The information regarding required parameters is displayed when running the script.

## 4. Running the region detection and analysis scripts
   
### 4.1. Rectangular geometry

For detecting and analysing regions of high intensity in an image considering a rectangular geometry use the script _RunRectangularRegionDetector.sh_. The information regarding required parameters is displayed when running the script.

### 4.2. Circular geometry

For detecting and analysing regions of high intensity in an image considering a circular geometry use the script _RunCircularRegionDetector.sh_. The information regarding required parameters is displayed when running the script.

## 5. Contact

For more details please visit my [personal webpage](http://brunel.ac.uk/~cspgoop).

