cmake_minimum_required(VERSION 4.3)
project(UsarBiblioteca_Parte2)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsarBiblioteca_Parte2 main.cpp
        Bibliotecas/Producto.h
        Bibliotecas/ProductoStock.h
        Bibliotecas/Empaque.h
        Bibliotecas/Almacen.h
        Bibliotecas/Overloads.h
        Bibliotecas/funciones.h
        Bibliotecas/funciones.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")
target_link_libraries(UsarBiblioteca_Parte2 PRIVATE Overloads)