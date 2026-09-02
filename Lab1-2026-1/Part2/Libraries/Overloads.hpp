//
// Created by jolumarti on 2026-09-01.
//

#ifndef LAB1_2026_1_OVERLOADS_HPP
#define LAB1_2026_1_OVERLOADS_HPP
#include "SistemaHuellitas.hpp"

bool operator>>(ifstream &input, struct Mascota &mascota);
bool operator>>(ifstream &input, struct Veterinario &veterinario);
bool operator>>(ifstream &input, struct Atencion &atencion);
bool operator==(const struct Atencion &a1, const struct Atencion &a2);
bool operator<=(const struct Mascota &mascota, const int fecha);
ofstream &operator<<(ofstream &output, const struct Mascota &mascota);
ofstream &operator<<(ofstream &output, const struct Atencion &atencion);
#endif //LAB1_2026_1_OVERLOADS_HPP