//
// Created by jolumarti on 2026-11-10.
//

#include "Metrica.hpp"

void Metrica::copy(Metrica &other) {
    id = other.id;
    descripcion = other.descripcion;
    fecha_calculo = other.fecha_calculo;
    fecha_expiracion = other.fecha_expiracion;
    estado = other.estado;
}

void Metrica::leer(ifstream &file) {
    char c;
    int dd, mm, yy;
    file >> id >> c;
    getline(file, descripcion, ',');
    file >> yy >> c >> mm >> c >> dd >> c;
    fecha_calculo = Helpers::date_to_int(dd, mm, yy);
    file >> yy >> c >> mm >> c >> dd >> c;
    fecha_expiracion = Helpers::date_to_int(dd, mm, yy);
    estado = (fecha_expiracion < 20260101);
}

void Metrica::imprimir(ofstream &file) const {
    file << id <<
        setw(10) << descripcion<<
        setw(10) << fecha_calculo <<
            setw(10) << fecha_expiracion <<
                setw(10) << (estado ? "Activo" : "Inactivo") << endl;
}
