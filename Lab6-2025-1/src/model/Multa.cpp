//
// Created by jolumarti on 2026-10-29.
//

#include "Multa.hpp"

void Multa::set_placa(const char *placa) {
    Helpers::set_str(this->placa, placa);
}

void Multa::get_placa(char *placa) const {
    Helpers::get_str(this->placa, placa);
}

int Multa::get_codigoInfraccion() const {
    return codigoInfraccion;
}

void Multa::copy(const Multa &other) {
    set_placa(other.placa);
    fechaDeInfraccion = other.fechaDeInfraccion;
    fechaDePago = other.fechaDePago;
    codigoInfraccion = other.codigoInfraccion;
    multa = other.multa;
}

Multa::Multa() {
    fechaDeInfraccion = 0;
    fechaDePago = 0;
    placa = nullptr;
}

Multa::Multa(Multa &other): Multa() {
    copy(other);
}

Multa::~Multa() {
    delete[] placa;
}

bool Multa::read(ifstream &i) {
    int dd, mm, yy;
    char c, buffer[M_BUFFER];
    i >> dd >> c >> mm >> c >> yy >> c;
    if (i.eof()) return false;
    i.getline(buffer, M_BUFFER, ',');
    fechaDeInfraccion = Helpers::date_to_int(dd, mm, yy);
    set_placa(buffer);
    i >> codigoInfraccion;
    if (i.get() == '\n') return true;
    if (i.get() == 'P') {
        i >> c >> dd >> c >> mm >> c >> yy;
        fechaDePago = Helpers::date_to_int(dd, mm, yy);
        i.get();
    }
    return true;
}

void Multa::print(ofstream &o) const {
    o << setw(16) << placa << setw(6) <<" ";
    Helpers::print_date(o, fechaDeInfraccion);
    o << setw(20) << codigoInfraccion <<
            setw(16) << multa << "   ";
    if (fechaDePago != 0) Helpers::print_date(o, fechaDePago);
    o << endl;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

void Multa::operator=(const Multa &other) {
    copy(other);
}

bool operator>>(ifstream &i, Multa &multa) {
    return multa.read(i);
}

void operator<<(ofstream &o, const Multa &multa) {
    multa.print(o);
}
