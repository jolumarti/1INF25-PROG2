cmake_minimum_required(VERSION 4.4)
project(Lab8_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab8_2025_2 main.cpp
        src/Helpers.cpp
        src/Helpers.hpp
        src/model/Metrica.cpp
        src/model/Metrica.hpp
        src/model/MetricaBasica.cpp
        src/model/MetricaBasica.hpp
        src/model/MetricaEngagement.cpp
        src/model/MetricaEngagement.hpp
        src/model/MetricaCalidad.cpp
        src/model/MetricaCalidad.hpp
        src/model/Node.cpp
        src/model/Node.hpp
        src/model/List.cpp
        src/model/List.hpp
        src/model/AdministrarMetricas.cpp
        src/model/AdministrarMetricas.hpp)
