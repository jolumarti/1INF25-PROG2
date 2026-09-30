//
// Created by jolumarti on 2026-09-24.
//

#include "enteros.hpp"

bool leenum(ifstream& file,  void *&data) {
    int num;
    file >> num;
    if (file.eof()) return false;
    file.get();
    data = new int(num);
    return true;
}
int comparanum (const void *data1, const void *data2) {
    void** reg1 = (void**) data1;
    void** reg2 = (void**) data2;
    int *num1 = (int*) reg1[DATA];
    int *num2 = (int*) reg2[DATA];
    return *num1 - *num2;
}
void imprimenum(ofstream &file, void **data) {
    file << *(int*)data[DATA] << endl;
}