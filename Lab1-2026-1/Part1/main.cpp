#include "MyLibrary/Overloads.hpp"
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
int main() {
    ifstream atencionesArch;
    ifstream mascotasArch;
    ifstream veterinariosArch;
    ofstream reporteArch;
    openInArch(atencionesArch, "../Data/Atenciones.csv");
    openInArch(mascotasArch, "../Data/Mascotas.csv");
    openInArch(veterinariosArch, "../Data/Veterinarios.csv");
    openOutArch(reporteArch, "../Report/Reporte.txt");
    struct Mascota mascota;
    bool testMascotaOp = false;
    while (true) {
        if (mascotasArch >> mascota) {
            reporteArch << mascota;
        } else break;
        if (!testMascotaOp) {
            testMascotaOp = true;
            int fecha = mascota.fechaNacimiento +10;
            reporteArch << "Compara Fechas" << endl;
            reporteArch << "Fecha de nacimiento: " << mascota.fechaNacimiento << endl;
            reporteArch << "Fecha: " << fecha << endl;
            reporteArch << ((mascota<=fecha)? "Si es mayor" : "no es mayor") << endl;
        }
    }
    struct Atencion atencion;
    bool testAtencionOp = false;
    int numAtencion=ATENCION_ID_INI;

    while (true) {
        if (atencionesArch >> atencion) {
            atencion.idAtencion = numAtencion++;
            reporteArch << atencion;
        } else break;

        if (!testAtencionOp) {
            testAtencionOp = true;
            struct Atencion atencion2 = atencion;
            atencion2.fecha ++;
            reporteArch << "Compara Atenciones" << endl;
            reporteArch << "Atencion 1: ";
            reporteArch << atencion;
            reporteArch << "Atencion 2: " ;
            reporteArch << atencion2;
            reporteArch << ((atencion==atencion2)? "Igual" : "no son iguales") << endl;

        }
    }

}
