cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 11)

#find_package(Boost REQUIRED)

add_executable(app main.cpp
        Str_blob_ptr.cpp Str_blob_ptr.h
        Str_blob.cpp Str_blob.h
        Const_str_blob_ptr.h Const_str_blob_ptr.cpp)

#target_link_libraries(app ${Boost_LIBRARIES})

