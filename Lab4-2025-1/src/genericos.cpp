//
// Created by jolumarti on 2026-09-24.
//

#include "genericos.hpp"

void procesarArreglo(void **array, bool (*read_fun)(ifstream &, void *&), const char *file_name) {
    ifstream file;
    open_in_file(file, file_name);
    void *data;
    int i = 0;
    while (read_fun(file, data)) {
        array[i++] = data;
    }
}

void push(void *list, void *node) {
    void **aux_node = (void **) node;
    void **aux_list = (void **) list;
    aux_node[NEXT] = aux_list[BLOQUE1];
    aux_list[BLOQUE1] = aux_node;
    if (aux_list[BLOQUE2] == nullptr) {
        aux_list[BLOQUE2] = aux_node;
    }
}

void append(void *&bloque, void *node) {
    if (!bloque) {
        bloque = node;
        return;
    }
    void **aux_bloque = (void **) bloque;
    void **aux_node = (void **) node;
    void **prev = nullptr;
    while (aux_bloque) {
        prev = aux_bloque;
        aux_bloque = (void **)aux_bloque[NEXT];
    }
    if (prev) prev[NEXT] = aux_node;
}

void insertarLista(void *list, void *data, bool (*cmp)(void *)) {
    void **node = new void *[2]{};
    node[DATA] = data;
    node[NEXT] = nullptr;
    void **aux = (void **) list;
    void **&b1 = (void **&) aux[BLOQUE1];
    void **&b2 = (void **&) aux[BLOQUE2];
    if (cmp(node)) {
        if (b1) node[NEXT] = b1;
        else { node[NEXT] = b2; }
        b1 = node;
    } else {
        if (!b2 && b1) append((void *&) b1, node);
        append((void *&) b2, node);
    }
}

void generaLista(void *&list, bool (*read_fun)(ifstream &, void *&), bool (*cmp)(void *),
                 const char *file_name) {
    ifstream file;
    open_in_file(file, file_name);
    void **aux = new void *[2];
    aux[BLOQUE1] = nullptr;
    aux[BLOQUE2] = nullptr;
    void *data;
    while (read_fun(file, data)) {
        insertarLista(aux, data, cmp);
    }
    list = aux;
}

void imprimeLista(void *list, void (*print_fun)(ofstream &, void *, bool), const char *file_name) {
    ofstream file;
    open_out_file(file, file_name);
    void **aux = (void **) list;
    bool first = true;
    if (!aux[BLOQUE1]) {
        for (void **cur = (void **) aux[BLOQUE2]; cur; cur = (void **) cur[NEXT]) {
            print_fun(file, cur, first);
            first = false;
        }
        return;
    }
    for (void **cur = (void **) aux[BLOQUE1]; cur; cur = (void **) cur[NEXT]) {
        print_fun(file, cur, first);
        first = false;
    }
}
