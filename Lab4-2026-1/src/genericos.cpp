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
void push(void *list, void *node) {
    void **aux_node = (void **)node;
    void **aux_list= (void **)list;
    int *size = (int *)aux_list[SIZE];
    aux_node[NEXT] = aux_list[HEAD];
    aux_list[HEAD] = aux_node;
    *size++;
}
void *pop(void *list) {
    void **aux_list = (void **)list;
    void **head = (void **)aux_list[HEAD];
    if (!head) return nullptr;
    aux_list[HEAD] = head[NEXT];
    head[NEXT] = nullptr;
    return head;
}
void generaLista(void *&list) {
    void **aux = new void*[2];
    aux[HEAD] = nullptr;
    aux[SIZE] = new int(0);
    list = aux;
}
void insertarLista(void *list, void *data) {
    void **node = new void*[2]{};
    node[DATA] = data;
    push(list, node);
}
void crearLista(void **array, void *&list, int (*cmp) (const void *, const void *)) {
    int num = 0;
    for (; array[num]; num++);
    qsort(array, num, sizeof(void *), cmp);
    generaLista(list);
    for (int i = num-1; i>=0; i--) {
        insertarLista(list, array[i]);
    }
}

void fusionaListas(void *list1, void *list2, int (*cmp)(const void *, const void *)) {
    void **aux1 = (void **)list1;
    void **aux2 = (void **)list2;
    void **cur1 = (void **)aux1[HEAD];
    void **cur2 = (void **)aux2[HEAD];
    void *new_head = nullptr;
    void **tail = nullptr;
    while (cur1 && cur2) {
        void **selected;
        if (cmp(cur1, cur2) <= 0) {
            selected = cur1;
            cur1 = (void **)cur1[NEXT];
        }else {
            selected = cur2;
            cur2 = (void **)cur2[NEXT];
        }
        if (new_head == nullptr) new_head = selected; // primer nodo, reemplaza la cabeza
        else tail[NEXT] = selected; // actualizo el ultimo
        tail = selected;
    }
    if (cur1) tail[NEXT] = cur1;
    if (cur2) tail[NEXT] = cur2;
    // clear values
    aux1[HEAD] = new_head;
    *(int *)aux1[SIZE] += *(int *)aux2[SIZE];
    aux2[HEAD] = nullptr;
    *(int *)aux2[SIZE] = 0;
}



void imprimeLista(void *list, void (*print_fun)(ofstream &, void **), const char* file_name) {
    ofstream file;
    open_out_file(file, file_name);
    void **aux = (void **)list;
    void **cur = (void **)aux[HEAD];
    print_fun(file, cur);
}
