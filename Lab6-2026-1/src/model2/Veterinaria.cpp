//
// Created by jolumarti on 2026-10-07.
//

#include "Veterinaria.hpp"

void Veterinaria::resize_list(int cap) {
    auto *newList = new Mascota[cap];
    for (int i = 0; i < numMascotas; i++) {
        newList[i] = listaMascotas[i];
    }
    delete[] listaMascotas;
    listaMascotas = newList;
}

int Veterinaria::find_mascota(int dni, const char *nombre) {
    for (int i{}; i < numMascotas; i++) {
        Mascota &mascota = listaMascotas[i];
        char cstr[S_BUFFER];
        mascota.get_nombre(cstr);
        if (mascota.get_dni() == dni && strcmp(cstr, nombre) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}

Veterinaria::Veterinaria() {
    numMascotas = 0;
    listaMascotas = nullptr;
}

Veterinaria::~Veterinaria() {
    delete[] listaMascotas;
}

void Veterinaria::operator<=(const char *filename) {
    ifstream file;
    Helpers::open_ifstream(file, filename);
    int cap{};
    while (true) {
        if (cap == numMascotas) {
            cap += INCREMENT;
            resize_list(cap);
        }
        Mascota mascota{};
        if (!(file >> mascota))break;
        listaMascotas[numMascotas++] = mascota;
    }

    resize_list(numMascotas);
}

void Veterinaria::operator<<=(const char *filename) {
    ifstream file;
    Helpers::open_ifstream(file, filename);
    while (true) {
        //Firulais,12345678,Rabia,20250110,1.5,CMVP-1001
        int dni;
        char nombre[S_BUFFER], c;
        VacunaAplicada vacuna{};
        file.getline(nombre, S_BUFFER, ',');
        if (file.eof())break;
        file >> dni >> c;
        file >> vacuna;
        int pos = find_mascota(dni, nombre);
        if (pos == NOT_FOUND) continue;
        Mascota &mascota = listaMascotas[pos];
        mascota += vacuna;
    }
}

void Veterinaria::operator<<(const char *filename) {
    ofstream file;
    Helpers::open_ofstream(file, filename);
    int prev_dni{};
    Helpers::print_filled_line(file, '=');
    file << "REPORTE DE CARTILLAS - VETERINARIA HUELLITAS Y PLUMITAS\n";
    Helpers::print_filled_line(file, '=');
    for (int i = 0; i < numMascotas; ++i) {
        Mascota &pet = listaMascotas[i];
        int dni = pet.get_dni();
        if (dni != prev_dni) {
            if (prev_dni) Helpers::print_filled_line(file, '-');
            file << "DNI: " << setfill('0') << setw(8) << dni << setfill(' ') << endl;
            prev_dni = dni;
        }
        file << pet;
        pet.print_vacunas(file);
    }
    Helpers::print_filled_line(file, '=');
}
