cmake_minimum_required(VERSION 4.3)
project(Fuentes_Bibioteca_2026_2)

set(CMAKE_CXX_STANDARD 20)
add_library(Overloads STATIC Bibliotecas/Overloads.cpp)
add_executable(Fuentes_Bibioteca_2026_2 main.cpp
        Bibliotecas/Almacen.h
        Bibliotecas/Empaque.h
        Bibliotecas/Producto.h
        Bibliotecas/ProductoStock.h
        Bibliotecas/Utils.h
        Bibliotecas/Overloads.h)

target_link_libraries(Fuentes_Bibioteca_2026_2 Overloads)