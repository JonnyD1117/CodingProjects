cmake_minimum_required(VERSION 3.22)
project(SimpleClientServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimpleServer server.cpp)
add_executable(SimpleClient client.cpp)
