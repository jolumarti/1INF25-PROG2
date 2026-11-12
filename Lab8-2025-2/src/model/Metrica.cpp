//
// Created by jolumarti on 2026-11-10.
//

#include "Metrica.hpp"


Metrica::~Metrica() {
}

void Metrica::copy(Metrica &other) {
    id = other.id;
    descripcion = other.descripcion;
    fecha_calculo = other.fecha_calculo;
    fecha_expiracion = other.fecha_expiracion;
    estado = other.estado;
}

void Metrica::leer(ifstream &file) {
    char c;
    int dd, mm, yy, streamId;
    file >> streamId >> c >> id >> c;
    getline(file, descripcion, ',');
    file >> yy >> c >> mm >> c >> dd >> c;
    fecha_calculo = Helpers::date_to_int(dd, mm, yy);
    file >> yy >> c >> mm >> c >> dd >> c;
    fecha_expiracion = Helpers::date_to_int(dd, mm, yy);
    estado = (fecha_expiracion >= 20251114);
}

void Metrica::imprimir(ofstream &file) const {
    file <<  setfill('0') << setw(4) << id<< setfill(' ') << "  " << left <<
            setw(22) << descripcion << right <<
            setw(12) << fecha_calculo <<
            setw(12) << fecha_expiracion <<
            setw(12) << (estado ? "Activo" : "Inactivo");
}

bool Metrica::compare(Metrica *other) {
    return (getType() > other->getType() ||
            (getType() == other->getType() && descripcion > other->descripcion));
}

bool Metrica::getEstado() const {
    return estado;
}
