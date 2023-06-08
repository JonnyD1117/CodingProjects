cmake_minimum_required(VERSION 3.22)
project(PyBind11_Practice)

set(CMAKE_CXX_STANDARD 20)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(deps)

add_executable(PyBindPract main.cpp)
target_link_libraries(PyBindPract ${PYTHON_LIBRARIES})

pybind11_add_module(example_cpp_module main.cpp)
