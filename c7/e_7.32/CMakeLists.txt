cmake_minimum_required(VERSION 3.20)
project(e_7_32)

set(CMAKE_CXX_STANDARD 20)

add_executable(e_7_32 main.cpp
        Screen.h Screen.cpp
        Window_manager.cpp Window_manager.h
        )
