#include "src/model/Veterinaria.hpp"

int main() {
    Veterinaria vet{};
    vet <= "../data/mascotas.csv";
    vet <<= "../data/vacunasAplicadas.csv";
    vet << "../dist/reporte.txt";
    return 0;
}
