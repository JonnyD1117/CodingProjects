cmake_minimum_required(VERSION 3.25)
project(MassSpringDamper)

set(CMAKE_CXX_STANDARD 20)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(MassSpringDamper main.cpp)
target_link_libraries (MassSpringDamper Eigen3::Eigen)