//
// Created by alulab14 on 25/09/2026.
//

#ifndef PUNTEROGENERICOS_2026_2_FUNC_H
#define PUNTEROGENERICOS_2026_2_FUNC_H
#include "utils.h"
void cargarProductos(const char *file_name, void*& productos);
void cargarEmpaques(const char *file_name, void* productos);
void generarReporte(const char *file_name, void* productos);
#endif //PUNTEROGENERICOS_2026_2_FUNC_H
