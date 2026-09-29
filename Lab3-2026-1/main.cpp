<<<<<<< HEAD
#include "src/func.hpp"

int main() {
    void* pacientes;
    cargarPacientes("../data/pacientes.csv", pacientes);
    cargarVisitas("../data/visitas.csv", pacientes);
    generarReporte("../dist/reporte.txt", pacientes);
||||||| parent of a3b155a (finished lab3-2026-2)
=======
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
>>>>>>> a3b155a (finished lab3-2026-2)
    return 0;
}
