//
// Created by jolumarti on 10/27/26.
//

#include "Mascota.hpp"

Mascota::Mascota() {
    nombre = nullptr;
    raza = nullptr;
}

Mascota::~Mascota() {
    delete[] nombre;
    delete[] raza;
}

int Mascota::get_codigo() const {
    return codigo;
}

void Mascota::set_codigo(const int codigo) {
    this->codigo = codigo;
}


char Mascota::get_tipo() const {
    return tipo;
}

void Mascota::set_tipo(const char tipo) {
    this->tipo = tipo;
}

void Mascota::get_nombre(char *nombre) const {
    Helpers::get_str(this->nombre, nombre);
}

void Mascota::set_nombre(const char *nombre) {
    Helpers::set_str(this->nombre, nombre);
}

void Mascota::get_raza(char *raza) const {
    Helpers::get_str(this->raza, raza);
}

void Mascota::set_raza(const char *raza) {
    Helpers::set_str(this->raza, raza);
}

//C,7/04/2025,11,101,Luna,C,Labrador,1222,20
/*Tipo_de_cita,fecha,hora,
 *cód_de_mascota, nombre,tipo,raza,
 *médico/total/dosis,monto/anestesia/meses,núm._de_médicos */
void Mascota::read(istream &i) {
    char buffer[M_BUFFER], c;
    i >> codigo >> c;
    i.getline(buffer, M_BUFFER, ',');
    set_nombre(buffer);
    i >> tipo >> c;
    i.getline(buffer, M_BUFFER, ',');
    set_raza(buffer);
}

void Mascota::print(ostream &o) const{
    o << left << setw(20) << raza << setw(16) << nombre << right;
}

void Mascota::copy(const Mascota &other) {
    codigo = other.codigo;
    tipo = other.tipo;
    if (other.nombre) set_nombre(other.nombre);
    else {
        delete[] nombre;
        nombre = nullptr;
    }
    if (other.raza) set_raza(other.raza);
    else {
        delete[] raza;
        raza = nullptr;
    }
}
