cmake_minimum_required(VERSION 4.0)
project(Part1Prueba)

set(CMAKE_CXX_STANDARD 20)

add_executable(Part1Prueba main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries")

target_link_libraries(Part1Prueba PRIVATE Overloads)