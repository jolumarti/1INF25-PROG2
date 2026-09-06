#include "Bibliotecas/funciones.h"

int main() {
    struct Producto *productos;
    struct Empaque *empaques;
    struct Almacen *almacenes;
    cargaProductos(productos, "../ArchivosDeDatos/productos.csv");
    cargaEmpaques(empaques, "../ArchivosDeDatos/empaques.csv");
    cargaAlmacenes(almacenes, "../ArchivosDeDatos/inventario.csv");
    actualizaEmpaqueNombre(almacenes, empaques, productos);
    imprimeAlmacen(almacenes, "../ArchivosDeReporte/Reporte.txt");
    return 0;
}
