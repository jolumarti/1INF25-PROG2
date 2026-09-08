//
// Created by alulab14 on 4/09/2026.
//

#include "funciones.h"
#define MAX_SIZE 800
#define MAX_ALMACEN_SIZE 100

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
    productos = new struct Producto[MAX_SIZE]{};
    int i = 0;
    while (file >> productos[i]) i++;
}

void cargaEmpaques(struct Empaque *&empaques, const char *file_name) {
    ifstream file;
    open_in_file(file, file_name);
    empaques = new struct Empaque[MAX_SIZE]{};
    int i = 0;
    while (file >> empaques[i]) i++;
}



void agregarProductoStock(struct Almacen *&almacenes, int &i, int codigoProducto, int stock, char *&codigoAlmacen) {
    struct Almacen almacen{};
    almacen.codigo = codigoAlmacen;
    int idAlmacen = almacenes != almacen;
    struct ProductoStock productoStock{};
    productoStock.codigo = codigoProducto;
    productoStock.stock = stock;
    if (idAlmacen != NOT_FOUND) {
        almacenes[idAlmacen] += productoStock;
        delete[] codigoAlmacen;
    } else {
        almacenes[i] = almacen;
        almacenes[i] += productoStock;
        i++;
    }
}

char *leerLinea(istream &file, char delim) {
    char buffer[BUFFER_SIZE];
    file.getline(buffer, BUFFER_SIZE, delim);
    char *ptr = new char[strlen(buffer) + 1];
    strcpy(ptr, buffer);
    return ptr;
}

void cargaAlmacenes(struct Almacen *&almacenes,
                    const char *file_name) {
    ifstream file;
    open_in_file(file, file_name);
    almacenes = new struct Almacen[MAX_ALMACEN_SIZE]{};
    //109,ALM01,717
    int i = 0;
    while (true) {
        int codigoProducto, stock;
        char *codigoAlmacen;
        file >> codigoProducto;
        if (file.eof()) break;
        file.get();
        codigoAlmacen = leerLinea(file, ',');
        file >> stock;
        file.get();
        agregarProductoStock(almacenes, i, codigoProducto, stock, codigoAlmacen);
    }
}
void actualizaEmpaqueNombre(struct Almacen *almacenes, struct Empaque *empaques, struct Producto *productos) {
    for (int i = 0; almacenes[i].codigo != nullptr; i++) {
        almacenes[i] <= productos;
        almacenes[i] <= empaques;
    }
}
void imprimeLinea (ostream &out, char delim) {
    out << setw(LINE_SIZE) << setfill(delim) << delim << setfill (' ')<< endl;
}
void imprimeAlmacen(struct Almacen *almacenes, const char *file_name) {
    ofstream file;
    open_out_file(file, file_name);
    imprimeLinea(file, '=');
    file << "***************** LISTADO DE ALMACENES ****************" << endl;
    imprimeLinea(file, '=');
    for (int i = 0; almacenes[i].codigo != nullptr; i++) {
        file << almacenes[i];
    }
}