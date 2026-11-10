//
// Created by jolumarti on 2026-11-06.
//

#include "Emergencia.hpp"

void Emergencia::leer(ifstream &file, int hour) {
    Atencion::leer(file, hour);
    char c;
    file >> requiere_rcp >> c >> minutos_sin_pulso;
    file.get();
}

void Emergencia::imprimir(ofstream &file) {
    Atencion::imprimir(file);
    file << setw(10) << requiere_rcp << setw(10) << minutos_sin_pulso << endl;
}

int Emergencia::obtener_prioridad() {
    return 1;
}
