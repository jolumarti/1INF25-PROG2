#include "Libraries/funciones.hpp"

int main() {
    struct SistemaHuellitas sistema{};
    readMascotas(sistema, "../Data/Mascotas.csv");
    readVeterinarios(sistema, "../Data/Veterinarios.csv");
    registerAtenciones(sistema, "../Data/Atenciones.csv");
    listaMascotasAEsterilizar(sistema, "../Report/ListaMascotasAEsterilizar.txt");
    imprimirMascotasConAtenciones(sistema, "../Report/MascotasConAtenciones.txt");
}
