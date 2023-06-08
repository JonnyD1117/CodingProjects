cmake_minimum_required(VERSION 3.25)
project(DynamicArray)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(UnitTests)
add_executable(DynamicArray main.cpp DynamicArray.h)
