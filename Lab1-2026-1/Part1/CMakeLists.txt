cmake_minimum_required(VERSION 4.0)
project(Lab1_2026_1)

set(CMAKE_CXX_STANDARD 20)
add_library(Overloads STATIC
        MyLibrary/Overloads.cpp)
add_executable(Lab1_2026_1 main.cpp
        MyLibrary/Utils.hpp
        MyLibrary/Mascota.hpp
        MyLibrary/Veterinario.hpp
        MyLibrary/Atencion.hpp
        MyLibrary/SistemaHuellitas.hpp
        MyLibrary/Overloads.hpp)

target_link_libraries(Lab1_2026_1 PRIVATE Overloads)
