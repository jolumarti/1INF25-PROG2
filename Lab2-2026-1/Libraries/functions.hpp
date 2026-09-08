//
// Created by jolumarti on 9/1/26.
//

#ifndef LAB2_2026_2_FUNCTIONS_HPP
#define LAB2_2026_2_FUNCTIONS_HPP
#include "auxFunctions.hpp"
void cargarInformacion(const char *fileName, int *&fechas, char ***&datosDeTexto,
                       int **&datosEnteros, float **&datosDePuntoFlotante);
void completarInformacion(int **&datosEnteros, float **&datosDePuntoFlotante);
void reporteDeAtenciones(const char *fileName,  int *fechas, char ***datosDeTexto,
                          int **datosEnteros,  float **datosDePuntoFlotante);

#endif //LAB2_2026_2_FUNCTIONS_HPP
