//
// Created by jolumarti on 2026-11-06.
//

#include "Urgencia.hpp"

void Urgencia::leer(ifstream &file, int hour) {
    Atencion::leer(file, hour);
    getline(file, zona_lesion, ',');
    file >> necesita_rx;
    file.get();
}

void Urgencia::imprimir(ofstream &file) {
    Atencion::imprimir(file);
    file << setw(10) << zona_lesion << setw(10) << necesita_rx << endl;

}

int Urgencia::obtener_prioridad() {
    return 2;
}
