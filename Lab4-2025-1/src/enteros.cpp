//
// Created by jolumarti on 2026-09-24.
//

#include "enteros.hpp"

bool read_num(ifstream &file, void *&data) {
    int num;
    file >> num;
    if (file.eof()) return false;
    file.get();
    data = new int (num);
    return true;
}

bool cmp_num(void *data) {
    void **reg = (void **) data;
    int *num = (int *) reg[DATA];
    return *num < 10;
}

void print_num(ofstream &file, void *node, bool first) {
    void **aux = (void **) node;
    if (first) file << "Numeros" << endl;
    file << *(int *) aux[DATA] << endl;
}
