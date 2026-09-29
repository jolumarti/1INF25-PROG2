#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "helpers.hpp"

void cargarPacientes(const char* file_name, void*& pacientes);
void cargarVisitas(const char* file_name, void* pacientes);
void generarReporte(const char *file_name, void *pacientes);

#endif //FUNCTIONS_HPP
