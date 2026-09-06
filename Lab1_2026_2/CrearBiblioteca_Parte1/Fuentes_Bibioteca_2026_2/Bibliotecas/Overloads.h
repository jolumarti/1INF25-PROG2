//
// Created by alulab14 on 4/09/2026.
//

#ifndef FUENTES_BIBIOTECA_2026_2_OVERLOADS_H
#define FUENTES_BIBIOTECA_2026_2_OVERLOADS_H
#include "Utils.h"
#include "Almacen.h"
#include "Empaque.h"
#include "Producto.h"
#include "ProductoStock.h"

bool operator>>(ifstream &file, struct Producto &producto);

bool operator>>(ifstream &file, struct Empaque &empaque);

int operator!=(const struct Almacen *almacenes, const struct Almacen &almacen);

void operator+=(struct Almacen &almacen, const struct ProductoStock &productoStock);

void operator||(struct ProductoStock &productoStock, const struct Producto *productos);

void operator&&(struct ProductoStock &productoStock, const struct Empaque *empaques);

void operator<=(struct Almacen &almacen, struct Empaque *empaques);

void operator<=(struct Almacen &almacen, struct Producto *productos);

ostream &operator<<(ostream &file, const struct ProductoStock &productoStock);

ostream &operator<<(ostream &file, const struct Almacen &almacen);


#endif //FUENTES_BIBIOTECA_2026_2_OVERLOADS_H
