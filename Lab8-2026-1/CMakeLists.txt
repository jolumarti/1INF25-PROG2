cmake_minimum_required(VERSION 4.4)
project(Lab8_2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab8_2026_1 main.cpp
        utils/Utils.cpp
        utils/Utils.hpp
        src/model/Atencion.cpp
        src/model/Atencion.hpp
        src/model/Emergencia.cpp
        src/model/Emergencia.hpp
        src/model/NoUrgencia.cpp
        src/model/NoUrgencia.hpp
        src/model/Urgencia.cpp
        src/model/Urgencia.hpp
        src/model/GestorAtenciones.cpp
        src/model/GestorAtenciones.hpp
        src/model/Par.cpp
        src/model/Par.hpp
        src/model/Node.cpp
        src/model/Node.hpp
        src/model/List.cpp
        src/model/List.hpp

)
