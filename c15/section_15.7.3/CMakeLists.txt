cmake_minimum_required(VERSION 3.20)
project(app)

set(CMAKE_CXX_STANDARD 20)

#find_package(Boost REQUIRED)

add_executable(app main.cpp quote.cpp quote.h bulk_quote.cpp bulk_quote.h discount_quote.cpp discount_quote.h limited_discount.cpp limited_discount.h)

#target_link_libraries(app ${Boost_LIBRARIES})

