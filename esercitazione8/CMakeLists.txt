cmake_minimum_required(VERSION 3.20)
project(esercitazione8) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(test_unidirected_graph test_unidirected_graph.cpp)
add_executable(test_unidirected_graph ${test_unidirected_graph})
add_test(NAME unidirected_graph COMMAND test_unidirected_graph)



enable_testing()