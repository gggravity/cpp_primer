cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 20)

add_executable(app main.cpp QueryResult.h QueryResult.cpp TextQuery.h TextQuery.cpp)

