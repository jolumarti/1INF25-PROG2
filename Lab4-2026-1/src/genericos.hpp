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
void fusionaListas(void *list1, void *list2, int (*cmp)(const void *, const void *));
void imprimeLista(void *list, void (*print_fun)(ofstream &, void **), const char* file_name);
#endif //LAB4_2026_1_GENERICOS_HPP
