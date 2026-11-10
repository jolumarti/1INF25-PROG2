cmake_minimum_required(VERSION 4.4)
project(Lab7_2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab7_2026_1 main.cpp
    src/Helpers.hpp
    src/Helpers.cpp
        src/model/Atencion.cpp
        src/model/Atencion.hpp
        src/model/GestorAtenciones.cpp
        src/model/GestorAtenciones.hpp
        src/model/Emergencia.cpp
        src/model/Emergencia.hpp
        src/model/Urgencia.hpp
        src/model/Urgencia.cpp
        src/model/NoUrgencia.cpp
        src/model/NoUrgencia.hpp
)
