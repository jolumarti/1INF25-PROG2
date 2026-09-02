//
// Created by jolumarti on 2026-09-03.
//

#ifndef FUENTES_BIBLIOTECA_2025_2_OVERLOADS_HPP
#define FUENTES_BIBLIOTECA_2025_2_OVERLOADS_HPP
#include "Estructuras.h"
#include "Utils.hpp"
void operator>>(ifstream &input, struct Cursos &curso);
void operator>>(ifstream &input, struct Alumnos &alumno);
bool operator>(const struct Alumnos &alumno, const int codigo);
bool operator>(const struct Cursos &curso, const char *codigo);
bool operator+=(struct Cursos &curso, const struct Alumnos &alumno);
int operator<=(const struct Alumnos *alumnos, const struct Alumnos &alumno);
int operator<=(const struct Cursos *cursos, const struct Cursos &curso);
void operator++ (struct Cursos &curso);
void operator <<(ostream &output, const struct Cursos &curso);
#endif //FUENTES_BIBLIOTECA_2025_2_OVERLOADS_HPP