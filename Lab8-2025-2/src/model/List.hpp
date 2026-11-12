//
// Created by jolumarti on 2026-11-10.
//

#ifndef LAB8_2025_2_LISTA_HPP
#define LAB8_2025_2_LISTA_HPP
#include "Node.hpp"


class List {
private:
    Node *lista;
public:
    List() = default;
    void crear();
    void insertar(Metrica * metrica );
    void eliminarNodos();
    void reset();
    void print(ofstream &file) const;
    void print_headers(ofstream &file, MetricaType type) const;
};


#endif //LAB8_2025_2_LISTA_HPP
