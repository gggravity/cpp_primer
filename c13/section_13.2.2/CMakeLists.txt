cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 20)

#find_package(Boost REQUIRED)

add_executable(app main.cpp has_ptr.h has_ptr.cpp tree_node.cpp tree_node.h bin_str_tree.cpp bin_str_tree.h)

#target_link_libraries(app ${Boost_LIBRARIES})

