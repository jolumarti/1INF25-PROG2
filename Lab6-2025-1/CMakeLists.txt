cmake_minimum_required(VERSION 4.3)
project(Lab6_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6_2025_2 main.cpp
        src/Helpers.cpp
        src/Helpers.hpp
        src/model/Infraccion.cpp
        src/model/Infraccion.hpp
        src/model/Empresa.cpp
        src/model/Empresa.hpp
        src/model/Multa.cpp
        src/model/Multa.hpp
        src/model/MinisterioDeTransporte.cpp
        src/model/MinisterioDeTransporte.hpp)
