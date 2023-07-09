cmake_minimum_required(VERSION 3.25)
project(OpenCVTest)

set(CMAKE_CXX_STANDARD 20)
set(MD_ARRAY_INCLUDE /home/indy/repos/CodingProjects/DataStructures/MultiDimensionalArrays)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} ${MD_ARRAY_INCLUDE} )

add_executable(ImageSimilarityMeasures main.cpp zncc.h ncc.h sad.h ssd.h zncc_new.h ncc_new.h FastNNC.h)
target_link_libraries( ImageSimilarityMeasures ${OpenCV_LIBS} )
target_include_directories(ImageSimilarityMeasures PUBLIC )