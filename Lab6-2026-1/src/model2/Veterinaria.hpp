//
// Created by jolumarti on 2026-10-07.
//

#ifndef LAB5_2026_1_VETERINARIA_HPP
#define LAB5_2026_1_VETERINARIA_HPP
#include "Mascota.hpp"

class Veterinaria {
    Mascota *listaMascotas;
    int numMascotas;

    void resize_list(int cap);
    int find_mascota(int dni, const char* nombre);
public:
    Veterinaria();

    ~Veterinaria();

    void operator<=(const char *filename);
    void operator<<=(const char *filename);
    void operator<<(const char *filename);
};


#endif //LAB5_2026_1_VETERINARIA_HPP
