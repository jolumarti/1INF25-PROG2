//
// Created by jolumarti on 2026-11-06.
//

#include "NoUrgencia.hpp"

void NoUrgencia::leer(ifstream &file, int hour) {
    Atencion::leer(file, hour);
    getline(file, especialidad, ',');
    file >> es_consulta_programada;
    file.get();
}

void NoUrgencia::imprimir(ofstream &file) {
    Atencion::imprimir(file);
    file << setw(10) << especialidad << setw(10) << es_consulta_programada << endl;
}

int NoUrgencia::obtener_prioridad() {
    return 3;
}
