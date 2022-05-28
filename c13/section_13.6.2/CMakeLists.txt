cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 14)

#find_package(Boost REQUIRED)

add_executable(app main.cpp String.cpp String.h message.cpp message.h folder.cpp folder.h string_vector.cpp string_vector.h)

#target_link_libraries(app ${Boost_LIBRARIES})

