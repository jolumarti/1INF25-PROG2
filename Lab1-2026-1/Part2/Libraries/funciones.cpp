//
// Created by jolumarti on 2026-09-01.
//

#include "funciones.hpp"
#define MAX_SIZE 50
#define LINE_SIZE 47
#define MAX_AGE 20251010
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
    struct Mascota mascotas[MAX_SIZE];
    openInArch(mascotasArch, file_name);
    while (true) {
        struct Mascota mascota;
        if (mascotasArch >> mascota) {
            mascotas[sistema.numeroMascotas] = mascota;
            sistema.numeroMascotas++;
        } else break;
    }
    sistema.mascotas = new struct Mascota[sistema.numeroMascotas];
    for(int i=0; i<sistema.numeroMascotas; i++){
        sistema.mascotas[i] = mascotas[i];
    }
}
void readVeterinarios(struct SistemaHuellitas &sistema, const char *file_name) {
    ifstream veterinariosArch;
    struct Veterinario veterinarios[MAX_SIZE];
    openInArch(veterinariosArch, file_name);
    while (true) {
        struct Veterinario veterinario;
        if (veterinariosArch >> veterinario) {
            veterinarios[sistema.numeroVeterinarios] = veterinario;
            sistema.numeroVeterinarios++;
        } else break;
    }
    sistema.veterinarios = new struct Veterinario[sistema.numeroVeterinarios];
    for(int i=0; i<sistema.numeroVeterinarios; i++){
        sistema.veterinarios[i] = veterinarios[i];
    }
}

void saveAtencion(struct SistemaHuellitas &sistema, struct Atencion *atenciones, int &idAtencion, int &numSinProgramar, struct Atencion &atencion) {
    bool save = true;
    atencion.idAtencion = idAtencion++;
    for (int i = 0; i < sistema.numeroAtenciones; i++) {
        if (atenciones[i] == atencion) {
            save = false;
            cout << "Horario ocupado del veterinario ID: " << atencion.idVeterinario <<
                    " el "<< atencion.fecha << " a las " << atencion.hora << ":" << atencion.minutos << endl;
            numSinProgramar++;
        }
    }
    if (save) {
        atenciones[sistema.numeroAtenciones] = atencion;
        sistema.numeroAtenciones++;
    }
}

void registerAtenciones(struct SistemaHuellitas &sistema, const char *file_name) {
    ifstream atencionesArch;
    openInArch(atencionesArch, file_name);

    struct Atencion atenciones[MAX_SIZE];
    int idAtencion{ATENCION_ID_INI}, numSinProgramar{};
    while (true) {
        struct Atencion atencion;
        if (atencionesArch >> atencion) {
            saveAtencion(sistema, atenciones, idAtencion, numSinProgramar, atencion);
        } else break;
    }
    cout << numSinProgramar << " ATENCION(S) SIN PROGRAMAR" << endl;
    sistema.atenciones = new struct Atencion[sistema.numeroAtenciones];
    for(int i=0; i<sistema.numeroAtenciones; i++){
        sistema.atenciones[i] = atenciones[i];
    }
}
ostream &printLine(ostream &arch, char deli) {
    arch << setfill(deli) << setw(LINE_SIZE) << deli << setfill(' ') << endl;
    return arch;
}
void listaMascotasAEsterilizar(struct SistemaHuellitas &sistema, const char *file_name) {
    ofstream reporteArch;
    openOutArch(reporteArch, file_name);
    printLine(reporteArch, '=') << "**** MASCOTAS QUE DEBEN SER ESTERILIZADAS *****" << endl;;
    printLine(reporteArch, '=');
    for (int i = 0; i < sistema.numeroMascotas; i++) {
        struct Mascota &mascota = sistema.mascotas[i];
        if (mascota<= MAX_AGE) {
            reporteArch << "MASCOTA ";
            reporteArch << mascota;
        }
    }
}

int printAtencionesDeMascota(struct SistemaHuellitas &sistema, ofstream &reporteArch, struct Mascota &mascota) {
    int cant{};
    for (int j = 0; j < sistema.numeroAtenciones; j++) {
        struct Atencion &atencion = sistema.atenciones[j];
        if (atencion.idMascota == mascota.idMascota) {
            reporteArch << "      ";
            reporteArch << atencion ;
            cant++;
        }
    }
    if (!cant) reporteArch << "      No tiene atenciones registradas" << endl;
    return cant;
}


void imprimirMascotasConAtenciones(struct SistemaHuellitas &sistema, const char *file_name) {
    ofstream reporteArch;
    openOutArch(reporteArch, file_name);
    printLine(reporteArch, '=') << "**** LISTADO DE MASCOTAS Y SUS ATENCIONES *****" << endl;;
    printLine(reporteArch, '=');
    int cantAtenciones{};
    for (int i = 0; i < sistema.numeroMascotas; i++) {
        struct Mascota &mascota = sistema.mascotas[i];
        reporteArch << "MASCOTA ";
        reporteArch << mascota << endl;
        cantAtenciones += printAtencionesDeMascota(sistema, reporteArch, mascota);
        printLine(reporteArch, '-');

    }
    reporteArch << "TOTAL: " <<sistema.numeroMascotas << " mascotas, " << cantAtenciones << " atenciones" << endl;
}
