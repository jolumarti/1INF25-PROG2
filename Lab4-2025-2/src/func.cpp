//
// Created by jolumarti on 2026-10-01.
//

#include "func.hpp"

void new_list(List &list) {
    list.size = 0;
    list.front = nullptr;
    list.back = nullptr;
}

void push_front(List &list, void *element, void *(*clone)(void *)) {
    void **node = new void *[2]{};
    node[DATA] = clone(element);
    node[NEXT] = list.front;
    list.front = node;
    if (!list.back) list.back = node;
    list.size++;
}

void push_back(List &list, void *element, void *(*clone)(void *)) {
    void **node = new void *[2]{};
    node[DATA] = clone(element);
    node[NEXT] = nullptr;
    if (list.back) {
        void **aux = (void **) list.back;
        aux[NEXT] = node;
    }
    if (!list.front) list.front = node;
    list.back = node;
    list.size++;
}

void *begin(List &list) {
    return list.front;
}

void *end() {
    return nullptr;
}

void *next(void *node) {
    void **aux = (void **) node;
    return aux[NEXT];
}

void *getValue(void *node) {
    void **aux = (void **) node;
    return aux[DATA];
}

void foreach(List &list, void (*fun)(void *)) {
    for (void *it = begin(list); it != end(); it = next(it)) {
        void *valor = getValue(it);
        fun(valor);
    }
}

bool findIf(List &list, bool (*cmp)(void *, void *), void *valor_busqueda) {
    for (void *it = begin(list); it != end(); it = next(it)) {
        void *valor = getValue(it);
        if (cmp(valor, valor_busqueda)) return true;
    }
    return false;
}
