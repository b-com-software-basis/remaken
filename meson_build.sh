#!/bin/bash

mkdir -p .build/boost/cmake
pushd .build/boost/cmake
cmake -DCMAKE_INSTALL_PREFIX=../install ../../../libs/boost
make
make install
popd
meson setup .build/remaken
pushd .build/remaken
meson compile
popd