cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 20)

add_executable(app main.cpp Str_blob.h Str_blob.cpp Str_blob_ptr.h Str_blob_ptr.cpp)

