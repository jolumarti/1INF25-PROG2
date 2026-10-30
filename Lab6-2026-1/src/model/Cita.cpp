//
// Created by jolumarti on 10/27/26.
//

#include "Cita.hpp"

int Cita::get_fecha() const {
    return fecha;
}

void Cita::set_fecha(int fecha) {
    this->fecha = fecha;
}

int Cita::get_hora() const {
    return hora;
}

void Cita::set_hora(int hora) {
    this->hora = hora;
}

void Cita::copy(const Cita &other) {
    fecha = other.fecha;
    hora = other.hora;
    Amascota.copy(other.Amascota);
}

Cita::Cita() {
    fecha = 0;
    hora = 0;
}

Cita::~Cita() {

}
//C,7/04/2025,11,101,Luna,C,Labrador,1222,20
/*Tipo_de_cita,fecha,hora,
 *cód_de_mascota, nombre,tipo,raza,
 *médico/total/dosis,monto/anestesia/meses,núm._de_médicos */

void Cita::read(istream &i) {
    int dd, mm, yy;
    char c;
    i >> c >> dd >> c >> mm >> c >> yy >> c >> hora >> c;
    fecha = yy*10000 + mm*100 + dd;
    Amascota.read(i);
}

void Cita::print(ostream &o) const {
    int dd, mm, yy;
    yy  = fecha / 10000;
    mm  = (fecha / 100) % 100;
    dd  = fecha % 100;
    o << yy << '.' << setfill('0') << setw(2) << mm << '.' << setw(2) << dd  << "  " <<
      setw(2) << hora << ":00" << setfill(' ') << "  ";
    Amascota.print(o);
}
