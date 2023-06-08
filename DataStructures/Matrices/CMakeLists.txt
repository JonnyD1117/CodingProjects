cmake_minimum_required(VERSION 3.25)
project(Matrices)

set(CMAKE_CXX_STANDARD 20)
add_executable(Matrices main.cpp Matrix.h)
add_subdirectory(UnitTests)