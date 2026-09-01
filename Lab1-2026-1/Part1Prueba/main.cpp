#include "Libraries/Overloads.hpp"
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
    mascotasArch >> mascota;
    reporteArch << mascota  << endl  << endl;
    int fecha = mascota.fechaNacimiento +10;
    reporteArch << "Comparar Fechas" << endl;
    reporteArch << "Fecha de nacimiento: " << mascota.fechaNacimiento << endl;
    reporteArch << "Fecha: " << fecha << endl;
    reporteArch << ((mascota<=fecha)? "Si es mayor" : "no es mayor") << endl<< endl;

    struct Atencion atencion;
    bool testAtencionOp = false;
    atencionesArch >> atencion;
    atencion.idAtencion = ATENCION_ID_INI;
    reporteArch << atencion  << endl  << endl;
    struct Atencion atencion2 = atencion;
    atencion2.fecha ++;
    reporteArch <<  "Compara Atenciones" << endl;
    reporteArch << "Atencion 1: ";
    reporteArch << atencion;
    reporteArch << "Atencion 2: " ;
    reporteArch << atencion2;
    reporteArch << ((atencion==atencion2)? "Igual" : "no son iguales") << endl;

}
