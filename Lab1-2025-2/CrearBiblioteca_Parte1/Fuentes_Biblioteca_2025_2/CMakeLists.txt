cmake_minimum_required(VERSION 4.0)
project(Fuentes_Biblioteca_2025_2)

set(CMAKE_CXX_STANDARD 20)
add_library(Overloads STATIC MyLibrary/Overloads.cpp)
add_executable(Fuentes_Biblioteca_2025_2 main.cpp
        MyLibrary/Estructuras.h
        MyLibrary/Overloads.hpp
        MyLibrary/Utils.hpp)
target_link_libraries(Fuentes_Biblioteca_2025_2 Overloads)
