//
// Created by jolumarti on 2026-09-24.
//

#ifndef LAB4_2026_1_GENERICOS_HPP
#define LAB4_2026_1_GENERICOS_HPP
#include "helpers.hpp"
void generaLista(void *&list, bool (*read_fun)(ifstream &, void *&), bool (*cmp)(void *),
                 const char *file_name);
void imprimeLista(void *list, void (*print_fun)(ofstream &, void *, bool), const char* file_name);

#endif //LAB4_2026_1_GENERICOS_HPP
