cmake_minimum_required(VERSION 4.3)
project(Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab main.cpp
        src/common.hpp
        src/model/Mascota.cpp
        src/model/Mascota.hpp
        src/model/VacunaAplicada.cpp
        src/model/VacunaAplicada.hpp
        src/model/Veterinaria.cpp
        src/model/Veterinaria.hpp
        src/model/Mascota.cpp
        src/Helpers.cpp
        src/Helpers.hpp
)
