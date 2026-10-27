//
// Created by jolumarti on 2026-10-07.
//

#include "VacunaAplicada.hpp"

VacunaAplicada::VacunaAplicada() {
    nombre = nullptr;
    colegiatura = nullptr;
    fecha = 0;
    dosis = 0.0;
}

VacunaAplicada::~VacunaAplicada() {
    delete[] nombre;
    delete[] colegiatura;
}

void VacunaAplicada::get_nombre(char *nombre) const {
    Helpers::get_str(this->nombre, nombre);
}

void VacunaAplicada::set_nombre(const char *nombre) {
    Helpers::set_str(this->nombre, nombre);
}

int VacunaAplicada::get_fecha() const {
    return fecha;
}

void VacunaAplicada::set_fecha(const int fecha) {
    this->fecha = fecha;
}

double VacunaAplicada::get_dosis() const {
    return dosis;
}

void VacunaAplicada::set_dosis(const double dosis) {
    this->dosis = dosis;
}

void VacunaAplicada::get_colegiatura(char *colegiatura) const {
    Helpers::get_str(this->colegiatura, colegiatura);
}

void VacunaAplicada::set_colegiatura(const char *colegiatura) {
    Helpers::set_str(this->colegiatura, colegiatura);
}

bool VacunaAplicada::read(istream &file) {
    //Firulais,12345678,Rabia,20250110,1.5,CMVP-1001
    char cstr[S_BUFFER], c;
    file.getline(cstr, S_BUFFER, ',');
    if (file.eof()) return false;
    set_nombre(cstr);
    file >> fecha >> c >> dosis >> c;
    file.getline(cstr, S_BUFFER, '\n');
    set_colegiatura(cstr);
    return true;
}

void VacunaAplicada::operator=(const VacunaAplicada &other) {
    set_nombre(other.nombre);
    set_colegiatura(other.colegiatura);
    fecha = other.fecha;
    dosis = other.dosis;
}

bool VacunaAplicada::operator==(const VacunaAplicada &other) {
    return strcmp(nombre, other.nombre) == 0 &&
               strcmp(colegiatura, other.colegiatura) == 0 &&
               fecha == other.fecha &&
               dosis == other.dosis;
}

void VacunaAplicada::print(ostream &file) {
    int yy, mm, dd;
    yy = fecha / 10000;
    mm = (fecha % 10000) / 100;
    dd = fecha % 100;
    file << "   - " << nombre << ": " << setfill('0')<< setw(2) << dd << "/"
            << setw(2) << mm << "/" << yy << setfill(' ');
    file << " (" << dosis << " ml, " << colegiatura << ")\n";
}

bool operator>>(istream &file, VacunaAplicada &vacuna_aplicada) {
    return vacuna_aplicada.read(file);
}

void operator<<(ostream &file, VacunaAplicada &vacuna_aplicada) {
    vacuna_aplicada.print(file);
}
