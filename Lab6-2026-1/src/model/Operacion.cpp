//
// Created by jolumarti on 10/27/26.
//

#include "Operacion.hpp"

Operacion::Operacion() {
}

bool Operacion::is_anestesiageneral() const {
    return anestesiageneral;
}

void Operacion::set_anestesiageneral(bool anestesiageneral) {
    this->anestesiageneral = anestesiageneral;
}

int Operacion::get_nummedicos() const {
    return nummedicos;
}

void Operacion::set_nummedicos(int nummedicos) {
    this->nummedicos = nummedicos;
}

double Operacion::get_total() const {
    return total;
}

void Operacion::set_total(double total) {
    this->total = total;
}

Operacion::~Operacion() {
}

//O,25/04/2026,10,110,LuisXV,F,Siberiano,150,1,2

/*total,anestesia,núm._de_médicos */

void Operacion::read(istream &i) {
    char c;
    Cita::read(i);
    i >> total >> c >> anestesiageneral >> c >> nummedicos;
    i.get();
}

void Operacion::print(ostream &o) const {
    Cita::print(o);
    o << setw(10) << (anestesiageneral? "General" : "Parcial") << setw(14) << nummedicos << endl;
}

