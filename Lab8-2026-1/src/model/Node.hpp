//
// Created by jolumarti on 2026-11-11.
//

#ifndef LAB8_2026_1_NODOLISTADOBLE_HPP
#define LAB8_2026_1_NODOLISTADOBLE_HPP
#include "Par.hpp"


class Node {
    Par data;
    Node *next;
    Node *prev;
public:
    Node();
    Node(int key, Atencion *valor);
    ~Node() = default;
    void print(ofstream & file) const;
    bool compare(Node *other) const;
    bool cmp_priority(int priority) const;
    friend class List;
};


#endif //LAB8_2026_1_NODOLISTADOBLE_HPP
