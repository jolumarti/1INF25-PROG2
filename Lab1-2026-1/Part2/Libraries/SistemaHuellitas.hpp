//
// Created by jolumarti on 2026-09-01.
//

#ifndef LAB1_2026_1_SISTEMAHUELLITAS_HPP
#define LAB1_2026_1_SISTEMAHUELLITAS_HPP
#include "Mascota.hpp"
#include "Veterinario.hpp"
#include "Atencion.hpp"

struct SistemaHuellitas {
    struct Mascota *mascotas;
    int numeroMascotas;
    struct Veterinario *veterinarios;
    int numeroVeterinarios;
    struct Atencion *atenciones;
    int numeroAtenciones;
};
#endif //LAB1_2026_1_SISTEMAHUELLITAS_HPP