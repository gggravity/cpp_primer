cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 17)

#find_package(Boost REQUIRED)

add_executable(app main.cpp String.cpp String.h Str_blob_ptr.cpp Str_blob_ptr.h Str_blob.cpp Str_blob.h string_vector.h string_vector.cpp employee.cpp employee.h)

#target_link_libraries(app ${Boost_LIBRARIES})

