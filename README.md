# 2D-Pose Estimator for Tricycle Model

## Project Overview

This repository provides a simple C++ Interface class that can be used to read in some data from a source. Additionally, an example implementation of the Interface class is provided which can be used to read in data from a text file.

The code documented herein is a work in progress.

### Dependencies

- None

#### Building

It is necessary to build the source code before being able to use the classes. Therefore, from a terminal execute the following,

	cd /path/to/iai_interview

	mkdir build

	cd build

	cmake ..

	make

Once successfully building code, you can test the successful operation of the implementation class for reading in data from a text file, by running the following from the build directory:

	./../bin/test_iai

or from the root directory:

	./bin/test_iai

By running these commands the text file located in the *data* directory will be read in by default, however if you would like to read in a different text file the following commands can be used:

	./../bin/test_iai /absolute/path/to/specific_data_file.txt

or,

	./bin/test_iai /absolute/path/to/specific_data_file.txt

## Developer Notes ##

### Implementation Class Operation ###
Currently, the text file class implementation reads in each line of a text file and add that line to a vector of strings. This was done so that if users want to perform incremental operations on the returned data, or search for specific data based on line number, this would be possible.

### TODOs ###

- Ensure the interface class can efficiently be used by derived classes for other data sources (UDP, serial port, etc.)

### Maintainer ###

Hunter Young (hunter.lw.young@gmail.com)
