//
// Created by jolumarti on 2026-10-07.
//

#include "Mascota.hpp"

Mascota::Mascota() {
    nombre = nullptr;
    especie = nullptr;
    colegiatura = nullptr;
    dni = 0;
    edad = 0;
    peso = 0.0;
    numVacunas = 0;
}

Mascota::~Mascota() {
    delete[] nombre;
    delete[] especie;
    delete[] colegiatura;
}

int Mascota::get_dni() const {
    return dni;
}

void Mascota::set_dni(int dni) {
    this->dni = dni;
}

void Mascota::set_nombre(const char *nombre) {
    Helpers::set_str(this->nombre, nombre);
}

void Mascota::set_especie(const char *especie) {
    Helpers::set_str(this->especie, especie);
}

void Mascota::set_edad(int edad) {
    this->edad = edad;
}

void Mascota::set_peso(double peso) {
    this->peso = peso;
}

void Mascota::set_colegiatura(const char *colegiatura) {
    Helpers::set_str(this->colegiatura, colegiatura);
}

void Mascota::set_num_vacunas(int num_vacunas) {
    numVacunas = num_vacunas;
}

void Mascota::get_nombre(char * nombre) const {
    Helpers::get_str( this->nombre, nombre);
}

void Mascota::get_especie(char *especie) const{
    Helpers::get_str(this->especie, especie);
}

int Mascota::get_edad() const {
    return edad;
}

double Mascota::get_peso() const {
    return peso;
}

void Mascota::get_colegiatura(char *colegiatura) const {
    Helpers::get_str(this->colegiatura, colegiatura);
}

int Mascota::get_num_vacunas() const {
    return numVacunas;
}
bool Mascota::read(istream &file) {
    //11223344,Michi,Gato,4,5.1,CMVP-6002
    char cstr[S_BUFFER], c;
    file >> dni>>c;
    if (file.eof()) return false;
    file.getline(cstr, S_BUFFER, ',');
    set_nombre(cstr);
    file.getline(cstr, S_BUFFER, ',');
    set_especie(cstr);
    file >> edad >> c >> peso >> c;
    file.getline(cstr, S_BUFFER, '\n');
    set_colegiatura(cstr);
    return true;
}



void Mascota::operator=(const Mascota &other) {
    set_nombre(other.nombre);
    set_especie(other.especie);
    set_colegiatura(other.colegiatura);
    dni = other.dni;
    edad = other.edad;
    peso = other.peso;
    numVacunas = other.numVacunas;
    for (int i = 0; i < numVacunas; i++) {
        listaVacunas[i] = other.listaVacunas[i];
    }
}

void Mascota::operator+=(const VacunaAplicada &vacuna) {
    listaVacunas[numVacunas++] = vacuna;
}

bool Mascota::operator~() {
    for (int i=0; i < numVacunas-1; i++) {
        for (int j=i+1; j < numVacunas; j++) {
            if (listaVacunas[i] == listaVacunas[j]) {
                return true;
            }
        }
    }
    return false;
}
void Mascota::print(ostream &file) {
    file << "Mascota: " << nombre << " (" << especie << ", " << edad <<
        " año" << (edad>1?"s":"")  << ", " << peso << " kg)\n";
}

void Mascota::print_vacunas(ostream &file) {
    file << "Vacunas:\n";
    for (int j= 0; j < numVacunas; ++j) {
        VacunaAplicada &vacuna = listaVacunas[j];
        file << vacuna;
    }
    if (!numVacunas) file << "   No hay vacunas aplicadas\n";
}

bool operator>>(istream &file, Mascota &mascota) {
    return mascota.read(file);
}
void operator<<(ostream &file, Mascota &mascota) {
    mascota.print(file);
}
