//
// Created by jolumarti on 2026-10-29.
//

#include "Empresa.hpp"

void Empresa::set_nombre(const char *nombre) {
    Helpers::set_str(this->nombre, nombre);
}

void Empresa::get_nombre(char *nombre) const {
    Helpers::get_str(this->nombre, nombre);
}

bool Empresa::find_placa(const char *placa) const {
    for (int i = 0; i < numPlacas; i++) {
        if (strcmp(this->placa[i], placa) == 0) {
            return true;
        }
    }
    return false;
}

Empresa::Empresa() {
    nombre = nullptr;
    numMultas = 0;
    numPlacas = 0;
    for (int i = 0; i < 10; i++) {
        placa[i] = nullptr;
    }
}

Empresa::~Empresa() {
    delete[] nombre;
    for (int i = 0; i < 10; i++) {
        delete[] placa[i];
    }
}

void Empresa::setPlacaI(const char *placa, int i) {
    Helpers::set_str(this->placa[i], placa);
}

void Empresa::getPlacaI(char *placa, int i) const {
    Helpers::get_str(this->placa[i], placa);
}

bool Empresa::read(ifstream &i) {
    char c, buffer[M_BUFFER];
    i >> dni >> c;
    if (i.eof()) return false;
    i.getline(buffer, M_BUFFER, ',');
    set_nombre(buffer);
    while (true) {
        i >> setw(9) >> buffer;
        setPlacaI(buffer, numPlacas);
        numPlacas++;
        if (i.get() == '\n') break;
    }
    return true;
}

void Empresa::print(ofstream &o) const {
    o << setw(10) << dni << "  " << left << setw(40) << nombre;
    for (int i = 0; i < numPlacas; i++) {
        o << setw(10) << placa[i];
    }
    o << right << endl <<
            setw(14) << "Placa" <<
            setw(23) << "Fecha de Infraccion" <<
            setw(23) << "Codigo de Infraccion" <<
            setw(8) << "Multa" <<
            setw(16) << "Fecha de pago" << endl;
    for (int i = 0; i < numMultas; i++) {
        o << multas[i];
    }
}

void Empresa::operator+=(const Multa &multa) {
    multas[numMultas++] = multa;
}

bool operator>>(ifstream &i, Empresa &empresa) {
    return empresa.read(i);
}

void operator<<(ofstream &o, const Empresa &empresa) {
    empresa.print(o);
}
