//
// Created by jolumarti on 2026-09-24.
//

#ifndef LAB4_2026_1_REGISTROS_HPP
#define LAB4_2026_1_REGISTROS_HPP
#include "helpers.hpp"

void print_reg(ofstream &file, void *node, bool first);

bool cmp_reg(void *node);

bool read_reg(ifstream &file, void *&data);
#endif //LAB4_2026_1_REGISTROS_HPP
