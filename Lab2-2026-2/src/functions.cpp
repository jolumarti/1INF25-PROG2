//
// Created by jolumarti on 2026-09-12.
//

#include "functions.hpp"
#include <fstream>
using namespace std;

void cargarVentas(const char *file_name, char ***&ventas) {
    ifstream file;
    open_in_file(file, file_name);
    char **buffer_ventas[MAX_VENTAS]{};
    int n = 0;
    while (true) {
        char **venta = new char *[4]{};
        venta[0] = read_line(file, ',');
        if (file.eof()) {
            delete[] venta;
            break;
        }
        venta[1] = read_line(file, ',');
        venta[2] = read_line(file, ',');
        venta[3] = read_line(file);
        buffer_ventas[n++] = venta;
    }
    ventas = new char **[n+1]{}; //+1 for nullptr termination
    for (int i = 0; i < n; ++i) {
        ventas[i] = buffer_ventas[i];
    }
}

int sice_c3(char ***array) {
    int i = 0;
    if (array == nullptr) return i;
    while (array[i]) {
        i++;
    }
    return i;
}

int lookup_ventas(char ***ventas, const char *codigo_venta) {
    for (int i = 0; ventas[i]; ++i) {
        if (strcmp(ventas[i][0], codigo_venta) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}

void increase_capacity(char ***&detallesDeVentasTextos, int **&detallesDeVentasValores, int &capacidad, int n) {
    capacidad += INCREMENT;
    char ***aux_textos = new char **[capacidad+1]{};//+1 for nullptr termination
    int **aux_valores = new int *[capacidad+1]{};
    if (detallesDeVentasTextos != nullptr) {
        for (int i = 0; i < n; ++i) {
            aux_textos[i] = detallesDeVentasTextos[i];
            aux_valores[i] = detallesDeVentasValores[i];
        }
        delete[] detallesDeVentasTextos;
        delete[] detallesDeVentasValores;
    }
    detallesDeVentasTextos = aux_textos;
    detallesDeVentasValores = aux_valores;
}

void add_detalles(char ***ventas, char ****&detallesDeVentasTextos, int ***&detallesDeVentasValores, ifstream &file,
                  int *capacidad, int *num, const char *codigo_venta) {
    char **textos = new char *[DET_TEXTOS]{};
    int *valores = new int[DET_VALORES]{};
    textos[0] = read_line(file, ',');
    textos[1] = read_line(file, ',');
    char c;
    file >> valores[0] >> c >> valores[1] >> c >> valores[2] >> c;
    file.get();
    int pos_venta = lookup_ventas(ventas, codigo_venta);
    if (pos_venta != NOT_FOUND) {
        char ***& detalles_textos = detallesDeVentasTextos[pos_venta];
        int **& detalles_valores = detallesDeVentasValores[pos_venta];
        int &cap = capacidad[pos_venta];
        int &n = num[pos_venta];
        if (cap == n)
            increase_capacity(detalles_textos, detalles_valores, cap, n);
        detalles_textos[n] = textos;
        detalles_valores[n] = valores;
        n++;
    } else {
        delete[] textos;
        delete[] valores;
    }
}

void cargarDetallesDeVentas(const char *file_name, char ***ventas,
                            char ****&detallesDeVentasTextos, int *** &detallesDeVentasValores) {
    ifstream file;
    open_in_file(file, file_name);
    int size_ventas = sice_c3(ventas);
    detallesDeVentasTextos = new char ***[size_ventas]{};
    detallesDeVentasValores = new int **[size_ventas]{};
    int *cap = new int[size_ventas]{};
    int *n = new int[size_ventas]{};
    while (true) {
        char *codigo_venta = read_line(file, ',');
        if (file.eof()) {
            delete[] codigo_venta;
            break;
        }
        add_detalles(ventas, detallesDeVentasTextos, detallesDeVentasValores, file, cap, n, codigo_venta);
        delete[] codigo_venta;
    }
    delete[] cap;
    delete[] n;
}

void completarDetallesDeVentas(const char *file_name, char ***ventas, char ****detallesDeVentasTextos,
                               int ***detallesDeVentasValores) {
    ifstream file;
    open_in_file(file, file_name);
    while (true) {
        char *codigo_prod = read_line(file, ',');
        if (file.eof()) {
            delete[] codigo_prod;
            break;
        }
        int i = 0;
        char *descripcion = read_line(file, ',');
        char *categoria = read_line(file, ',');
        char c;
        int costo, precio;
        file >> costo >> c >> precio;
        file.get();
        while (ventas[i]) {
            int j = 0;
            char ***detalles_textos = detallesDeVentasTextos[i];
            int **detalles_valores = detallesDeVentasValores[i];
            while (detalles_textos[j]) {
                char **textos = detalles_textos[j];
                int *valores = detalles_valores[j];
                if (strcmp(textos[0], codigo_prod) == 0) {
                    textos[2] = copy_cstring(descripcion);
                    textos[3] = copy_cstring(categoria);
                    valores[3] = costo;
                    valores[4] = precio;
                }
                j++;
            }
            i++;
        }
        delete[] descripcion;
        delete[] categoria;
        delete[] codigo_prod;
    }
}


void print_detalles(char ****detallesDeVentasTextos, int ***detallesDeVentasValores, ofstream &file, int i, int j) {
    char ***detalles_textos = detallesDeVentasTextos[i];
    int **detalles_valores = detallesDeVentasValores[i];
    float costo_total{}, precio_total{};
    file << "PRODUCTOS COMPRADOS:" << endl << "CODIGO"
            << setw(LINE_SIZE / 10-3) << "DESCRIPCION"
            << setw(LINE_SIZE / 10+16) << "PRESENTACION"
            << setw(LINE_SIZE / 10) << "CATEGORIA"
            << setw(LINE_SIZE / 10) << "UNID X PRES"
            << setw(LINE_SIZE / 10) << "CANTIDAD"
            << setw(LINE_SIZE / 10+5) << "COSTO UNITARIO"
            << setw(LINE_SIZE / 10+5) << "PRECIO UNITARIO"
            << setw(LINE_SIZE / 10) << "DESCUENTO"
    << endl;
    print_filled_line(file, '-');
    while (detalles_textos[j]) {
        char **textos = detalles_textos[j];
        int *valores = detalles_valores[j];
        file << left << setw(8) << textos[0]
                << setw(LINE_SIZE / 10+16+2) << (textos[2] ? textos[2] : "")
                << setw(LINE_SIZE / 10) << textos[1]
                << setw(LINE_SIZE / 10-3) << (textos[3] ? textos[3] : "") << right
                << setw(8) << valores[0]
                << setw(LINE_SIZE / 10) << valores[1]
                << setw(LINE_SIZE / 10+4) << valores[3]
                << setw(LINE_SIZE / 10+5) << valores[4]
                << setw(LINE_SIZE / 10) << valores[2] << "%" << endl;
        j++;
        costo_total += valores[1] * valores[3];
        precio_total += valores[1] * valores[4] * (1 - valores[2] / 100.0);
    }
    print_filled_line(file, '-');
    file << "COSTO TOTAL:    " << setw(10) << costo_total << endl;
    file << "PRECIO TOTAL:   " << setw(10) << precio_total << endl;
    file << "GANANCIA TOTAL: " << setw(10) << precio_total-costo_total << endl;
}

void imprimirReporte(const char *file_name, char ***ventas, char ****detallesDeVentasTextos,
                     int ***detallesDeVentasValores, bool complete) {
    ofstream file;
    open_out_file(file, file_name);
    int i = 0;
    file << setw(LINE_SIZE/2+5) << "PACKMART S.A." << endl;
    file << setw(LINE_SIZE/2+8) << "REGISTRO DE VENTAS" << endl;
    while (ventas[i]) {
        int j = 0;
        char **venta = ventas[i];

        print_filled_line(file, '=');
        file << setw(LINE_SIZE / 4-13) << "CODIGO DE VENTA" << setw(LINE_SIZE / 4) << "CODIGO DE CLIENTE" <<
                setw(LINE_SIZE / 4) << "FECHA DE VENTA" << setw(LINE_SIZE / 4) << "CANAL DE VENTA" << endl <<
                setw(LINE_SIZE / 4-18) << venta[0] << setw(LINE_SIZE / 4-2) << venta[1] <<
                setw(LINE_SIZE / 4+5) << venta[2] << setw(LINE_SIZE / 4-3) << venta[3] << endl;
        print_filled_line(file, '-');
        if (complete) {
            print_detalles(detallesDeVentasTextos, detallesDeVentasValores, file, i, j);
        }
        i++;
    }
}
