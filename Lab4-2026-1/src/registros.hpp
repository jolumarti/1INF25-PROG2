//
// Created by jolumarti on 2026-09-24.
//

#ifndef LAB4_2026_1_REGISTROS_HPP
#define LAB4_2026_1_REGISTROS_HPP
#include "helpers.hpp"
bool leerRegistro(ifstream& file,  void *&data);
int compararReg(const void *data1, const void *data2);
void imprimeReg(ofstream &file, void **node);
#endif //LAB4_2026_1_REGISTROS_HPP
