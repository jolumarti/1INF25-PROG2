//
// Created by jolumarti on 2026-09-24.
//

#ifndef LAB4_2026_1_ENTEROS_HPP
#define LAB4_2026_1_ENTEROS_HPP
#include "helpers.hpp"

bool read_num(ifstream &file, void *&data);

bool cmp_num(void *data);
void print_num(ofstream &file, void *node, bool first);
#endif //LAB4_2026_1_ENTEROS_HPP
