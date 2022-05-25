cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 20)

#add_executable(app main.cpp TextQuery.cpp TextQuery.h QueryResult.cpp QueryResult.h)
add_executable(app e_12_28.cpp ../section_12.3.2/QueryResult.cpp ../section_12.3.2/QueryResult.h ../section_12.3.2/TextQuery.cpp ../section_12.3.2/TextQuery.h)
