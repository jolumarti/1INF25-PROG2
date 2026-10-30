cmake_minimum_required(VERSION 4.3)
project(Lab6_2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab6_2026_1 main.cpp
        src/Helpers.cpp
        src/Helpers.hpp
        src/model/Mascota.cpp
        src/model/Mascota.hpp
        src/model/Cita.cpp
        src/model/Cita.hpp
        src/model/Control.cpp
        src/model/Control.hpp
        src/model/Operacion.cpp
        src/model/Operacion.hpp
        src/model/Vacuna.cpp
        src/model/Vacuna.hpp
        src/model/Veterinaria.cpp
        src/model/Veterinaria.hpp)
