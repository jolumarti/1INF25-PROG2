cmake_minimum_required(VERSION 4.0)
project(Prueba_Biblioteca_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Biblioteca_2025_2 main.cpp
        Libraries/Overloads.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries")
target_link_libraries(Prueba_Biblioteca_2025_2 PRIVATE Overloads)
