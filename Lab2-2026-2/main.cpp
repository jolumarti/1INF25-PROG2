#include "src/functions.hpp"

int main() {
    char ***ventas;
    char ****detallesDeVentasTextos;
    int ***detallesDeVentasValores;
    cargarVentas("../data/Ventas.csv", ventas);
    imprimirReporte("../report/prueba1.txt", ventas, detallesDeVentasTextos, detallesDeVentasValores, false);
    cargarDetallesDeVentas("../data/DetalleVentas.csv", ventas, detallesDeVentasTextos, detallesDeVentasValores);
    imprimirReporte("../report/prueba2.txt", ventas, detallesDeVentasTextos, detallesDeVentasValores);
    completarDetallesDeVentas("../data/Productos.csv", ventas, detallesDeVentasTextos,
                                 detallesDeVentasValores);
    imprimirReporte("../report/report.txt", ventas, detallesDeVentasTextos, detallesDeVentasValores);
    return 0;
}
