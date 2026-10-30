//
// Created by jolumarti on 2026-10-29.
//

#include "Infraccion.hpp"

void Infraccion::set_descripcion(const char *descripcion) {
    Helpers::set_str(this->descripcion, descripcion);
}

void Infraccion::get_descripcion(char *descripcion) const {
    Helpers::get_str(this->descripcion, descripcion);
}

void Infraccion::set_gravedad(const char *gravedad) {
    Helpers::set_str(this->gravedad, gravedad);
}

void Infraccion::get_gravedad(char *gravedad) const {
    Helpers::get_str(this->gravedad, gravedad);
}

void Infraccion::copy(const Infraccion &other) {
    set_descripcion(other.descripcion);
    set_gravedad(other.gravedad);
    codigo = other.codigo;
    multa = other.multa;
}

Infraccion::Infraccion() {
    descripcion = nullptr;
    gravedad = nullptr;
}

Infraccion::Infraccion(const Infraccion &other): Infraccion() {
    copy(other);
}

Infraccion::~Infraccion() {
    delete[] descripcion;
    delete[] gravedad;
}

int Infraccion::get_codigo() const {
    return codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

bool Infraccion::read(ifstream &i) {
    char c, buffer[XL_BUFFER];
    i >> codigo >> c;
    if (i.eof()) return false;
    i >> multa >> c;
    i.getline(buffer, XL_BUFFER, ',');
    set_gravedad(buffer);
    i.getline(buffer, XL_BUFFER, '\n');
    set_descripcion(buffer);
    return true;
}

void Infraccion::print(ofstream &o) const {
    o << setw(8) << codigo <<
            setw(10) << multa << "    " << left <<
            setw(13) << gravedad << descripcion << right << endl;
}

void Infraccion::operator=(const Infraccion &other) {
    copy(other);
}


bool operator>>(ifstream &i, Infraccion &infraccion) {
    return infraccion.read(i);
}

void operator<<(ofstream &o, const Infraccion &infraccion) {
    infraccion.print(o);
}
