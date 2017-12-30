cmake_minimum_required(VERSION 3.8)
project(lopputyotictactoe2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp omakirjasto.cpp omakirjasto.h)
add_executable(lopputyoristinolla ${SOURCE_FILES})