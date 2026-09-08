#include "Libraries/functions.hpp"

int main() {
    int *fechas{};
    int **datosEnteros{};
    char ***datosDeTexto{};
    float **datosDePuntoFlotante{};
    cargarInformacion("../Data/ER_Final_Dataset_For_Students_Programacion_2.csv", fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    completarInformacion(datosEnteros, datosDePuntoFlotante);
    reporteDeAtenciones("../Report/reporte.txt", fechas, datosDeTexto, datosEnteros, datosDePuntoFlotante);
    return 0;
}
