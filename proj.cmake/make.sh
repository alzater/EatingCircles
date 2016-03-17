#!/bin/bash

mkdir build
cd build

#generate cmake project in the "build" folder
cmake -D ADDITIONAL_FLAGS=" -ggdb" ..
#build it
make -j5

cd ../../data
