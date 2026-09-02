//
// Created by jolumarti on 2026-09-01.
//

#ifndef PART1PRUEBA_FUNCIONES_HPP
#define PART1PRUEBA_FUNCIONES_HPP
#include "Overloads.hpp"

void readMascotas(struct SistemaHuellitas &sistema, const char *file_name);

void readVeterinarios(struct SistemaHuellitas &sistema, const char *file_name);

void registerAtenciones(struct SistemaHuellitas &sistema, const char *file_name);

void listaMascotasAEsterilizar(struct SistemaHuellitas &sistema, const char *file_name);

void imprimirMascotasConAtenciones(struct SistemaHuellitas &sistema, const char *file_name);
#endif //PART1PRUEBA_FUNCIONES_HPP
