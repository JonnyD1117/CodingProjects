cmake_minimum_required(VERSION 3.25)
project(JsonParser)

set(CMAKE_CXX_STANDARD 20)

add_executable(JsonParser main.cpp JsonParser.h JsonExceptions.h JsonToken.h JsonLexer.h)
