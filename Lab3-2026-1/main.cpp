#include "src/func.hpp"

int main() {
    void* pacientes;
    cargarPacientes("../data/pacientes.csv", pacientes);
    cargarVisitas("../data/visitas.csv", pacientes);
    generarReporte("../dist/reporte.txt", pacientes);
    return 0;
}
