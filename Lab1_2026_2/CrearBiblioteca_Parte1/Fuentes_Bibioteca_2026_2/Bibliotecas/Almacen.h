//
// Created by anaro on 3/09/2026.
//

#ifndef FUENTES_BIBIOTECA_2026_2_ALMACEN_H
#define FUENTES_BIBIOTECA_2026_2_ALMACEN_H
#include "ProductoStock.h"
struct Almacen {
    char *codigo;
    int numeroProdutos;
    struct ProductoStock producto_stock[200];
};
#endif //FUENTES_BIBIOTECA_2026_2_ALMACEN_H
