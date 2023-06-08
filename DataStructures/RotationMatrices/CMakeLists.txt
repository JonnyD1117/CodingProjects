cmake_minimum_required(VERSION 3.25)
project(RotationMatrices)

set(CMAKE_CXX_STANDARD 20)

add_executable(RotationMatrices main.cpp RotationMatrices.h)
add_subdirectory(UnitTests)
