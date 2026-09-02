cmake_minimum_required(VERSION 4.0)
project(UsarBiblioteca_Part2)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsarBiblioteca_Part2 main.cpp
        Libraries/Overloads.hpp
        Libraries/funciones.cpp
        Libraries/funciones.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Libraries")
target_link_libraries(UsarBiblioteca_Part2 Overloads)