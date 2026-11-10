//
// Created by jolumarti on 2026-11-10.
//

#include "MetricaBasica.hpp"

void MetricaBasica::copy(MetricaBasica &other) {
    Metrica::copy(other);
    horas_transmitidas = other.horas_transmitidas;
    espectadores_promedio = other.espectadores_promedio;
}

void MetricaBasica::leer(ifstream &file) {
    //BASIC,263905,44,Sesión Games,2025-11-26,2025-12-31,6.5,1116
    Metrica::leer(file);
    char c;
    file >> horas_transmitidas >> c >> espectadores_promedio;
    file.get();
}

void MetricaBasica::imprimir(ofstream &file) const {
    Metrica::imprimir(file);
}
