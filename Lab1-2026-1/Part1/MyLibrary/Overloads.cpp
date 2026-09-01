//
// Created by jolumarti on 2026-09-01.
//
#include "Overloads.hpp"

int readDate(ifstream &input) {
    int day, month, year;
    char delimiter;
    input >> day >> delimiter >> month >> delimiter >> year;
    return day + month * 100 + year * 10000;
}

char *readLine(ifstream &arch, char delim) {
    char *ptr, cc[MAX_LINE];
    arch.getline(cc, MAX_LINE, delim);
    if (arch.eof()) return nullptr;
    ptr = new char[strlen(cc) + 1];
    strcpy(ptr, cc);
    return ptr;
}

//101,Luna,Labrador,Negro,CANINO,10/10/2024
bool operator>>(ifstream &input, struct Mascota &mascota) {
    input >> mascota.idMascota;
    if (input.eof()) return false;
    input.get();
    mascota.nombre = readLine(input, ',');
    mascota.raza = readLine(input, ',');
    mascota.color = readLine(input, ',');
    mascota.tipo = readLine(input, ',');
    mascota.fechaNacimiento = readDate(input);
    input.get();
    return true;
}

//201,Miguel Perez,MedicinaGeneral
bool operator>>(ifstream &input, struct Veterinario &veterinario) {
    input >> veterinario.idVeterinario;
    if (input.eof()) return false;
    input.get();
    veterinario.nombre = readLine(input, ',');
    veterinario.especialidad = readLine(input, ',');
    input.get();
    return true;
}

//01,204,7/4/2025,CONTROL,11:00,PROGRAMADA
bool operator>>(ifstream &input, struct Atencion &atencion) {
    char c;
    input >> atencion.idMascota >> c;
    if (input.eof()) return false;
    input >> atencion.idVeterinario >> c;
    atencion.fecha = readDate(input);
    input >> c;
    atencion.tipo = readLine(input, ',');
    input >> atencion.hora >> c >> atencion.minutos >> c;
    atencion.estado = readLine(input, '\n');
    return true;
}

bool operator==(const struct Atencion &a1, const struct Atencion &a2) {
    // solo se necesita comparar para saber si la atencion en ese horario con ese veterinario esta disponible.
    return ( //a1.idMascota == a2.idMascota &&
        a1.idVeterinario == a2.idVeterinario &&
        a1.fecha == a2.fecha &&
        a1.hora == a2.hora &&
        a1.minutos == a2.minutos);
}

bool operator<=(const struct Mascota &mascota, const int fecha) {
    return mascota.fechaNacimiento <= fecha;
}

ofstream &operator<<(ofstream &output, const struct Mascota &mascota) {
    output << "ID: " << mascota.idMascota << endl <<
        setw(6) << ' ' << "Nombre: " << mascota.nombre << endl <<
        setw(6) << ' ' << "Raza: " << mascota.raza << endl <<
        setw(6) << ' ' << "Color: " << mascota.color << endl <<
        setw(6) << ' ' << "Tipo: " << mascota.tipo << endl ;
    return output;
}
ofstream &operator<<(ofstream &output, const struct Atencion &atencion) {
    output << "Fecha: " << atencion.fecha << ", " <<
        "ID: " << atencion.idAtencion << ", " <<
        "ID Veterinario: " << atencion.idVeterinario << ", " <<
        "Tipo: " << atencion.tipo << ", " <<
        "Estado: " << atencion.estado << endl;
    return output;
}