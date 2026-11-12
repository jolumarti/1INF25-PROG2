//
// Created by jolumarti on 2026-11-10.
//

#ifndef LAB8_2025_2_NODO_HPP
#define LAB8_2025_2_NODO_HPP
#include "Metrica.hpp"

class Node {
private:
    Metrica *metrica;
    Node *next;
    Node *prev;
public:
    Node();
    Node(Metrica *metrica);
    ~Node();

    friend class List;
};


#endif //LAB8_2025_2_NODO_HPP
