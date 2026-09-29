//
// Created by jolumarti on 2026-09-12.
//

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "aux.hpp"

void cargarVentas(const char *file_name, char ***&ventas);
void cargarDetallesDeVentas(const char *file_name, char ***ventas,
                            char ****&detallesDeVentasTextos, int *** &detallesDeVentasValores);
void completarDetallesDeVentas(const char *file_name, char ***ventas, char ****detallesDeVentasTextos,
                               int ***detallesDeVentasValores);
void imprimirReporte(const char *file_name, char ***ventas, char ****detallesDeVentasTextos,
                     int ***detallesDeVentasValores, bool complete = true);
#endif //FUNCTIONS_HPP
