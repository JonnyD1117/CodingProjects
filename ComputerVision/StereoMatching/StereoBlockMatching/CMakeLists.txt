cmake_minimum_required(VERSION 3.25)
project(StereoBlockMatching)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(StereoBlockMatching main.cpp StereoBlockMatcher.h)

target_link_libraries( StereoBlockMatching ${OpenCV_LIBS} )
target_include_directories(StereoBlockMatching PUBLIC /home/indy/repos/CodingProjects/ComputerVision/TemplateMatching/NormalizedCrossCorrelation)
