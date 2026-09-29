//
// Created by jolumarti on 2026-09-24.
//

#ifndef LAB4_2026_1_GENERICOS_HPP
#define LAB4_2026_1_GENERICOS_HPP
#include "helpers.hpp"
void procesarArreglo(void **array, bool (*read_fun)(ifstream &, void *&), const char* file_name);
void generaLista(void *&list);
void insertarLista(void *list, void *data);
void crearLista(void **array, void *&list, int (*cmp) (const void *,const void *));
#endif //LAB4_2026_1_GENERICOS_HPP
