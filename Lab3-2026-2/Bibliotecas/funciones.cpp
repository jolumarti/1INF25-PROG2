//
// Created by alulab14 on 25/09/2026.
//

#include "funciones.h"
#include <iostream>

void open_in_file(ifstream &file, const char *file_name) {
    file.open(file_name, ios::in);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo : " << file_name << endl;
        exit(1);
    }
}

void open_out_file(ofstream &file, const char *file_name) {
    file.open(file_name, ios::out);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo : " << file_name << endl;
        exit(1);
    }
    file << setprecision(2) << fixed;
}

void resize_memory(void **&array, int cap, int num) {
    void **aux = new void *[cap]{};
    for (int i = 0; i < num; i++) {
        aux[i] = array[i];
    }
    if (array) delete [] array;
    array = aux;
}

char *read_line(ifstream &file, char delim) {
    char buffer[BUFFER_SIZE];
    file.getline(buffer, BUFFER_SIZE, delim);
    char *aux = new char[strlen(buffer) + 1];
    strcpy(aux, buffer);
    return aux;
}

bool read_product(ifstream &file, void *&product) {
    char *id, *desc, type, tmp;
    float price;
    id = read_line(file, ',');
    if (file.eof()) {
        delete []id;
        return false;
    }
    desc = read_line(file, ',');
    file >> price >> tmp >> type;
    file.get();
    if (file.peek() != '\r') file.get(); //fix for linux
    void **data = new void *[6]{};
    data[ID] = id;
    data[DESC] = desc;
    data[PRICE] = new float(price);
    data[TYPE] = new char(type);
    data[PACKS] = nullptr;
    data[QTY] = new int(0);
    product = data;
    return true;
}

void cargarProductos(const char *file_name, void *&productos) {
    ifstream file;
    open_in_file(file, file_name);
    void **aux{}, *product{};
    int cap = 0, num = 0;
    while (read_product(file, product)) {
        if (cap == num) {
            cap += INCREMENT;
            resize_memory(aux, cap, num);
        }
        aux[num] = product;
        num++;
    }
    resize_memory(aux, num + 1, num);
    productos = aux;
}
void delete_empaque(void *&empaque) {
    if (!empaque) return;
    void **aux = (void**) empaque;
    delete[] (char *)aux[PACK_ID];
    delete[] (char *)aux[PACK_DESC];
    delete (int *)aux[PACK_UNITS];
    delete (float *)aux[PACK_FACTOR];
    delete (int *)aux[PACK_ACTIVE];
    delete [] aux;
    empaque = nullptr;
}
bool read_empaque(ifstream &file, void *&empaque, char *&id) {
    char *aux_id, *id_pack, *desc_pack, c;
    float factor;
    int units, active;
    id_pack = read_line(file, ',');
    if (file.eof()) {
        delete []id_pack;
        return false;
    }
    aux_id = read_line(file, ',');
    desc_pack = read_line(file, ',');
    file >> units >> c >> factor >> c >> active;
    file.get();
    void **data = new void *[5]{};
    data[PACK_ID] = id_pack;
    data[PACK_DESC] = desc_pack;
    data[PACK_UNITS] = new int(units);
    data[PACK_FACTOR] = new float(factor);
    data[PACK_ACTIVE] = new int(active);
    empaque = data;
    id = aux_id;
    return true;
}

int find_product(void **products, const char *id) {
    if (!products) return NOT_FOUND;
    int i{};
    void **aux = (void **) products[i];
    while (aux) {
        char *id_product = (char *) aux[ID];
        if (strcmp(id, id_product) == 0) return i;
        aux = (void **) products[++i];
    }
    return NOT_FOUND;
}

void push_empaque(void *&packs, void *empaque, int &cap, int &num) {
    void **&aux = (void **&) packs;
    if (cap == num) {
        cap += INCREMENT;
        resize_memory(aux, cap + 1, num);
    }
    aux[num++] = empaque;
}

void cargarEmpaques(const char *file_name, void *productos) {
    ifstream file;
    open_in_file(file, file_name);
    void **aux_productos = (void **) productos;
    int caps[250]{}, nums[250]{};
    void *empaque{};
    char *id;
    while (read_empaque(file, empaque, id)) {
        int pos = find_product(aux_productos, id);
        if (pos == NOT_FOUND) {
            delete_empaque(empaque);
            delete[] id;
            continue;
        }
        void **product = (void **) aux_productos[pos];
        void *&packs = (void *&) product[PACKS];
        int *&qty = (int *&) product[QTY];
        void **aux_empaque = (void **) empaque;
        if (*(int *) aux_empaque[PACK_ACTIVE]) *qty += *(int *) aux_empaque[PACK_UNITS];
        push_empaque(packs, empaque, caps[pos], nums[pos]);
        delete []id;
    }
}

void print_line(ofstream &file, char delim) {
    file << setfill(delim) << setw(LINE_SIZE) << delim << setfill(' ') << endl;
}

int size_packs(void **packs) {
    if (!packs) return 0;
    int i{};
    while (packs[i]) i++;
    return i;
}

void calculate_totals(void **packs, int qty_packs, char type, float price, int *cants, int &qty_active, float &subtotal) {
    if (!qty_packs) ++cants[R_SIN];
    switch (type) {
        case 'A': ++cants[R_A]; break;
        case 'B': ++cants[R_B]; break;
        case 'C': ++cants[R_C]; break;
        case 'H': ++cants[R_H]; break;
        case 'L': ++cants[R_L]; break;
        case 'M': ++cants[R_M]; break;
        case 'O': ++cants[R_O]; break;
        case 'S': ++cants[R_S]; break;
    }
    for (int i = 0; i < qty_packs; i++) {
        void **pack = (void **) packs[i];
        int *active = (int *) pack[PACK_ACTIVE];
        float *factor = (float *) pack[PACK_FACTOR];
        int *units = (int *) pack[PACK_UNITS];
        if (*active) {
            qty_active++;
            subtotal += *factor * *units * price;
            cants[R_UNI]+=*units;
            ++cants[R_ACT];
        }
    }
}

void print_products(ofstream &file, void **aux_productos) {
    int i = 0, cants[11]{};
    float total{};
    void **product = (void **) aux_productos[i];
    while (product) {
        char *id = (char *) product[ID];
        char *desc = (char *) product[DESC];
        char *type = (char *) product[TYPE];
        float *price = (float *) product[PRICE];
        void **packs = (void **) product[PACKS];
        int *qty = (int *) product[QTY];
        int qty_packs = size_packs(packs);
        int qty_active = 0;
        float subtotal = 0;
        calculate_totals(packs, qty_packs, *type, *price, cants, qty_active, subtotal);
        if (qty_packs) {
            file << left << setw(8) << id << setw(LINE_SIZE / 5+10) << desc << right <<
                    setw(LINE_SIZE / 8) << *type << setw(LINE_SIZE / 8) << *price <<
                    setw(LINE_SIZE / 8) << qty_active << setw(LINE_SIZE / 8) << *qty <<
                    setw(LINE_SIZE / 8) << subtotal << endl;
        }
        total += subtotal;
        product = (void **) aux_productos[++i];
    }
    print_line(file, '-');
    file << "RESUMEN GENERAL:" << endl;
    file << "PRODUCTOS TIPO A: " << cants[R_A] << endl;
    file << "PRODUCTOS TIPO B: " << cants[R_B] << endl;
    file << "PRODUCTOS TIPO C: " << cants[R_C] << endl;
    file << "PRODUCTOS TIPO H: " << cants[R_H] << endl;
    file << "PRODUCTOS TIPO L: " << cants[R_L] << endl;
    file << "PRODUCTOS TIPO M: " << cants[R_M] << endl;
    file << "PRODUCTOS TIPO O: " << cants[R_O] << endl;
    file << "PRODUCTOS TIPO S: " << cants[R_S] << endl;
    file << "PRODUCTOS SIN EMPAQUES: " << cants[R_SIN] << endl;
    file << "TOTAL DE EMPAQUES ACTIVOS: " << cants[R_ACT] << endl;
    file << "TOTAL DE UNIDADES ACUMULADAS: " << cants[R_UNI] << endl;
    file << "VALOR TOTAL DEL CATALOGO (S/): " << total << endl;
    print_line(file, '=');
}

void generarReporte(const char *file_name, void *productos) {
    ofstream file;
    open_out_file(file, file_name);
    void **aux_productos = (void **) productos;
    print_line(file, '=');
    file << setw(LINE_SIZE / 2 + 18) << "REPORTE DE CATALOGO DE PRODUCTOS" << endl;
    print_line(file, '=');
    file << left << setw(8) << "CODIGO" << setw(LINE_SIZE / 5) << "NOMBRE PRODUCTO" << right <<
            setw(LINE_SIZE / 8+10) << "TIPO" << setw(LINE_SIZE / 8) << "PRECIO" <<
            setw(LINE_SIZE / 8) << "EMPAQ." << setw(LINE_SIZE / 8) << "UNID" <<
            setw(LINE_SIZE / 8) << "VALOR" << endl;
    print_line(file, '-');
    print_products(file, aux_productos);
}
