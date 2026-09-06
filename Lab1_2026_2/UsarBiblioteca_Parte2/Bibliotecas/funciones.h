//
// Created by alulab14 on 4/09/2026.
//

#ifndef PRUEBA_BIBLIOTECA_2026_2_FUNCIONES_H
#define PRUEBA_BIBLIOTECA_2026_2_FUNCIONES_H
#include "Overloads.h"
void cargaProductos(struct Producto *&productos, const char *file_name);
void cargaEmpaques(struct Empaque *&empaques, const char *file_name);
void cargaAlmacenes(struct Almacen *&almacenes, const char *file_name);
void actualizaEmpaqueNombre(struct Almacen *almacenes, struct Empaque *empaques, struct Producto *productos);
void imprimeAlmacen(struct Almacen *almacenes, const char *file_name);

#endif //PRUEBA_BIBLIOTECA_2026_2_FUNCIONES_H
