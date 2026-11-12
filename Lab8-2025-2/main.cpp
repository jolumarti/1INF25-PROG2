
#include "src/model/AdministrarMetricas.hpp"

int main() {
    AdministrarMetricas ops;
    ops.cargarArchivo("../data/metricas.csv");
    ops.generarReporte("../dist/reporte1.txt");
    ops.eliminarNodos();
    ops.generarReporte("../dist/reporte2.txt");
    return 0;
}
