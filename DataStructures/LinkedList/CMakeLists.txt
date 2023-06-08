cmake_minimum_required(VERSION 3.25)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(UnitTests)
add_executable(LinkedList main.cpp LinkedList.h)
