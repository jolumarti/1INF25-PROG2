#include "Bibliotecas/Overloads.h"

void open_in_file(ifstream &file, const char *file_name) {
    file.open(file_name, ios::in);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo \"" << file_name << "\"" << endl;
        exit(1);
    }
}

void open_out_file(ofstream &file, const char *file_name) {
    file.open(file_name, ios::out);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo \"" << file_name << "\"" << endl;
        exit(1);
    }
}

void cargaProductos(struct Producto *&productos, const char *file_name) {
    ifstream file;
    open_in_file(file, file_name);
    productos = new struct Producto[800]{};
    int i = 0;
    while (true) {
        if (!(file >> productos[i])) break;
        i++;
    }
}

void cargaEmpaques(struct Empaque *&empaques, const char *file_name) {
    ifstream file;
    open_in_file(file, file_name);
    empaques = new struct Empaque[800]{};
    int i = 0;
    while (true) {
        if (!(file >> empaques[i])) break;
        i++;
    }
}

int main() {
    struct Producto *productos;
    struct Empaque *empaques;
    struct Almacen almacenes[10]{};
    ofstream ofile;
    open_out_file(ofile, "../ArchivosDeReporte/prueba.txt");
    cargaProductos(productos, "../ArchivosDeDatos/productos.csv");
    Producto &producto = productos[5];
    ofile << "Prueba de Carga de Producto con codigo " << producto.codigo << ", nombre " << producto.nombre <<
            " y unidad " << producto.unidad << endl;
    cargaEmpaques(empaques, "../ArchivosDeDatos/empaques.csv");
    Empaque &empaque = empaques[5];
    ofile << "Prueba de Carga de Empaque con codigo " << empaque.codigo << ", nombre " << empaque.nombre <<
            " y cantidad " << empaque.cantidad << endl;
    for (int i = 0; i < 10; i++) {
        almacenes[i].codigo = new char[10]{};
        strcpy(almacenes[i].codigo, "ALM0");
        almacenes[i].codigo[3] += i;
    }
    Almacen almacen = almacenes[5];
    ofile << "Prueba de Busqueda Almacen con codigo 5: " << (almacenes != almacen) << endl;
    ProductoStock productoStock{};
    productoStock.codigo = producto.codigo;
    productoStock.stock = 50;
    // Prueba de carga de nombre
    productoStock || productos;
    // Prueba de carga de empaque
    productoStock && empaques;
    // Prueba de añadido a almacen
    almacen += productoStock;
    // Prueba de impresion de almacen con datos actualizados
    ofile << almacen;
    return 0;
}
