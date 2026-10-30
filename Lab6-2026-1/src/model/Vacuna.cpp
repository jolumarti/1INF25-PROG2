//
// Created by jolumarti on 2026-10-28.
//

#include "Vacuna.hpp"

Vacuna::Vacuna() {
}

Vacuna::~Vacuna() {
}

void Vacuna::read(istream &i) {
    char c;
    Cita::read(i);
    i >> dosis >> c >> meses;
    i.get();
}

void Vacuna::print(ostream &o) const {
    Cita::print(o);
    o << setw(10) << dosis << setw(14) << meses << endl;
}

int Vacuna::get_dosis() const {
    return dosis;
}

void Vacuna::set_dosis(const int dosis) {
    this->dosis = dosis;
}

int Vacuna::get_meses() const {
    return meses;
}

void Vacuna::set_meses(const int meses) {
    this->meses = meses;
}
