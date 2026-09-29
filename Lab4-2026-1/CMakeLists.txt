cmake_minimum_required(VERSION 4.3)
project(Lab4_2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4_2026_1 main.cpp
        src/utils.hpp
        src/helpers.cpp
        src/helpers.hpp
        src/genericos.cpp
        src/genericos.hpp
        src/registros.cpp
        src/registros.hpp
        src/enteros.hpp
        src/enteros.cpp
        src/enteros.hpp
)
