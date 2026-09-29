//
// Created by jolumarti on 2026-09-24.
//

#include "genericos.hpp"

void procesarArreglo(void **array, bool (*read_fun)(ifstream &, void *&), const char* file_name) {
    ifstream file;
    open_in_file(file, file_name);
    void *data; int i = 0;
    while (read_fun(file, data)) {
        array[i++] = data;
    }
}
void generaLista(void *&list) {
    void **aux = new void*[2];
    aux[HEAD] = nullptr;
    aux[SIZE] = new int(0);
    list = aux;
}
void insertarLista(void *list, void *data) {
    void **aux_list = (void**) list;
    void **new_node = new void*[2];
    new_node[DATA] = data;
    new_node[NEXT] = aux_list[HEAD];
    aux_list[HEAD] = new_node;
}
void crearLista(void **array, void *&list, int (*cmp) (void *, void *)) {
    int num = 0;
    for (; array[num]; num++);
    qsort(array, num, sizeof(void *), cmp);
    generaLista(list);
    for (int i = num-1; i <0; i--) {
        insertarLista(list, array[i]);
    }
}