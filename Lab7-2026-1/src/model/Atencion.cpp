//
// Created by jolumarti on 2026-11-05.
//

#include "Atencion.hpp"

Atencion::Atencion() {
}

Atencion::Atencion(Atencion &other) {
    copy(other);
}

Atencion::~Atencion() {
}

void Atencion::copy(Atencion &other) {
    codigo = other.codigo;
    paciente = other.paciente;
    descripcion = other.descripcion;
    hora = other.hora;
}

void Atencion::leer(ifstream &file, int hour) {
    char c;
    hora = hour;
    file >> codigo >> c;
    getline(file, paciente, ',');
    getline(file, descripcion, ',');
}

void Atencion::imprimir(ofstream &file) {
    file << setw(10) << codigo <<
            setw(10) << paciente <<
            setw(10) << descripcion;
}
