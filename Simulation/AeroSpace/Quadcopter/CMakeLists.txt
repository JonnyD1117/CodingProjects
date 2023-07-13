cmake_minimum_required(VERSION 3.25)
project(Quadcopter)

set(CMAKE_CXX_STANDARD 20)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(Quadcopter main.cpp QuadSim.h)
target_link_libraries (Quadcopter Eigen3::Eigen)

