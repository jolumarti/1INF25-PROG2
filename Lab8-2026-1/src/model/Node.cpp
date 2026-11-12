//
// Created by jolumarti on 2026-11-11.
//

#include "Node.hpp"

Node::Node() {
    next = nullptr;
    prev = nullptr;
}

Node::Node(int key, Atencion *valor): Node() {
    data.key = key;
    data.value = valor;
}

void Node::print(ofstream & file)const {
    data.value -> imprimir(file);
}

bool Node::compare(Node *other) const {
    return data.key < other->data.key;
}

bool Node::cmp_priority(int priority) const {
    return data.value->obtenerPrioridad() == priority;
}
