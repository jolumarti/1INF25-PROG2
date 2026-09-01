//
// Created by jolumarti on 2026-09-01.
//

#include "funciones.hpp"
#include "Overloads.hpp"

void openOutArch(ofstream &arch, const char *nomArch) {
    arch.open(nomArch, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nomArch << endl;
        exit(1);
    }
    arch << setprecision(2) << fixed;
}
void openInArch(ifstream &arch, const char *nomArch) {
    arch.open(nomArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nomArch << endl;
        exit(1);
    }
}

void readMascotas(struct SistemaHuellitas &sistema, const char *file_name) {
    ifstream mascotasArch;
    struct Mascota mascotas[100];
    openInArch(mascotasArch, "../Data/Mascotas.csv");
    while (true) {
        struct Mascota mascota;
        if (mascotasArch >> mascota) {
            mascotas[sistema.numeroMascotas] = mascota;
            sistema.numeroMascotas++;
        }break;
    }
    sistema.mascotas = new struct Mascota[sistema.numeroMascotas];
    for(int i=0; i<sistema.numeroMascotas; i++){
        sistema.mascotas[i] = mascotas[i];
    }
}
void readVeterinarios(struct SistemaHuellitas &sistema, const char *file_name) {
    ifstream veterinariosArch;
    struct Veterinario veterinarios[100];
    openInArch(veterinariosArch, "../Data/Veterinarios.csv");
    while (true) {
        struct Veterinario veterinario;
        if (veterinariosArch >> veterinario) {
            veterinarios[sistema.numeroVeterinarios] = veterinario;
            sistema.numeroVeterinarios++;
        }break;
    }
    sistema.veterinarios = new struct Veterinario[sistema.numeroVeterinarios];
    for(int i=0; i<sistema.numeroVeterinarios; i++){
        sistema.veterinarios[i] = veterinarios[i];
    }
}
