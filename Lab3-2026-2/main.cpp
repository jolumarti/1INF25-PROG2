#include "Bibliotecas/funciones.h"
int main(int argc, char** argv)
{
    void *productos;
    cargarProductos("../data/productos.csv", productos);
    cargarEmpaques("../data/empaques.csv", productos);
    generarReporte("../dist/reporteDeProductos.txt", productos);
    return 0;
}