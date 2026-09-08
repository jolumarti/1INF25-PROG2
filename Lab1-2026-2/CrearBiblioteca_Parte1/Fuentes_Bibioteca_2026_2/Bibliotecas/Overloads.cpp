//
// Created by alulab14 on 4/09/2026.
//

#include "Overloads.h"

char *readLine(istream &file, char delim) {
    char buffer[BUFFER_SIZE];
    file.getline(buffer, BUFFER_SIZE, delim);
    char *ptr = new char[strlen(buffer) + 1];
    strcpy(ptr, buffer);
    return ptr;
}

char *copyString(const char *str) {
    char *ptr = new char[strlen(str) + 1];
    strcpy(ptr, str);
    return ptr;
}

bool operator>>(ifstream &file, struct Producto &producto) {
    //1,Avena Pacifico Tipo 17,UNIDAD
    file >> producto.codigo;
    if (file.eof()) return false;
    file.get();
    producto.nombre = readLine(file, ',');
    producto.unidad = readLine(file, '\n');
    return true;
}

bool operator>>(ifstream &file, struct Empaque &empaque) {
    //1,PAQ25,25
    file >> empaque.codigo;
    if (file.eof()) return false;
    file.get();
    empaque.nombre = readLine(file, ',');
    file >> empaque.cantidad;
    file.get();
    return true;
}

int operator!=(const struct Almacen *almacenes, const struct Almacen &almacen) {
    int i = 0;
    while (almacenes[i].codigo != nullptr) {
        if (strcmp(almacenes[i].codigo, almacen.codigo) == 0) return i;
        i++;
    }
    return NOT_FOUND;
}

void operator+=(struct Almacen &almacen, const struct ProductoStock &productoStock) {
    almacen.producto_stock[almacen.numeroProdutos] = productoStock;
    almacen.numeroProdutos++;
}

void operator||(struct ProductoStock &productoStock,const struct Producto *productos) {
    int i = 0;
    while (productos[i].nombre != nullptr) {
        if (productos[i].codigo == productoStock.codigo) {
            productoStock.nombre = copyString(productos[i].nombre);
            return;
        }
        i++;
    }
}

void operator&&(struct ProductoStock &productoStock, const struct Empaque *empaques) {
    int i = 0;
    while (empaques[i].nombre != nullptr) {
        if (empaques[i].codigo == productoStock.codigo) {
            productoStock.empacado = productoStock.stock / empaques[i].cantidad;
            productoStock.picking = productoStock.stock % empaques[i].cantidad;
            return;
        }
        i++;
    }
}

void operator<=(struct Almacen &almacen, struct Empaque *empaques) {
    for (int i = 0; i < almacen.numeroProdutos; i++) {
        almacen.producto_stock[i] && empaques;
    }
}
void operator<=(struct Almacen &almacen, struct Producto *productos) {
    for (int i = 0; i < almacen.numeroProdutos; i++) {
        almacen.producto_stock[i] || productos;
    }
}
ostream & operator<< (ostream &file, const struct ProductoStock &productoStock) {
    file << "Codigo del producto: " << setw(9) << right << productoStock.codigo << left << endl;
    file << "Nombre del producto: " << productoStock.nombre << endl;
    file << "StockTotal: " << setw(18) << right <<productoStock.stock << left << endl << endl;
    file << "Stock en Paquetes: " << endl;
    file << "Paquetes: " << setw(20) << right << productoStock.empacado<< left << endl;
    file << "Unidades: " << setw(20) << right << productoStock.picking << left << endl;
    return file;
}
void printLine (ostream &out, char delim) {
    out << setw(LINE_SIZE) << setfill(delim) << delim << setfill (' ')<< endl;
}
ostream &operator<< (ostream &file, const struct Almacen &almacen) {
    file << "Almacen:           " << almacen.codigo << endl;
    file << "Numero de Productos: " << almacen.numeroProdutos << endl;
    printLine(file, '=');
    file << "Detalle de productos:" << endl;
    printLine(file, '=');
    for (int i = 0; i < almacen.numeroProdutos; i++) {
        file << almacen.producto_stock[i];
        printLine(file, '=');
    }
    return file;
}


