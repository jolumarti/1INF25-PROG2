//
// Created by jolumarti on 9/8/26.
//

#ifndef LAB2_2025_2_FUNCTIONS_HPP
#define LAB2_2025_2_FUNCTIONS_HPP
#include "auxFunctions.hpp"

void cargarCategorias(const char *file_name, char ***&categorias);

void cargarStreamers(const char *file_name, char ***&streamers, int **&fechasPromedios,
                     long long **&tiempoRepSeguidores);

void cargarComentarios(const char *file_name, char ***&comentarios, char ***&etiquetas);
void imprimirReporte(const char *file_name, char ***categorias, char ***streamers, int **fechasPromedios,
                 long long **tiempoRepSegidores, char ***comentarios, char ***etiquetas);
#endif //LAB2_2025_2_FUNCTIONS_HPP
