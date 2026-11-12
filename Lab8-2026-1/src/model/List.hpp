//
// Created by jolumarti on 2026-11-11.
//

#ifndef LAB8_2026_1_LISTADOBLE_HPP
#define LAB8_2026_1_LISTADOBLE_HPP
#include "Node.hpp"


class List {
    Node *head;
    void insertRecursive(Node *&cur, Node *prev, Node *node);
    void printRecursive(const Node *cur, ofstream &file, int priority) const;

public:
    List();
    ~List();
    void insert(int llave, Atencion *valor);


    void print(ofstream & file, int priority) const;


    void destroy();
};


#endif //LAB8_2026_1_LISTADOBLE_HPP
