cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 17)

#find_package(Boost REQUIRED)

add_executable(app main.cpp Sales_data.h Sales_data.cpp employee.cpp employee.h String.h String.cpp)

#target_link_libraries(app ${Boost_LIBRARIES})

