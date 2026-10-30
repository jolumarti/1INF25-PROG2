//
// Created by jolumarti on 10/27/26.
//

#include "Control.hpp"

Control::Control() {

}

void Control::read(istream &i) {
    char c;
    Cita::read(i);
    i >> codmed >> c >> costo;
    i.get();
}

void Control::print(ostream &o) const {
    Cita::print(o);
    o << setw(10) << codmed << setw(10) << costo << endl;
}

double Control::get_costo() const {
    return costo;
}

void Control::set_costo(const double costo) {
    this->costo = costo;
}

int Control::get_codmed() const {
    return codmed;
}

void Control::set_codmed(const int codmed) {
    this->codmed = codmed;
}

void Control::copy(const Control &other) {
    codmed = other.codmed;
    costo = other.costo;
    Cita::copy(other);
}
