
#include "src/model/MinisterioDeTransporte.hpp"

int main() {
    MinisterioDeTransporte ministerio;
    ministerio < "../data/TablaDeInfracciones.csv";
    ministerio <= "../data/EmpresasRegistradas.csv";
    ministerio <<= "../data/InfraccionesCometidas.csv";
    ministerio >> "../dist/Reporte.txt";
    return 0;
}
