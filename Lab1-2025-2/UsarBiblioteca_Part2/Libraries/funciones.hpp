//
// Created by jolumarti on 2026-09-03.
//

#ifndef USARBIBLIOTECA_PART2_FUNCIONES_HPP
#define USARBIBLIOTECA_PART2_FUNCIONES_HPP
#include "Overloads.hpp"
void readAlumnos(struct Alumnos *alumnos, const char *file_name);
void readCursos(struct Cursos *cursos, const char *file_name);
void printCursos(struct Cursos *cursos, const char *file_name);
void processMatricula(struct Cursos *cursos, const struct Alumnos *alumnos, const char *file_name);
#endif //USARBIBLIOTECA_PART2_FUNCIONES_HPP