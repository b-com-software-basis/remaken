#!/bin/bash

if [ ! -d libs/boost ]; then
    pushd libs
    echo "Trying to clone boost from github"
    git clone --recurse-submodules https://github.com/boostorg/boost
    popd
fi

if [ ! -d libs/boost ]; then
    echo "Error cloning boost from github - exiting"
    exit
fi

echo "Building boost"
mkdir -p .build/boost/cmake
pushd .build/boost/cmake
cmake -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_POSITION_INDEPENDENT_CODE=ON ../../../libs/boost
make
make install
popd

echo "Meson setup for remaken"
meson setup .build/remaken

echo "Building remaken"
pushd .build/remaken
meson compile
popd