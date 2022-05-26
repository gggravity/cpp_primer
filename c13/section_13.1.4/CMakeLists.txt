cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

add_executable(app main.cpp)

target_link_libraries(app ${Boost_LIBRARIES})

