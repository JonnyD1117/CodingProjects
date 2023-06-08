cmake_minimum_required(VERSION 3.25)
project(TemplateMatcher)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(TemplateMatcher main.cpp TemplateMatcher.h)
target_link_libraries( TemplateMatcher ${OpenCV_LIBS} )

target_include_directories(TemplateMatcher PUBLIC /home/indy/repos/CodingProjects/ComputerVision/TemplateMatching/NormalizedCrossCorrelation)

