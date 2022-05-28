cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 14)

#find_package(Boost REQUIRED)

add_executable(app main.cpp string_vector.cpp string_vector.h TextQuery.h TextQuery.cpp QueryResult.h QueryResult.cpp String.cpp String.h)

#target_link_libraries(app ${Boost_LIBRARIES})

